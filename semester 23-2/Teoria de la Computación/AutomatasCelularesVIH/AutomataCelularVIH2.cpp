#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

const int N = 50; // Tamaño de la cuadrícula
const int I = 5; // Número inicial de células infectadas
int T = 3; // Tiempo de vida de una célula infectada

enum Celula { Sano, Infectado, Muerto };

Celula cuadricula[N][N]; // Cuadrícula de células

// Inicializar la cuadrícula
void inicializar() {
    // Todas las células se inicializan como sanas
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cuadricula[i][j] = Sano;
        }
    }

    // Se seleccionan aleatoriamente I células para infectar
    srand(time(NULL));
    for (int i = 0; i < I; i++) {
        int x = rand() % N;
        int y = rand() % N;
        cuadricula[x][y] = Infectado;
    }
}

// Mostrar la cuadrícula en la pantalla
void mostrar() {
    //system("cls"); // Limpiar la pantalla
    std::cout << "\033c";

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (cuadricula[i][j]) {
                case Sano:
                    cout << "\033[32mS "; // Color verde
                    break;
                case Infectado:
                    cout << "\033[31mI "; // Color rojo
                    break;
                case Muerto:
                    cout << "\033[30mM "; // Color gris
                    break;
            }
        }
        cout << endl;
    }
}

// Actualizar la cuadrícula
void actualizar() {
    Celula nueva_cuadricula[N][N]; // Nueva cuadrícula para almacenar el siguiente estado de las células

    // Aplicar la regla a cada célula
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            switch (cuadricula[i][j]) {
                case Sano:
                    // Una célula infectada adyacente infectará a esta célula
                    if ((i > 0 && cuadricula[i-1][j] == Infectado) ||
                        (i < N-1 && cuadricula[i+1][j] == Infectado) ||
                        (j > 0 && cuadricula[i][j-1] == Infectado) ||
                        (j < N-1 && cuadricula[i][j+1] == Infectado)) {
                        nueva_cuadricula[i][j] = Infectado;
                        }
                    else {
                    nueva_cuadricula[i][j] = Sano;
                    }
                    break;
                case Infectado:
                    // Una célula infectada morirá después de T iteraciones
                    if (T == 0) {
                    nueva_cuadricula[i][j] = Muerto;
                    }
                    else {
                        nueva_cuadricula[i][j] = Infectado;
                        T--;
                    }
                    break;
                case Muerto:
                nueva_cuadricula[i][j] = Muerto;
                break;
                }
        }
    }
    // Actualizar la cuadrícula original con la nueva cuadrícula
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cuadricula[i][j] = nueva_cuadricula[i][j];
        }
    }
    sleep(1);
}

int main() {
inicializar(); // Inicializar la cuadrícula
mostrar(); // Mostrar la cuadrícula inicial
// Actualizar la cuadrícula en cada iteración hasta que no haya más células infectadas
while (true) {
    actualizar();
    mostrar();
    int contagiados = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (cuadricula[i][j] == Infectado) {
                contagiados++;
            }
        }
    }
    if (contagiados == 0) {
        break;
    }
}

return 0;
}