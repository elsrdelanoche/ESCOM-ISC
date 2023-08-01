//Un programa de Alfredo Bautista 2CV3
#include<bits/stdc++.h>
using namespace std;
int main(){
    int A[100],B[100],C[100],n1,n2;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d",&n1);
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d",&n2);
    printf("Ingrese el primer arreglo ordenado:\n");
    for(int i=0;i<n1;i++){
        scanf("%d",&A[i]);
    }
    printf("Ingrse el segundo arreglo ordenado:\n");
    for(int i=0;i<n2;i++){
        scanf("%d",&B[i]);
    }
    printf("Los arreglos ingresados son: \n");
    for(int i=0;i<n1;i++){
       printf("%d\t",A[i]);
    }
    printf("\n");
    for(int i=0;i<n2;i++){
       printf("%d\t",B[i]);
    }
    //Mezcla de arreglos
    int p=0,q=0,r=0;
    while(p<(n1+n2)){
            if(A[p]<B[q]){
               C[r]=A[p];
               p++;
            }
           else{
               C[r]=B[q];
               q++;
           } 
       r++;
    }
    //Imprimir Mezcla
    printf("\nLos arreglos ingresados son: \n");
    for(int i=0;i<(n1+n2);i++){
       printf("%d\t",C[i]);
    } 
    return 0;
}