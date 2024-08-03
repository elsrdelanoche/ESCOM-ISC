#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int examen(const unsigned char trama[]) {

    unsigned short int Tot = (trama[12] << 8) | trama[13];
    
    if (Tot <= 1500) {
        // Trama LLC
        if (!(trama[16] & 1)) {
            // Trama LLC tipo I
            printf("N(S): %d \nN(R): %d\n", (trama[16] & 0xFE) >> 1, (trama[17] & 0xFE) >> 1);
            return 1;
        }
        if ((trama[16] & 1) && !(trama[16] & 2)) {
            // Trama S
            if (((trama[16] & 0x0c) >> 2) == 2) {
                printf("N(S): %d\n", (trama[17] & 254) >> 1);
            }
        }
        return 0;
    }
    
    if (Tot == 2048) {
        // Trama IP
        unsigned short int Total_Length = (trama[16] << 8) | trama[17];
        if (trama[23] == 6) {
            // Trama TCP
            if (trama[47] & 0x20) {
                // TCP Urg
                printf("Secuencia: 0x%x%x%x%x\n", trama[38], trama[39], trama[40], trama[41]);
                return 1;
            }
            return 0;
        }
        
        // Trama ICMP
        if (trama[23] == 1) {
            if (Total_Length == 0x0030) {
                // IP-ICMP sin opciones
                return 0;
            }
            unsigned short int Counter = 0;
            printf("Opciones: \n");
            do {
                printf("0x%.2x%.2x%.2x%.2x \n", trama[34 + (Counter * 4)], trama[35 + (Counter * 4)], trama[36 + (Counter * 4)], trama[37 + (Counter * 4)]);
                Counter += 1;
            } while ((trama[34 + (Counter * 4)] | trama[35 + (Counter * 4)] | trama[36 + (Counter * 4)] | trama[37 + (Counter * 4)]) != 0);
            return 1;
        }
        
        if (trama[23] == 17) {
            if (Total_Length > 0x0030) {
                // UDP IP con opciones
                printf("Offset: 0x%.4x\n", ((trama[20] & 0x1f) << 8) | trama[21]);
                return 1;
            }
            return 0;
        }
    }
    
    if (Tot == 2054) {
        // Trama ARP
        if (trama[21] == 2) {
            // Trama ARP Respuesta
            printf("Mac destino: %.2x:%.2x:%.2x:%.2x:%.2x:%.2x\n", trama[32], trama[33], trama[34], trama[35], trama[36], trama[37]);
            return 1;
        }
        return 0;
    }
    //declaración de retorno por defecto
    return 0;
}

int main() {
    std::ifstream archivo("TramasEXA2modificado.txt");
    if (!archivo) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::vector<std::vector<unsigned char>> tramas;
    std::string linea;
    bool tramaIniciada = false;
    std::vector<unsigned char> tramaActual;

    while (std::getline(archivo, linea)) {
        size_t pos = 0;
        for (char c : linea) {
            if (c == '{') {
                tramaIniciada = true;
                tramaActual.clear();
            } else if (c == '}') {
                if (tramaIniciada) {
                    tramaIniciada = false;
                    tramas.push_back(tramaActual);
                }
            } else if (tramaIniciada) {
                std::string byteStr = linea.substr(pos, 2);
                unsigned char byte = static_cast<unsigned char>(std::stoi(byteStr, nullptr, 16));
                tramaActual.push_back(byte);
            }
        }
    }

    // Diagnosticar cada trama
    for (const auto& trama : tramas) {
        examen(trama.data());
    }
    return 0;
}
