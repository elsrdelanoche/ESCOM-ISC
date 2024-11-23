#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <stack>
using namespace std;

// Direcciones posibles para moverse: arriba, abajo, izquierda, derecha
const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Node {
    int x, y, distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Verifica si una posición es válida en el laberinto
bool isValid(int x, int y, const vector<vector<int>>& maze) {
    return x >= 0 && y >= 0 && x < maze.size() && y < maze[0].size() && maze[x][y] == 0;
}

// Imprime el camino desde inicio hasta el final
void printPath(const vector<vector<pair<int, int>>>& prev, int endX, int endY) {
    stack<pair<int, int>> path;
    int x = endX, y = endY;

    while (x != -1 && y != -1) {
        path.push({x, y});
        auto prevNode = prev[x][y];
        x = prevNode.first;
        y = prevNode.second;
    }

    cout << "Ruta más corta:\n";
    while (!path.empty()) {
        auto [px, py] = path.top();
        path.pop();
        cout << "(" << px << ", " << py << ")";
        if (!path.empty()) cout << " -> ";
    }
    cout << endl;
}

// Encuentra la ruta más corta en el laberinto usando Dijkstra
void dijkstra(const vector<vector<int>>& maze, int startX, int startY, int endX, int endY) {
    int rows = maze.size();
    int cols = maze[0].size();

    vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));
    vector<vector<pair<int, int>>> prev(rows, vector<pair<int, int>>(cols, {-1, -1}));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    distances[startX][startY] = 0;
    pq.push({startX, startY, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.x == endX && current.y == endY) {
            printPath(prev, endX, endY);
            return;
        }

        for (const auto& dir : DIRECTIONS) {
            int newX = current.x + dir.first;
            int newY = current.y + dir.second;

            if (isValid(newX, newY, maze)) {
                int newDist = current.distance + 1; // Cada paso tiene costo 1

                if (newDist < distances[newX][newY]) {
                    distances[newX][newY] = newDist;
                    prev[newX][newY] = {current.x, current.y};
                    pq.push({newX, newY, newDist});
                }
            }
        }
    }

    cout << "No hay ruta posible entre (" << startX << ", " << startY << ") y ("
         << endX << ", " << endY << ").\n";
}

int main() {
    vector<vector<int>> maze = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
        {1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0}
    };

    int startX, startY, endX, endY;
    cout << "Introduce las coordenadas de inicio (x y): ";
    cin >> startX >> startY;
    cout << "Introduce las coordenadas de destino (x y): ";
    cin >> endX >> endY;

    if (!isValid(startX, startY, maze) || !isValid(endX, endY, maze)) {
        cout << "Coordenadas inválidas.\n";
        return 0;
    }

    dijkstra(maze, startX, startY, endX, endY);

    return 0;
}
