#include <SFML/Graphics.hpp>
#include <iostream>

// Definimos las dimensiones de la matriz
const int filas = 8;
const int columnas = 15;

// La matriz proporcionada
int matriz[filas][columnas] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}
};

// Tamaño de cada celda en píxeles
const int tamanoCelda = 40;

// Función para colorear la celda seleccionada
void colorearCelda(int x, int y) {
    // Verificar si las coordenadas están dentro de la matriz
    if (x >= 0 && x < columnas && y >= 0 && y < filas) {
        // Solo cambiar a verde si la celda es blanca (0)
        if (matriz[y][x] == 0) {
            matriz[y][x] = 2;  // Usamos '2' para marcarla como verde
            std::cout << "Celda (" << x << ", " << y << ") coloreada de verde.\n";
        } else {
            std::cout << "La celda no es blanca. No se puede colorear.\n";
        }
    } else {
        std::cout << "Coordenadas fuera de rango.\n";
    }
}

int main() {
    // Calculamos las dimensiones de la ventana
    int anchoVentana = columnas * tamanoCelda;
    int altoVentana = filas * tamanoCelda;

    // Creamos la ventana SFML
    sf::RenderWindow ventana(sf::VideoMode(anchoVentana, altoVentana), "Matriz de cuadros");

    // Bucle principal de la aplicación
    while (ventana.isOpen()) {
        // Procesamos eventos
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();
        }

        // Limpiamos la ventana con un color blanco
        ventana.clear(sf::Color::White);

        // Dibujamos la matriz
        for (int i = 0; i < filas; ++i) {
            for (int j = 0; j < columnas; ++j) {
                // Creamos un rectángulo para cada celda
                sf::RectangleShape celda(sf::Vector2f(tamanoCelda, tamanoCelda));
                celda.setPosition(j * tamanoCelda, i * tamanoCelda);

                // Asignamos color según el valor de la matriz
                if (matriz[i][j] == 1) {
                    celda.setFillColor(sf::Color::Black);
                } else if (matriz[i][j] == 2) {
                    celda.setFillColor(sf::Color::Green);
                } else {
                    celda.setFillColor(sf::Color::White);
                }

                // Dibujamos la celda en la ventana
                ventana.draw(celda);
            }
        }

        // Mostramos la ventana
        ventana.display();

        // Pedimos coordenadas al usuario
        std::cout << "Ingrese las coordenadas (x y) para colorear o -1 -1 para salir: ";
        int x, y;
        std::cin >> x >> y;

        if (x == -1 && y == -1) {
            std::cout << "Saliendo...\n";
            ventana.close();
        } else {
            colorearCelda(x, y);
        }
    }

    return 0;
}
