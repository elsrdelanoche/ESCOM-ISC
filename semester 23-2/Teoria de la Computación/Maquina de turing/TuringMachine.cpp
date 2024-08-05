#include <iostream>
#include <vector>
#include <unordered_map>
#include <tuple>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

using namespace std;

class TuringMachine {
public:
    TuringMachine(vector<char> tape, int initialState, unordered_map<tuple<int, char>, tuple<int, char, int>> transitionTable)
        : tape(tape), head(0), currentState(initialState), transitionTable(transitionTable) {}

    void execute() {
        cout << "Starting Turing Machine Execution..." << endl;
        cout << "Initial Tape: ";
        printTape();
        while (true) {
            this_thread::sleep_for(chrono::milliseconds(500)); // Pause for visualization

            if (transitionTable.find({currentState, tape[head]}) == transitionTable.end()) {
                cout << "\nFinal State Reached: " << currentState << endl;
                cout << "Final Tape: ";
                printTape();
                return;
            }

            auto [nextState, writeSymbol, moveDirection] = transitionTable[{currentState, tape[head]}];
            tape[head] = writeSymbol;
            currentState = nextState;
            head += moveDirection;

            cout << "\nStep: ";
            printTape();
            cout << "Current State: " << currentState << endl;
        }
    }

private:
    vector<char> tape;
    int head;
    int currentState;
    unordered_map<tuple<int, char>, tuple<int, char, int>> transitionTable;

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
    }
};

unordered_map<tuple<int, char>, tuple<int, char, int>> parseTransitionTable(istream& input) {
    unordered_map<tuple<int, char>, tuple<int, char, int>> transitionTable;
    string line;
    while (getline(input, line)) {
        istringstream iss(line);
        int currentState, nextState, moveDirection;
        char readSymbol, writeSymbol;
        if (iss >> currentState >> readSymbol >> nextState >> writeSymbol >> moveDirection) {
            transitionTable[{currentState, readSymbol}] = {nextState, writeSymbol, moveDirection};
        } else {
            cerr << "Error parsing line: " << line << endl;
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
    unordered_map<tuple<int, char>, tuple<int, char, int>> transitionTable;
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
        while (true) {
            getline(cin, line);
            if (line.empty()) break;
            istringstream iss(line);
            int currentState, nextState, moveDirection;
            char readSymbol, writeSymbol;
            if (!(iss >> currentState >> readSymbol >> nextState >> writeSymbol >> moveDirection)) {
                cerr << "Error parsing transition table." << endl;
                continue;
            }
            transitionTable[{currentState, readSymbol}] = {nextState, writeSymbol, moveDirection};
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

