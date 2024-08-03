#include<iostream>
#include<stdio.h>
#include <time.h>
using namespace std;
void burbuja();
int main(){
    int T1,T2;
    
    cout<<"Programa Tarea 2"<<endl;
    T1 = clock();  
    burbuja();
    T2 = clock();
    double segundos_totales = (double(T2-T1)/CLOCKS_PER_SEC);
    cout<<"segundos totales: "<<segundos_totales<<endl;
}

void burbuja(){
    int n = 3;
    int i,j,temp,vector[]= {2,3,1};
    for (i = 0; i < n; ++i){
        for (j = 0; j < n; ++j){
            if (vector[j] < vector[j+1]){
                temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
        }
    }
    for (i = 0; i < n; ++i){
        cout<< vector[i] <<endl;
    }
}
