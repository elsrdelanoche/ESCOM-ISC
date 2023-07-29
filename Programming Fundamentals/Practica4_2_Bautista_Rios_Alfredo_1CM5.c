/*Practica 4: Problema 2, Escribir un programa que calcule la suma total e imprima en
la pantalla los N terminos de la seria siguiente:Sumatoria N K=1 K(2K-1) El programa debe
 solicitar al usuario el valor entero N. Recuerde que la funcion que realiza el calculo 
 de la suma no debe imprimir por lo tanto debe invocar a la funcion mostrar 1*1+2*3+3*5+4*7*/
 
//Archivos de cabecera
#include<stdio.h>
#include<stdlib.h>

//Prototipos de funcion
void entrada(int*);
void operacion(int);
void salida();
void salidatotal();

//funcion principal
void main(){
	int N;
	entrada(&N);
	operacion(N);
}

//cuerpo de funciones
void entrada(int*N){
	printf("Este programa suma k(2k-1) con iniciando con K=1 hasta el valor de N que ud indique.\n");
	printf("\nDigite el valor de N:");
	scanf("%d",N);
}

void operacion(int N){
	int k=1,a;
	int total=0;
	do{
		a=k*(2*k-1);
		salida(k,a);
		k++;
		total=total+a;
	}while(k<=N);
	salidatotal(total);
}

void salida(int k, int a){
	printf("%i(2*%i-1)=%i \n",k,k,a);
	
}

void salidatotal(int total){
	printf("La suma total es: %i\n",total);
	exit(0);
}
