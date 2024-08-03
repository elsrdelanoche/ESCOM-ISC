#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <random>

// Dimensiones de la rejilla celular
const int N = 1000;
const int M = 1000;

// Clase para representar la célula en la rejilla
class Cell {
public:
    Cell() : infected(false), viralLoad(0) {};
    bool infected;  // Indica si la célula está infectada con VIH
    int viralLoad;  // Carga viral en la célula
};

// Función para actualizar el estado de la célula según las reglas de transición
void updateCell(Cell& cell) {
    // Si la célula está infectada, la carga viral aumenta
    if (cell.infected) {
        cell.viralLoad += 1;
    }
}

int main() {
    // Generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1.0);

    // Crear la ventana de SFML
    sf::RenderWindow window(sf::VideoMode(N, M), "VIH");

    // Matriz de células
    std::vector<std::vector<Cell>> grid(N, std::vector<Cell>(M));

    // Generar condiciones iniciales aleatorias
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (dis(gen) < 0.1) {
                grid[i][j].infected = true;
                grid[i][j].viralLoad = 100;
            }
        }
    }

    // Bucle principal de simulación
    while (window.isOpen()) {
        // Gestionar eventos de SFML
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Actualizar el estado de las células
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                updateCell(grid[i][j]);
            }
        }

        // Dibujar la matriz de células en la ventana de SFML
        window.clear();
        sf::RectangleShape cell(sf::Vector2f(1, 1));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (grid[i][j].infected) {
                    cell.setFillColor(sf::Color::Red);
                } else {
                    cell.setFillColor(sf::Color::White);
                }
                cell.setPosition(i, j);
                window.draw(cell);
            }
        }
        window.display();
    }

    return 0;
}
