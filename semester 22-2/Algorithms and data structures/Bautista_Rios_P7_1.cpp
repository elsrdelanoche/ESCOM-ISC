//Autor: Alfredo Bautista
#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*nodo_siguiente;
};
typedef nodo*apu_nodo;
int main(void){

    nodo estatico;
    estatico.valor=24;
    estatico.nodo_siguiente=NULL;

    apu_nodo dinamico;
    if(dinamico==NULL){
        cout<<"No se reservo la memoria"<<endl;
    }
    else{
        dinamico = new(nodo);
        dinamico -> valor = 25;
        dinamico -> nodo_siguiente = NULL;
    }
    
    cout<<"Estatico: "<<estatico.valor<<endl;
    cout<<"Dinamico: "<<dinamico->valor<<endl;
}