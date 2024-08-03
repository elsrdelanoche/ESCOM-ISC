//Codigo busqueda binaria
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int b,i,j,k;
    int v[8]={2,4,5,6,9,15,18,20};

    printf("Ingrese numero a buscar");
    scanf("%d",&b);
    i=0;
    j=8-1;
    do{
        k=(i+j)/2;
        if(v[k]<=b){
            i=k+1;
        }
        if(v[k]>=b){
            j=k-1;
        }
    }while(i<=j);
    printf("Elemento %d esta en %d\n",v[k],k);
    return 0;
}