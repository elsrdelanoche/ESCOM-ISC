#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int idx;
    char input, outTop;
    string inTop;
    Edge(char _input, char _outTop, string _inTop, int _idx) {
        input = _input;
        outTop = _outTop;
        inTop = _inTop;
        _idx = idx;
    }
    bool operator<(const Edge& e1) const { return idx < e1.idx; }
};
struct Node {
    int acc = 0;
    vector<pair<Edge, int>> edges;
};
struct StackAutomata {
    vector<Node> Nodes;
    StackAutomata(int n) {
        Nodes.resize(n);
    }
    void addEdge(int u, int v, char input, char outTop, string inTop) {
        Edge e = Edge(input, outTop, (inTop == "$" ? "" : inTop), Nodes[u].edges.size()+1);
        Nodes[u].edges.push_back({ e,v });
    }
    void addAcc(int u) {
        Nodes[u].acc = 1;
    }
    bool isOn(string pattern, int i, int u, string stack1) {
        if (i == pattern.size()) {
            if (Nodes[u].acc) return true;
            else return false;
        }
        if (stack1.empty()) return false;
        bool res = false;
        for (auto adj : Nodes[u].edges) {
            if (adj.first.input == pattern[i]) {
                if (adj.first.outTop == stack1.back()) {
                    string cStack = stack1;
                    cStack.pop_back();
                    cStack = cStack + adj.first.inTop;
                    res |= isOn(pattern, i + 1, adj.second, cStack);
                }
            }
            if (adj.first.input == '$') res |= isOn(pattern, i, adj.second, stack1);
        }
        return res;
    }
    void printAutomata() {
        cout << "Automata:" << endl;
        for (int i = 0; i < Nodes.size(); i++) {
            cout << "Nodo " << i << ":" << endl;
            cout << "Estado aceptación: " << (Nodes[i].acc ? "Yes" : "No") << endl;
            cout << "Transición: " << endl;
            for (auto adj : Nodes[i].edges) {
                Edge e = adj.first;
                int v = adj.second;
                cout << "Input: " << e.input << ", OutTop: " << e.outTop << ", InTop: " << (e.inTop == "" ? "$" : e.inTop)<< ", Siguiente estado " << v << endl;
            }
            cout << endl;
        }
    }

    void generateDotFile() {
        ofstream dotFile("automataPila.dot");
        if (!dotFile.is_open()) {
            cout << "Error al abrir el archivo DOT." << endl;
            return;
        }

        dotFile << "digraph StackAutomaton {" << endl;
        // Nodo inicial
        dotFile << "\tstart [shape=none, label=\"\",height=0.08, width=0.08];" << endl;
        dotFile << "\tstart -> 0;" << endl;

        for (int i = 0; i < Nodes.size(); i++) {
            string shape = (Nodes[i].acc == 1) ? "doublecircle" : "circle";
            dotFile << "\t"  << i << " [shape=" << shape << "];" << endl;
        }

        for (int u = 0; u < Nodes.size(); u++) {
            set<int> visited;
            for (auto adj : Nodes[u].edges) {
                int v = adj.second;
                Edge e = adj.first;
                dotFile << "\t" << u << " -> " << v << " [label=\"" << e.input << "," << e.outTop << "/" <<(e.inTop == "" ? "$" : e.inTop)<<";  \"];" << "\n" <<endl;
            }
        }

        dotFile << "}" << endl;
        dotFile.close();

        cout << "Visualización grafica lista." << endl;
    }
};


int main() {
    freopen("input3.txt", "r", stdin);
    int n, edges;
    cin >> n >> edges;
    StackAutomata sa = StackAutomata(n);
    string stack1 = "!";

    for (int i = 0; i < edges; i++) {
        int u, v;
        char outTop, input;
        string inTop;
        cin >> u >> v >> input >> outTop >> inTop;
        sa.addEdge(u, v, input, outTop, inTop);
    }
    for (int i = 0; i < n; i++) {
        int acc;
        cin >> acc;
        if (acc){
            sa.addAcc(i);
        }
    }
    string s;
    cin >> s;
    s = s + '!';

    sa.printAutomata();

    cout << "Cadena: " << s << endl;
    bool isOn = sa.isOn(s, 0, 0, stack1);
    cout << "La cadena es aceptada? " << (isOn ? "Sí" : "No") << endl;

    sa.generateDotFile();
    // Llamar al comando dot para generar la imagen del grafo
    system("dot -Tpng -o AutomataPila.png automataPila.dot");
    return 0;
}
