#include <SFML/Graphics.hpp>
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

    void dibujar(sf::RenderWindow& ventana) {
        // Crear rectángulos para cada célula y colorearlos según su estado
        const int lado = 20;
        sf::RectangleShape rectangulo(sf::Vector2f(lado, lado));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                switch (matriz[i][j].estado) {
                    case Celula::SANA:
                        rectangulo.setFillColor(sf::Color::Green);
                        break;
                    case Celula::INFECTADA:
                        rectangulo.setFillColor(sf::Color::Red);
                        break;
                    case Celula::MUERTA:
                        rectangulo.setFillColor(sf::Color::Black);
                        break;
                }
                
                            // Posicionar el rectángulo en la posición correspondiente
                rectangulo.setPosition(j * lado, i * lado);

                // Dibujar el rectángulo en la ventana
                ventana.draw(rectangulo);
            }
        }
    }
};

int main() {
    // Crear ventana de SFML
    sf::RenderWindow ventana(sf::VideoMode(400, 400), "Automata Celular");
    // Crear objeto de automata celular
    AutomataCelular automata;

    // Bucle principal del programa
    while (ventana.isOpen()) {
        // Procesar eventos de la ventana
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed) {
                ventana.close();
            }
        }

        // Actualizar el automata celular
        automata.actualizar();

        // Limpiar la ventana
        ventana.clear();

        // Dibujar el automata celular en la ventana
        automata.dibujar(ventana);

        // Mostrar la ventana
        ventana.display();
        while (ventana.isOpen()) {
            // Procesar eventos de la ventana
            sf::Event evento;
            while (ventana.pollEvent(evento)) {
                if (evento.type == sf::Event::Closed) {
                    ventana.close();
                }
            }

            // Actualizar el automata celular
            automata.actualizar();

            // Limpiar la ventana
            ventana.clear();

            // Dibujar el automata celular en la ventana
            automata.dibujar(ventana);

            // Mostrar la ventana
            ventana.display();

            // Pausar el programa durante 100 milisegundos
            sf::sleep(sf::milliseconds(100));
        }
    }
return 0;
}