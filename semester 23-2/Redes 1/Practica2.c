#include <stdio.h>

//Calulo de checksum
unsigned short calcular_checksum(unsigned char *trama) {
    unsigned int suma = 0; // Variable para almacenar la suma de los valores de los bytes de la trama
    unsigned short checksum;// Variable para almacenar el checksum final
    
    // Recorre la trama de 20 bytes en bloques de 2 bytes
    for(int i = 0; i < 20; i += 2) {
        suma += (trama[i] << 8) | trama[i+1]; // Suma los valores de los dos bytes actuales (con desplazamiento)
    }
    
     // Si la suma es mayor a 16 bits, se ajusta para que quepa en 16 bits
    while(suma >> 16) {
        suma = (suma & 0xFFFF) + (suma >> 16);
    }
    
    // Se calcula el complemento a uno de la suma
    checksum = (unsigned short) ~suma;
    
    return checksum;
}

int main() {
    // Prueba 1
    unsigned char T1[] = {0x45, 0x00, 0x01, 0xe2, 0xd7, 0xdb, 0x40, 0x00, 0x80, 0x06, 0x00, 0x00, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    unsigned short checksum_calculado = calcular_checksum(T1);
    
    printf("Prueba 1\n");
    printf("Trama: ");
    for(int i = 0; i < 20; i++) {
        printf("%02x ", T1[i]); // Imprime cada byte de la trama en hexadecimal
    }
    printf("\nChecksum: %04x\n\n", checksum_calculado); // Imprime el checksum calculado en hexadecimal
    
    // Prueba 2
    unsigned char T2[] = {0x45, 0x00, 0x01, 0x9c, 0xd7, 0xde, 0x40, 0x00, 0x80, 0x06, 0x88, 0x9d, 0xc0, 0xa8, 0x01, 0x43, 0x94, 0xcc, 0x3a, 0xdd};
    checksum_calculado = calcular_checksum(T2);
    unsigned short checksum_trama = (T2[10] << 8) | T2[11]; // Combina los bytes 10 y 11 de la trama para obtener el checksum recibido

    printf("Prueba 2\n");
    printf("Trama: ");
    for(int i = 0; i < 20; i++) {
        printf("%02x ", T2[i]); // Imprime cada byte de la trama en hexadecimal
    }
    if(checksum_calculado == checksum_trama) { // Compara el checksum calculado con el recibido
        printf("\nLa trama es correcta. Checksum: %02x %02x\n", (unsigned char)(checksum_calculado >> 8), (unsigned char)checksum_calculado);
    } else {
        printf("\nLa trama tiene un error. Checksum calculado: %02x%02x, Checksum en trama: %02x%02x\n", (unsigned char)(checksum_calculado >> 8), (unsigned char)checksum_calculado, T2[10], T2[11]);
        printf("Checksum que debia haber sido: %02x%02x\n", (unsigned char)(~checksum_calculado >> 8), (unsigned char)~checksum_calculado);
    }
    
    return 0;
}