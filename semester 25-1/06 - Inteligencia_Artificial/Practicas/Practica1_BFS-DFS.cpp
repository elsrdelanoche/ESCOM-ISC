#include <bits/stdc++.h>
#include <chrono>
#include <sys/resource.h>  // Para medir el uso de memoria.

using namespace std::chrono;
using namespace std;

const int N = 1e5;   // Tamaño máximo permitido para el número de nodos.
vector<int>* g;      // Puntero a un array de vectores que representará el grafo.
int vis[N];          // Array para llevar un registro de los nodos visitados.
bool encontrado;     // Variable de control para saber si el nodo fue encontrado.

// Función para obtener el uso de memoria en kilobytes.
long getMemoryUsage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;  // Retorna el máximo tamaño de memoria residente.
}

void dfs(int u, int x) {
    if (encontrado) return;  // Si el nodo ya fue encontrado, detén la búsqueda.
    
    cout << u << " ";  // Imprime el nodo actual.
    if (u == x) {
        cout << "Me encontraste" << "\n";  // Si se encuentra el nodo buscado, imprime un mensaje.
        encontrado = true;  // Marca como encontrado.
        return;  // Detiene la búsqueda.
    } else {
        cout << "\n";
    }
    vis[u] = 1;  // Marca el nodo como visitado.
    for (auto it : g[u])  // Recorre los vecinos del nodo actual.
        if (!vis[it])  // Si un vecino no ha sido visitado, llama recursivamente a DFS.
            dfs(it, x);
}

void bfs(int u, int x) {
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        cout << v << " ";  // Imprime el nodo actual.
        if (v == x) {
            cout << "Me encontraste" << "\n";  // Si encuentra el nodo buscado, imprime el mensaje.
            return;  // Detén la búsqueda.
        } else {
            cout << "\n";
        }
        for (auto it : g[v]) {  // Recorre los vecinos del nodo actual.
            if (!vis[it]) {
                q.push(it);
                vis[it] = 1;  // Marca los vecinos como visitados y los añade a la cola.
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;  // Lee el número de nodos y aristas del grafo.
    g = new vector<int>[n + 1];  // Inicializa la lista de adyacencia.

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;  // Lee las aristas.
        g[a].push_back(b);  // Agrega la conexión en ambas direcciones (grafo no dirigido).
        g[b].push_back(a);
    }

    srand(time(0));  // Inicializa el generador de números aleatorios.

    // DFS
    cout << "DFS" << "\n";
    for (int i = 0; i <= n; i++) vis[i] = 0;  // Reinicia el array de nodos visitados.
    int numeroRaiz = 1;  // Establece 1 como raíz.
    int numeroAleatorioEncontrar = rand() % n + 1;  // Elige un nodo aleatorio a buscar.
    cout << numeroAleatorioEncontrar << " " << numeroRaiz << endl;

    encontrado = false;  // Resetea la variable de control.
    auto start = high_resolution_clock::now();  // Captura el tiempo inicial.
    long memoriaInicialDFS = getMemoryUsage();  // Obtén la memoria inicial.
    dfs(numeroRaiz, numeroAleatorioEncontrar);  // Llama a la DFS.
    auto end = high_resolution_clock::now();  // Captura el tiempo final.
    long memoriaFinalDFS = getMemoryUsage();  // Obtén la memoria final.
    auto duration = duration_cast<microseconds>(end - start);  // Calcula la duración.
    cout << duration.count() << "ms\n";  // Imprime el tiempo de ejecución.
    cout << "Memoria utilizada (DFS): " << (memoriaFinalDFS - memoriaInicialDFS) * 1024 << " B\n";  // Imprime la memoria utilizada en bytes.

    // BFS
    cout << "BFS" << "\n";
    for (int i = 0; i <= n; i++) vis[i] = 0;  // Reinicia el array de nodos visitados.
    start = high_resolution_clock::now();  // Captura el tiempo inicial.
    long memoriaInicialBFS = getMemoryUsage();  // Obtén la memoria inicial.
    bfs(numeroRaiz, numeroAleatorioEncontrar);  // Llama a la BFS.
    end = high_resolution_clock::now();  // Captura el tiempo final.
    long memoriaFinalBFS = getMemoryUsage();  // Obtén la memoria final.
    duration = duration_cast<microseconds>(end - start);  // Calcula la duración.
    cout << duration.count() << "ms\n";  // Imprime el tiempo de ejecución.
    cout << "Memoria utilizada (BFS): " << (memoriaFinalBFS - memoriaInicialBFS) * 1024 << " B\n";  // Imprime la memoria utilizada en bytes.

    return 0;  // Indica que el programa terminó correctamente.
}
