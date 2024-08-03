//Ordenamiento_por_mezcla_con_recursividad
//Bibliotecas
#include<bits/stdc++.h>
using namespace std;
//Prototipos de programa
void entrada(vector<int>arreglo);
void imprimirArreglo(vector<int>arreglo);
//Funcion principal
int main(){
    vector<int> prueba;
    entrada(prueba);
    imprimirArreglo(prueba);
    return 0;
}
//Cuerpo de programa
void entrada(vector<int>arreglo){
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d",&n);
    //printf("Usted ingreso: %d\n",n);
    printf("Ingrese los valores para el arreglo\n");
    for(int i=0;i<n;i++){
        printf("[%d]:",i+1);
        //scanf("%d",&arreglo[i]);
        cin>>arreglo[i];
    }
}
void imprimirArreglo(vector<int>arreglo){
    for(int i = 0; i < arreglo.size(); i++){
        printf("%d ",arreglo[i]);
    }
    printf("\n");
}