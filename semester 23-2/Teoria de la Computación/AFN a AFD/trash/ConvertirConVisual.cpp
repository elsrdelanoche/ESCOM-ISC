#include <bits/stdc++.h>
using namespace std;

// Primera línea del txt representa el número de nodos
// Las siguientes N líneas deben tener el siguiente formato:
// el número de transiciones para 0 y los nodos, lo mismo para 1
map<int, vector<set<int>>> adj;
map<set<int>, int> colors;
queue<set<int>> processing;
map<set<int>, int> processed;
int color;
map<int, int> acceptedAFN;
map<int, int> acceptedAFD;
vector<int> *g;

void transformAFNtoADF(int node)
{
    set<int> init;
    init.insert(node);
    processed[init] = 1;
    colors[init] = ++color;
    processing.push(init);
    while (!processing.empty())
    {
        set<int> trans = processing.front();
        processing.pop();
        set<int> transWith0;
        set<int> transWith1;
        for (auto tran : trans)
        {
            transWith0.insert(adj[tran][0].begin(), adj[tran][0].end());
            transWith1.insert(adj[tran][1].begin(), adj[tran][1].end());
            if (acceptedAFN[tran])
                acceptedAFD[tran] = 1;
        }
        if (colors[transWith0] == 0)
        {
            color++;
            colors[transWith0] = color;
        }
        if (colors[transWith1] == 0)
        {
            color++;
            colors[transWith1] = color;
        }
        g[colors[trans]] = {colors[transWith0], colors[transWith1]};
        if (processed[transWith0] == 0)
        {
            processed[transWith0] = 1;
            processing.push(transWith0);
        }
        if (processed[transWith1] == 0)
        {
            processed[transWith1] = 1;
            processing.push(transWith1);
        }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            int m;
            cin >> m;
            set<int> aux;
            for (int k = 0; k < m; k++)
            {
                int num;
                cin >> num;
                aux.insert(num);
            }
            adj[i].push_back(aux);
        }
    }

    g = new vector<int>[n + 1000];
    transformAFNtoADF(1);

    // Generar archivo DOT para Graphviz
    ofstream dotFile("graph.dot");
    dotFile << "digraph Automaton {\n";
    for (int i = 1; i <= color; i++)
    {
        if (g[i].size() > 0)
        {
            dotFile << "\t" << i << " [shape=doublecircle];\n";
            for (int j : g[i])
            {
                dotFile << "\t" << i << " -> " << j << " [label=\"0\"];\n";
                dotFile << "\t" << i << " -> " << j << " [label=\"1\"];\n";
            }
        }
    }
    dotFile << "}";
    dotFile.close();

    // Llamar al comando dot para generar la imagen del grafo
    system("dot -Tpng -o graph.png graph.dot");

    delete[] g;
    return 0;
}
