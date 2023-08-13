#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
  char character;
  int frequency;
  Node *left, *right;

  Node(char character, int frequency) : character(character), frequency(frequency), left(nullptr), right(nullptr) {}
};

string decode(Node* root, string encodedMessage) {
    string decodedMessage;
    Node* current = root;
    for (char bit : encodedMessage) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (current->left == nullptr && current->right == nullptr) {
            decodedMessage += current->character;
            current = root;
        }
    }
    return decodedMessage;
}

int main() {
  // Abrir el archivo y leer los datos
  ifstream file("HUFFMAN.txt");
  vector<char> characters;
  vector<int> frequencies;
  string message;
  string line;

  //Leer valores
  while (getline(file, line)){
    // Si la línea comienza con "Caracter:", leer los caracteres
    if (line.substr(0, 10) == "Caracter: ") {
      line = line.substr();
      for (int i = 10; i < line.size(); i++) {
        if(line[i]!=',')
        characters.push_back(line[i]);
      }
    }
    // Si la línea comienza con "Frecuencia:", leer las frecuencias
    else if (line.substr(0, 12) == "Frecuencia: ") {
      line = line.substr();
      for (int i = 12; i < line.size(); i++) {
        if(line[i]%1==0&&line[i]!=','){
          frequencies.push_back(line[i] - '0');
        }
      }
    }
    // Si la línea comienza con "Mensaje:", leer el mensaje
    else if (line.substr(0, 9) == "Mensaje: ") {
      for(int i=9;i<line.size();i++){
        if(line[i]=='1'||line[i]=='0'){
          message.push_back(line[i]);
        }
      }
    }
  
  }
  cout<<"Valores leidos:"<<endl;
  cout<<"Caracter: ";
  for (int i = 0; i <characters.size(); i++){
    cout<<characters[i]<<" ";
  }
  cout<<endl;
  cout<<"Frecuencia: ";
  for (int i = 0; i <frequencies.size(); i++){
  cout<<frequencies[i]<<" ";
  }
  cout<<endl;
  cout<<"Mensaje: "<<message<<endl;

  vector<Node*> nodes;
  for (int i = 0; i < characters.size(); i++) {
  Node* temp = new Node(characters[i], frequencies[i]);
  nodes.push_back(temp);
  }

  while (nodes.size() > 1) {
  // Step 1
  sort(nodes.begin(), nodes.end(), [](Node* a, Node* b) {
  return a->frequency < b->frequency;
  });
  Node* left = nodes[0];
  Node* right = nodes[1];
  // Step 2
  Node* parent = new Node('\0', left->frequency + right->frequency);
  parent->left = left;
  parent->right = right;

  // Step 3
  nodes.erase(nodes.begin());
  nodes.erase(nodes.begin());
  nodes.push_back(parent);

  // Step 4
  }

Node* root = nodes[0];
cout<<"Mensaje decodificado: "<<decode(root, message)<<endl;

return 0;
}
