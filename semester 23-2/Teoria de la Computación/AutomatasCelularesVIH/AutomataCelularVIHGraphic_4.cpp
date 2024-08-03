#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SFML/Graphics.hpp>

using namespace std;

const int WIDTH = 800;
const int HEIGHT = 600;
const int CELL_SIZE = 5;
const int ROWS = HEIGHT / CELL_SIZE;
const int COLS = WIDTH / CELL_SIZE;
const int DELAY = 100;
const int INITIAL_INFECTED_CELLS = 10;

int grid[ROWS][COLS];

sf::Color colors[3] = { sf::Color::Blue, sf::Color::Green, sf::Color::Red };

void initGrid() {
    srand(time(NULL));
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = 0;
        }
    }

    for (int i = 0; i < INITIAL_INFECTED_CELLS; i++) {
        int row = rand() % ROWS;
        int col = rand() % COLS;
        grid[row][col] = 1;
    }
}

void updateGrid() {
    int newGrid[ROWS][COLS];

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int state = grid[row][col];
            int neighbors = 0;

            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int r = (row + i + ROWS) % ROWS;
                    int c = (col + j + COLS) % COLS;
                    neighbors += grid[r][c];
                }
            }

            neighbors -= state;

            if (state == 0 && neighbors == 3) {
                newGrid[row][col] = 1;
            } else if (state == 1 && (neighbors < 2 || neighbors > 3)) {
                newGrid[row][col] = 0;
            } else {
                newGrid[row][col] = state;
            }
        }
        
    }

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            grid[row][col] = newGrid[row][col];
        }
        sf::sleep(sf::milliseconds(500));
    }

}

void renderGrid(sf::RenderWindow& window) {
    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));

    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            int state = grid[row][col];
            cell.setPosition(col * CELL_SIZE, row * CELL_SIZE);
            cell.setFillColor(colors[state]);
            window.draw(cell);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Cellular Automaton");
    initGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);
        renderGrid(window);
        window.display();

        updateGrid();
        sf::sleep(sf::milliseconds(1000));
    }

    return 0;
}
