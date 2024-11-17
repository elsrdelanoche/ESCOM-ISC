#include <iostream>
#include <string>

using namespace std;

int main() {
    int opcion;
    string cadena, cadena2;
    int inicio, fin, potencia;

    do {
        // Menú de opciones
        cout << "Menu de cadenas\n";
        cout << "1.- Concatenar cadenas\n";
        cout << "2.- Obtener prefijo\n";
        cout << "3.- Obtener sufijo\n";
        cout << "4.- Obtener subcadena\n";
        cout << "5.- Obtener subsecuencia\n";
        cout << "6.- Invertir cadena\n";
        cout << "7.- Potencia de cadena\n";
        cout << "8.- Salir\n";
        cout << "Elige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Concatenar cadenas
                cout << "Ingrese la primera cadena: ";
                cin >> cadena;
                cout << "Ingrese la segunda cadena: ";
                cin >> cadena2;
                cout << "La cadena concatenada es: ";
                for (char c : cadena) cout << c;
                for (char c : cadena2) cout << c;
                cout << endl<<endl;
                break;
            case 2: // Obtener prefijo
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el tamaño del prefijo: ";
                cin >> fin;
                for (int i = 0; i < fin; i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 3: // Obtener sufijo
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el tamaño del sufijo: ";
                cin >> inicio;
                for (int i = inicio; i < cadena.length(); i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 4: // Obtener subcadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el índice inicial: ";
                cin >> inicio;
                cout << "Ingrese el índice final: ";
                cin >> fin;
                for (int i = inicio; i <= fin; i++) {
                    cout << cadena[i];
                }
                cout << endl;
                break;

            case 5:{ // Obtener subsecuencia (considerando subcadena de longitud máxima)
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese la subcadena a buscar: ";
                cin >> cadena2;
                bool encontrada = false;
                for (int i = 0; i <= cadena.length() - cadena2.length(); i++) {
                    int j;
                    for (j = 0; j < cadena2.length(); j++) {
                        if (cadena[i + j] != cadena2[j]) {
                            break;
                        }
                        
                    }
                    if (j == cadena2.length()) {
                        encontrada = true;
                        cout << "subsecuencia encontrada en el índice " << i << endl;
                        break;
                    }
                }
                if (!encontrada) {
                    cout << "subsecuencia no encontrada." << endl;
                }
                break;
            }
            case 6: // Invertir cadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "La cadena invertida es: ";
                for (int i = cadena.length() - 1; i >= 0; i--) {
                    cout << cadena[i];
                }
                cout << endl;
                break;
            case 7: // Potencia de cadena
                cout << "Ingrese la cadena: ";
                cin >> cadena;
                cout << "Ingrese el exponente: ";
                cin >> potencia;
                cout << "La cadena elevada a la " << potencia << " es: ";
                for (int i = 0; i < potencia; i++) {
                    for (char c : cadena) cout << c;
                }
                cout << endl;
                break;
            case 8:
                cout << "Saliendo del programa..." << endl<<"Tenga buen día";
                break;
            default:
                cout << "Opción inválida." << endl;
        }
    } while (opcion != 8);

    return 0;
}