#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*siguiente;
};
typedef nodo*apuntador;
int main(){
    int n, dato;
    //Declarar punteros
    apuntador inicio=NULL, auxiliar=NULL, fin=NULL;
    //Solicitar cantidad
    cout<<"Ingrese el numero de nodos: ";
    cin>>n;
    //Insertar nodo
    for(int i=0;i<n;i++){
        cout<<"Dato nodo ["<<i+1<<"]: ";
        cin>>dato;
        if(inicio==NULL){
            inicio=new(nodo);
            inicio->valor=dato;
            fin=inicio;
        }
        else{
            auxiliar=new(nodo);
            fin->siguiente=auxiliar;
            auxiliar->valor=dato;
            fin=auxiliar;
        }
        fin->siguiente=NULL;       
    }
    //Mostrar
    auxiliar=inicio;
    cout<<"\nLos elementos de la lista S enlazada son:"<<endl;
    while(auxiliar!=NULL){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->siguiente;
        if(auxiliar!=NULL){ //Flechas decorativas
            cout<<"->";
        }
    }
}