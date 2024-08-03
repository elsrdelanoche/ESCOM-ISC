#include<bits/stdc++.h>
#include<iostream>
#include<math.h>
#define e 2.71828182845904523536
using namespace std;
int main(){
    double a,b,N;
    cout<<"Este programa calcula la integral de e^(-x^2) por la regla del trapecio.\n";
    cout<<"Ingrese el limite superior: ";
    cin>>b;
    cout<<"Ingrese el limite inferior: ";
    cin>>a;
    cout<<"Asigne un valor a N: ";
    cin>>N;
    double delta=0,suma=0;
    delta=(b-a)/N;
    for(double i=0;i<=N;i++){
        if(i==0 or i==N){
            suma=suma+(1/pow(e,i*i));
        }
        else{
            suma=suma+2*(1/pow(e,i*i));
        }
    }
    cout<<"La integral definida con N="<<N;
    cout<<" es: "<<(delta/2)*suma;
    return 0;
}