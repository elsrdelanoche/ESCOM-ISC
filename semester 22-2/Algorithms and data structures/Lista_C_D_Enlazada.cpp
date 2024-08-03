#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*ant;
    nodo*sig;
};
typedef nodo*apuntador;
int main(){
    int n, dato;
    apuntador pivote=NULL, auxiliar=NULL, actual=NULL;
    cout<<"Ingrese el numero de nodos: ";
    cin>>n;
    for(int i=0;i<n;i++){
        cout<<"Dato ["<<i+1<<"]: ";
        cin>>dato;
        if(pivote==NULL){
            pivote=new(nodo);
            pivote->valor=dato;
            pivote->ant=pivote;
            pivote->sig=pivote;
            actual=pivote;
        }
        else{
            auxiliar=new(nodo);
            auxiliar->valor=dato;
            auxiliar->ant=actual;
            auxiliar->sig=pivote;
            pivote->ant=auxiliar;
            actual->sig=auxiliar;
            actual=auxiliar;
        }
    }
    //mostrar
    auxiliar=pivote;
    cout<<"Sentido I a D: "<<endl;
    for(int i=0;i<n*2;i++){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->sig;
        cout<<"->";
    }
    auxiliar=pivote;
    cout<<"\nSentido D a I: "<<endl;
    for(int i=0;i<n*2;i++){
        cout<<auxiliar->valor;
        auxiliar=auxiliar->ant;
        cout<<"<-";
    }

}