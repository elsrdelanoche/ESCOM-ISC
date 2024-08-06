#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>

using namespace std;

// Estructura de hash personalizada para std::pair<int, char>
struct pair_hash {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2; // Combina los hashes
    }
};

class TuringMachine {
public:
    TuringMachine(vector<char> tape, int initialState, unordered_map<pair<int, char>, tuple<int, char, int>, pair_hash> transitionTable)
    : tape(tape), head(0), currentState(initialState), transitionTable(transitionTable) {}

    void execute() {
        cout << "Starting Turing Machine Execution..." << endl;
        printTape();
        while (true) {
            // Espera para la visualización
            this_thread::sleep_for(chrono::milliseconds(500));

            // Borra la línea de la terminal
            clearLine();

            if (transitionTable.find({currentState, tape[head]}) == transitionTable.end()) {
                cout << "\nFinal State Reached: " << currentState << endl;
                printTape();
                return;
            }

            auto [nextState, writeSymbol, moveDirection] = transitionTable[{currentState, tape[head]}];
            tape[head] = writeSymbol;
            currentState = nextState;
            head += moveDirection;

            printTape();
        }
    }

private:
    vector<char> tape;
    int head;
    int currentState;
    unordered_map<pair<int, char>, tuple<int, char, int>, pair_hash> transitionTable;

    void printTape() {
        cout << "| ";
        for (int i = 0; i < tape.size(); ++i) {
            if (i == head) {
                cout << '[' << tape[i] << "] ";
            } else {
                cout << ' ' << tape[i] << "  ";
            }
        }
        cout << '|' << endl;

        // Imprimir flechas de movimiento
        cout << "  ";
        for (int i = 0; i < tape.size(); ++i) {
            if (i == head) {
                cout << " ↑  ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }

    void clearLine() {
        // Mueve el cursor a la línea anterior y borra la línea
        cout << "\033[F\033[F\033[2K";
    }
};

unordered_map<pair<int, char>, tuple<int, char, int>, pair_hash> parseTransitionTable(istream& input) {
    unordered_map<pair<int, char>, tuple<int, char, int>, pair_hash> transitionTable;
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        int currentState, nextState, moveDirection;
        char readSymbol, writeSymbol;
        if (iss >> currentState >> readSymbol >> nextState >> writeSymbol >> moveDirection) {
            transitionTable[{currentState, readSymbol}] = {nextState, writeSymbol, moveDirection};
        }
    }
    return transitionTable;
}

vector<char> parseTape(const string& input) {
    return vector<char>(input.begin(), input.end());
}

int main() {
    cout << "Choose input method: \n1. Terminal\n2. File\n";
    int choice;
    cin >> choice;
    cin.ignore(); // Clear newline character from the input buffer

    vector<char> tape;
    unordered_map<pair<int, char>, tuple<int, char, int>, pair_hash> transitionTable;
    int initialState;

    if (choice == 1) {
        // Input from terminal
        cout << "Enter initial tape content: ";
        string tapeInput;
        getline(cin, tapeInput);
        tape = parseTape(tapeInput);

        cout << "Enter initial state: ";
        cin >> initialState;
        cin.ignore();

        cout << "Enter transition table (end with an empty line):\n";
        string line;
        while (getline(cin, line) && !line.empty()) {
            istringstream iss(line);
            int currentState, nextState, moveDirection;
            char readSymbol, writeSymbol;
            if (iss >> currentState >> readSymbol >> nextState >> writeSymbol >> moveDirection) {
                transitionTable[{currentState, readSymbol}] = {nextState, writeSymbol, moveDirection};
            }
        }
    } else if (choice == 2) {
        // Input from file
        cout << "Enter filename: ";
        string filename;
        cin >> filename;
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file." << endl;
            return 1;
        }

        string tapeInput;
        getline(file, tapeInput);
        tape = parseTape(tapeInput);

        file >> initialState;
        file.ignore();

        transitionTable = parseTransitionTable(file);
        file.close();
    } else {
        cerr << "Invalid choice." << endl;
        return 1;
    }

    TuringMachine tm(tape, initialState, transitionTable);
    tm.execute();

    return 0;
}
