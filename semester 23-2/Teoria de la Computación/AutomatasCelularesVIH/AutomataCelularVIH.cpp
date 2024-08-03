#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Celula {
public:
    enum Estado {SANA, INFECTADA, MUERTA};
    Estado estado;

    Celula() {
        estado = static_cast<Estado>(rand() % 2);
    }
};

class AutomataCelular {
private:
    static const int N = 20;
    static const int M = 20;
    Celula matriz[N][M];

public:
    AutomataCelular() {
        // Inicializar la semilla para generar números aleatorios
        srand(time(nullptr));

        // Inicializar matriz de células con estados aleatorios
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                matriz[i][j] = Celula();
            }
        }
    }

    void actualizar() {
        // Actualizar estados de las células según reglas de transición
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                int numInfectadas = 0;

                // Contar células infectadas en el vecindario de la célula actual
                for (int k = i - 1; k <= i + 1; k++) {
                    for (int l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < N && l >= 0 && l < M && !(k == i && l == j) && matriz[k][l].estado == Celula::INFECTADA) {
                            numInfectadas++;
                        }
                    }
                }

                if (matriz[i][j].estado == Celula::INFECTADA) {
                    // Si la célula está infectada:
                    if (numInfectadas >= 3) {
                        // Muere si tiene 3 o más células infectadas en el vecindario
                        matriz[i][j].estado = Celula::MUERTA;
                    }
                } else if (matriz[i][j].estado == Celula::SANA) {
                    // Si la célula está sana:
                    if (numInfectadas >= 2) {
                        // Se infecta si tiene 2 o más células infectadas en el vecindario
                        matriz[i][j].estado = Celula::INFECTADA;
                    }
                }
            }
        }
    }

    void imprimir() {
        // Imprimir matriz de células en la consola
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                switch (matriz[i][j].estado) {
                    case Celula::SANA:
                        cout << ".";
                        break;
                    case Celula::INFECTADA:
                        cout << "X";
                        break;
                    case Celula::MUERTA:
                        cout << "-";
                        break;
                }
            }
            cout << endl;
        }
    }
};

int main() {
    AutomataCelular ac;

    // Actualizar y mostrar el autómata celular en cada iteración
    for (int i = 0; i < 10; i++) {
        ac.actualizar();
        ac.imprimir();
        cout << endl;
    }

    return 0;
}
