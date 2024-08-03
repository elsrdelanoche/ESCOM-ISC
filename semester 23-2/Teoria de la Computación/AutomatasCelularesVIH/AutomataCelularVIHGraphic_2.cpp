#include <SFML/Graphics.hpp>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace sf;

const int TAM_CELULA = 2; // Tamaño de cada célula en píxeles
const int FILAS = 500; // Número de filas en la matriz de células
const int COLUMNAS =500; // Número de columnas en la matriz de células
const int ANCHO_VENTANA = COLUMNAS * TAM_CELULA; // Ancho de la ventana en píxeles
const int ALTO_VENTANA = FILAS * TAM_CELULA; // Alto de la ventana en píxeles

// Definición de la clase Celula
class Celula {
public:
    Celula() : estado(false) {}
    bool estado;
};

// Definición de la clase AutomataCelular
class AutomataCelular {
private:
    std::vector<std::vector<Celula>> celulas;
    int contarVecinosVivos(int fila, int columna) {
    // Contar el número de vecinos vivos de una célula
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int fila_vecino = (fila + i + FILAS) % FILAS;
            int columna_vecino = (columna + j + COLUMNAS) % COLUMNAS;
            if (!(i == 0 && j == 0) && celulas[fila_vecino][columna_vecino].estado) {
                count++;
            }
        }
    }
    return count;
    }
public:
    AutomataCelular() {
        std::srand(std::time(nullptr)); // Inicializar la semilla del generador de números aleatorios
        celulas.resize(FILAS, std::vector<Celula>(COLUMNAS)); // Inicializar la matriz de células
        // Inicializar la matriz de células con valores aleatorios
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                celulas[i][j].estado = (std::rand() % 2 == 0);
            }
        }
    }
    void actualizar() {
        // Implementar las reglas de actualización del autómata celular
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                int vecinos_vivos = contarVecinosVivos(i, j);
                if (celulas[i][j].estado) {
                    if (vecinos_vivos < 2 || vecinos_vivos > 3) {
                        celulas[i][j].estado = false;
                    }
                } else {
                    if (vecinos_vivos == 3) {
                        celulas[i][j].estado = true;
                    }
                }
            }
        }
    }
    void dibujar(RenderWindow& ventana) {
        // Dibujar la matriz de células en la ventana
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                RectangleShape celula(Vector2f(TAM_CELULA, TAM_CELULA));
                celula.setPosition(j * TAM_CELULA, i * TAM_CELULA);
                celula.setFillColor(celulas[i][j].estado ? Color::Green : Color::Black);
                ventana.draw(celula);
            }
        }
    }
};

int main() {
    // Crear la ventana de renderizado
    RenderWindow ventana(VideoMode(ANCHO_VENTANA, ALTO_VENTANA), "Simulación del VIH");
    // Crear el autómata celular
    AutomataCelular automata;

    // Bucle principal del programa
    while (ventana.isOpen()) {
        // Procesar eventos
        Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == Event::Closed) {
                ventana.close();
            }
        }

        // Actualizar el autómata celular
        automata.actualizar();

        // Dibujar la matriz de células en la ventana
        ventana.clear(Color::White);
        automata.dibujar(ventana);
        ventana.display();

        // Esperar un tiempo antes de actualizar la ventana
        sf::sleep(milliseconds(50));
    }

    return 0;
}