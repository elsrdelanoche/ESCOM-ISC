//
#include <bits/stdc++.h>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <time.h>
using namespace std;
//Protoripos de funciones
void lectura();

//Funcion principal
int main(){
    system("cls");
    cout<<"*******Bienvenido********"<<endl;
    cout<<"Este programa lee numeros de un archivo de texto"<<endl;
    //Solicitar dimensiones
    system("cls");
    lectura(); //Dar lectura de datos
}

void lectura(){
    ifstream archivo;
    string texto;
    string num;  
    vector<int> numbers;
    cout<<"Leyendo archivo..."<<endl;
    archivo.open("MATRIZ_1.txt",ios::in); //Abriendo el archivo en modo lectura

    if(archivo.fail()){
        cout<<"No fue posible abrir el archivo";
        exit(1);
    }

    while (!archivo.eof()) {
        getline(archivo,texto);
		
        texto+="x";
        num="";

        for(int i=0;i<texto.length();i++){
            if(texto[i]>=48 && texto[i]<=57){
                num+=texto[i];
            }
            else{
                if(num!=""){
                    numbers.push_back(atoi(num.c_str()));
                    num="";
                }
            }
        }
    }
    for(int i=0;i<numbers.size();i++){
        cout<<numbers[i]<<" ";
    }
    cout << endl;
    archivo.close();//cerramos el archivo
    cout<<"Lectura finalizada :)"<<endl;
}