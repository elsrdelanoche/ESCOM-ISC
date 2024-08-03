#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*sig;
    nodo*ant;
};
typedef nodo*apuntador;
int main(){
    int n, dato;
    apuntador inicio=NULL, auxiliar=NULL, fin=NULL;
    cout<<"Ingrese la cantidad de nodos: ";
    cin>>n;
    //insertar nodos
    for(int i=0;i<n;i++){
        cout<<"Dato ["<<i+1<<"]: ";
        cin>>dato;
        if(inicio==NULL){
            inicio=new(nodo);
            inicio->valor=dato;
            inicio->ant=NULL;
            inicio->sig=NULL;
            fin=inicio;
        }
        else{
            auxiliar=new(nodo);
            auxiliar->valor=dato;
            auxiliar->ant=fin;
            fin->sig=auxiliar;
            fin=auxiliar;
        }
        fin->sig=NULL;
    }
    //Mostrar
    cout<<"\nLista de I a D:"<<endl;
    auxiliar=inicio;
    while(auxiliar!=NULL){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->sig;
        if(auxiliar!=NULL){
            cout<<"->";
        }
    }
    cout<<"\nLista de D a I:"<<endl;
    auxiliar=fin;
    while(auxiliar!=NULL){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->ant;
        if(auxiliar!=NULL){
            cout<<"<-";
        }
    }
}