/*Arbol dinamico 
    autor: Alfredo Bautista 
            Alejandro Hidalgo
    Grupo: 2CV3*/
#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*izq;
    nodo*der;
};
typedef nodo*puntero;
int main(){
    puntero raiz=NULL, actual,nuevo;
    int n,A[n];
	
    cout<<"digite la cantidad de elementos: ";
    cin>>n;
	int nivelMax=log2(n)+1;
	int B[nivelMax][n],C[n];
    for(int i=0;i<n;i++){//Lleno el arreglo
        cout<<"Dato "<<i+1<<" :";
        cin>>A[i];
    }
    //Llenar matriz con zeros
    for(int i=0;i<nivelMax;i++){
        for(int j=0;j<n;j++){
           B[i][j]=0;
        }
    }
    //Obtener nivel por busqueda binaria
    for(int i=0;i<n;i++){
        int numero=A[i];//Numero a buscar
        int inicio=0;
        int fin=n-1;
        int actual,nivel=0;
        do{
            actual=(inicio+fin)/2;
            if(A[actual]<=numero){
                inicio=actual+1;
            }
            if(A[actual]>=numero){
                fin=actual-1;
            }
            nivel++;
        }while(inicio<=fin);
        cout<<"El elemento "<<A[i]<<" esta en "<<actual<<" nivel "<<nivel<<endl;
        B[nivel-1][i]=A[i];
    }
    int k=0;//Será el contador de C
    cout<<"Imprimir matriz: "<<endl;
    for(int i=0;i<nivelMax;i++){//Reorenaremos el arreglo
        for(int j=0;j<n;j++){
            if(B[i][j]!=0){
               cout<<B[i][j];
			   C[k]=B[i][j]; 
               k++;
            }
			if(B[i][j]==0){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    cout<<"Nuevo arreglo\n";
    for(int i=0;i<n;i++){   //Imprimimos el nuevo arreglo
        cout<<C[i]<<" ";
    }
}