#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include <SFML/Graphics.hpp>

using namespace std;

const int WINDOW_SIZE = 1000;
const int CELL_SIZE = 2;
const int GRID_SIZE = WINDOW_SIZE / CELL_SIZE;

int grid[GRID_SIZE][GRID_SIZE];

int countNeighbors(int x, int y) {
    int sum = 0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            int col = (x + i + GRID_SIZE) % GRID_SIZE;
            int row = (y + j + GRID_SIZE) % GRID_SIZE;
            sum += grid[row][col];
        }
    }
    sum -= grid[y][x];
    return sum;
}

void initializeGrid() {
    srand(time(NULL));
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = rand() % 2;
        }
    }
}

void updateGrid() {
    int newGrid[GRID_SIZE][GRID_SIZE];

    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            int neighbors = countNeighbors(j, i);
            if (grid[i][j] == 1) {
                if (neighbors < 2 || neighbors > 3) {
                    newGrid[i][j] = 0;
                } else {
                    newGrid[i][j] = 1;
                }
            } else {
                if (neighbors == 3) {
                    newGrid[i][j] = 1;
                } else {
                    newGrid[i][j] = 0;
                }
            }
        }
    }

    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            grid[i][j] = newGrid[i][j];
        }
    }
}

void drawGrid(sf::RenderWindow& window) {
    for (int i=0; i<GRID_SIZE; i++) {
        for (int j=0; j<GRID_SIZE; j++) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(j*CELL_SIZE, i*CELL_SIZE);
            if (grid[i][j] == 1) {
                cell.setFillColor(sf::Color::Green);
            } else {
                cell.setFillColor(sf::Color::Black);
            }
            window.draw(cell);
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Game of Life");

    initializeGrid();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        drawGrid(window);
        window.display();
        updateGrid();
        usleep(100000);
    }

    return 0;
}
