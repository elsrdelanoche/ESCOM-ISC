#include <bits/stdc++.h>
using namespace std;

map<int, vector<set<int>>> adj;
map<set<int>, int> colors;
queue<set<int>> processing;
map<set<int>, int> processed;
int color;
map<int, int> acceptedAFN;
map<int, int> acceptedAFD;
set<int>* g;

void transformAFNtoADF(int node) {
    set<int> init;
    init.insert(node);
    processed[init] = 1;
    colors[init] = ++color;
    processing.push(init);

    while (!processing.empty()) {
        set<int> trans = processing.front();
        processing.pop();
        set<int> transWith0;
        set<int> transWith1;

        for (auto tran : trans) {
            transWith0.insert(adj[tran][0].begin(), adj[tran][0].end());
            transWith1.insert(adj[tran][1].begin(), adj[tran][1].end());
            if (acceptedAFN[tran]) acceptedAFD[tran] = 1;
        }

        if (colors[transWith0] == 0) {
            color++;
            colors[transWith0] = color;
            processing.push(transWith0);
        }

        if (colors[transWith1] == 0) {
            color++;
            colors[transWith1] = color;
            processing.push(transWith1);
        }

        g[colors[trans]].insert(colors[transWith0]);
        g[colors[trans]].insert(colors[transWith1]);
    }
}

void generateGraphvizFile(int numNodes) {
    ofstream file("graph.dot");
    if (!file.is_open()) {
        cout << "Error: No se pudo abrir el archivo graph.dot" << endl;
        return;
    }

    file << "digraph AFD {" << endl;
    file << "\tstart [shape=point]" << endl;
    file << "\tstart -> 1" << endl;
    for (int i = 1; i <= color; i++) {
        file << "\t" << i << " [shape=circle";
        if (acceptedAFD[*g[i].begin()] || acceptedAFD[*(++g[i].begin())])
            file << ", peripheries=2";
        file << "]" << endl;
        for (auto neighbor : g[i]) {
            file << "\t" << i << " -> " << neighbor << " [label=\"";
            if (neighbor == *g[i].begin())
                file << "0";
            else
                file << "1";
            file << "\"]" << endl;
        }
    }
    file << "}" << endl;

    file.close();
}

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            int m;
            cin >> m;
            set<int> aux;

            for (int k = 0; k < m; k++) {
                int num;
                cin >> num;
                aux.insert(num);
            }

            adj[i].push_back(aux);
        }
    }

    g = new set<int>[n + 1000];
    transformAFNtoADF(1);

    generateGraphvizFile(color);

    // Llamar al comando dot para generar la imagen del grafo
    system("dot -Tpng -o graph.png graph.dot");

    delete[] g;

    return 0;
}
