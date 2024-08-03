//Alfredo Bautista
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

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
  cout<<"Mensaje: ";
  for (int i = 0; i <message.size(); i++){
    cout<<message[i];
  }
  cout<<endl;
  return 0;
}