//Alfredo Bautista Rios 2CV4
#include<iostream>
#include<stdio.h>
#include<math.h>
#include<conio.h>
using namespace std;
int main(){
	float x1=0, x2=0, a, b, c;
	cout<<"Inserte el valor de A: "; cin>>a;
	cout<<"Inserte el valor de B: "; cin>>b;
	cout<<"Inserte el valor de C: "; cin>>c;
	
    if((pow(b,2)-4*a*c)>0){
        cout<<"Hay dos soluciones:\n";
        x1=(-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        x2=(-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        cout<<"X1: "<<x1<<endl;
        cout<<"x2: "<<x2<<endl;
    }
    if((pow(b,2)-4*a*c)==0){
        cout<<"Una solucion doble: \n";
        x1=(-b+(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        x2=(-b-(sqrt(pow(b,2)-(4*a*c))))/(2*a);
        cout<<"X1: "<<x1<<endl;
        cout<<"x2: "<<x2<<endl;
    }
    if((pow(b,2)-4*a*c)<0){
        cout<<"Solucion con numeros complejos: \n";
        int raiz=0;
        float x11=0,x21=0;
        raiz=pow(b,2)-(4*a*c);
        if(raiz<0){
            raiz=raiz*(-1);
        }
        x1=(-b/(2*a));
        x11=sqrt(raiz)/2*a;
        x2=(-b/(2*a));
        x21=sqrt(raiz)/2*a;

        cout<<"x1= "<<x1;
        cout<<"-"<<x11<<"i"<<endl;
        cout<<"x2= "<<x2<<"-";
        cout<<x21<<"i"<<endl;
    }
}
