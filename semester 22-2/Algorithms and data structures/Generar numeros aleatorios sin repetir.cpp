//Generar numeros aleatorios sin repetirlos
#include<stdlib.h>
#include<iostream>
#include<time.h>
using namespace std;
int main(){
    int num,n,m;
    int A[100];
    cout<<"Digite el numero de numeros aleatorios: ";
    cin>>n;
    cout<<"digite un maximo.";
    cin>>m;
    srand(time(NULL));
    for(int i=0;i<n;i++){
        A[i]=1+rand()%(m);
        for(int j=0;j<i;j++){
            while(A[i]==A[j]){
                A[i]=1+rand()%(m);
            }
        }
        cout<<A[i]<<"|";
    }
    return 0;
}