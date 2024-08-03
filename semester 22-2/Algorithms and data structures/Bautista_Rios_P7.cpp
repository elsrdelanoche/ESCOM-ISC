//Autor: Alfredo Bautista
#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*nodo_siguiente;
};
typedef nodo*apu_nodo;
int main(void){
    int dimension;
    apu_nodo inicio, final, actual;
    cout<<"Digite el numero de nodos: ";
    cin>>dimension;
    
    
        srand(time(NULL));
        for(int i=0;i<dimension;i++){
            if(i==0){
                inicio = new(nodo);
                inicio ->valor=rand();
            }
            else{
                final = new (nodo);
                final ->valor=rand();
            }
            if(i==dimension){
                final -> valor = 0;
            }
        }
        final->nodo_siguiente=inicio;
        int j=0;
        actual=inicio;
        while(j<dimension){
            cout<<actual->valor<<" ";
            actual = actual->nodo_siguiente;
            j++;
        }
}    