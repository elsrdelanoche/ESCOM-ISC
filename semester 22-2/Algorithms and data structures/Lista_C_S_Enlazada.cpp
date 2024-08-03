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
    apuntador pivote=NULL, auxiliar=NULL, actual=NULL;
    //Solicitar cantidad
    cout<<"Ingrese el numero de nodos: ";
    cin>>n;
    //Insertar nodo
    for(int i=0;i<n;i++){
        cout<<"Dato nodo ["<<i+1<<"]: ";
        cin>>dato;
        if(pivote==NULL){
            pivote=new(nodo);
            pivote->valor=dato;
            pivote->siguiente=pivote;
            actual=pivote;
        }
        else{
            auxiliar=new(nodo);
            auxiliar->valor=dato;
            auxiliar->siguiente=pivote;
            actual->siguiente=auxiliar;
            actual=auxiliar;
        }   
    }
    //Mostrar
    auxiliar=pivote;
    cout<<"\nLos elementos de la lista circular simple son:"<<endl;
    for(int i=0;i<n*2;i++){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->siguiente;
        //Flechas decorativas
        cout<<"->";
    }
}