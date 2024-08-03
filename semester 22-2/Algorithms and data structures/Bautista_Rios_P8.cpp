//Autor: Alfredo Bautista
#include<bits/stdc++.h>
using namespace std;

struct nodo{
    int valor;
    nodo*nodo_sig;
};
typedef nodo*apu_nodo;

int main(){
    int dimension,numero;
    nodo *lista = NULL;
    nodo *lista0=NULL;        //Creamos la lista
    //Solicitar dimension
    cout<<"Ingrese el tamaño de la lista: ";
    cin>>dimension;
    for(int i=0;i<dimension;i++){
        nodo *nuevo = new nodo ();  //Crea nuevo nodo
        //insertamos datos
        cout<<"Nodo ["<<i+1<<"]: ";
        cin>>numero;  //Guardo el valor en variable
        nuevo->valor = numero;        //A ese nodo le damos el valor
                                    //Crear dos nodos auxiliares
        nodo *aux1 = lista;         //El primero lo enlazamos a lista
        nodo *aux2;
        //ordenamos con burbuja de while
        while((aux1 != NULL)&&(aux1->valor < numero)){//Solo casos dentro de las dimensiones y si el numero es mayor a el valor en turno
        aux2 = aux1;                //El segundo tambien apuntara a lista
        aux1 = aux1->nodo_sig;      
        }
        if(lista == aux1){          //Condicion solo para conectar el primer nodo
            lista = nuevo; 
        }
        
        else{
            aux2->nodo_sig = nuevo;  
        }
        nuevo->nodo_sig = aux1;

    }
    //Mostrar lista
    nodo *actual = new nodo();
    actual = lista;
    while(actual != NULL){
    cout<<actual->valor;
    actual = actual->nodo_sig;
    if(actual!=NULL){
        cout<<" ->  ";
    }
    }
    cout<<endl;

  
    //Eliminar nodos con valores pares
    if(lista==NULL){
        cout<<"La lista esta vacia\n";
    }
    else{
        for(int i=0;i<dimension;i++){
            nodo *aux_borrar;
            nodo *anterior = NULL;
            while(lista&&lista->valor %2==0){
                aux_borrar = lista;
                lista = lista ->nodo_sig;
                delete(aux_borrar);
            }
            aux_borrar=lista;
            while(aux_borrar && aux_borrar -> nodo_sig ->valor%2==0){
                while(aux_borrar->nodo_sig&&aux_borrar->nodo_sig->valor%2==0){
                anterior=aux_borrar->nodo_sig;
                aux_borrar->nodo_sig=anterior->nodo_sig;                    
                }
                aux_borrar=aux_borrar->nodo_sig; 
            }     
        }

    }
    

    //Volver a imprimir
    nodo *actual2 = new nodo();
    actual2 = lista;
    while(actual2 != NULL){
    cout<<actual2->valor;
    actual2 = actual2->nodo_sig;
    if(actual2!=NULL){
        cout<<" ->  ";
    }
    }

}