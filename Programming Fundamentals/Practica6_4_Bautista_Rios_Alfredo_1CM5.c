/*Practica 6 - Problema 4: Hacer un programa que dado un arreglo A de n 
elementos, los cuales son numeros enteros en orden creciente, obtener un 
arreglo B tal  que sus elementos sean el numero de repeticiones del primer
arreglo. 
Ejemplo
	Entrada A[1,4,4,4,5,5,7,9,9,9,9]
	Salida B[1,3,2,1,4]*/
	
//Archivos de cabecera
#include<stdio.h>
#define MAX 50

//Prototipos de funciones
void darNumElem(int*);
void insertaDatos(char*,int);
void conteo(int,int,char*,char*);
void mostrar(char*,int,int);

//Funcion principal
void main(){
	int n,j=0; 
	char A[MAX],B[MAX];
	darNumElem(&n);
	insertaDatos(A,n);
	conteo(n,j,A,B);
}

//Cuerpo de funciones
void darNumElem(int*n){
	printf("Este programa obtiene un arreglo B con las repeticiones del arreglo A.\n");
	printf("Inserte el numero de elementos: ");
	scanf("%d",n);
}

void insertaDatos(char*A,int n){
	int i;
	printf("Entrada:\n");
	for(i=0;i<n;i++){
		printf("A[%d]:",i+1);
		scanf("%d",&A[i]);
	}
}

void conteo(int n,int j,char*A,char*B){
	int i;
	j=0;
	for(i=0;i<n;i++){
		if(A[i]==A[i+1]){
			B[j]++;
		}else{
			B[j]++;
		j++;	
		}
	}
	mostrar(B,n,j);
}

void mostrar(char*B, int n, int j){
	int i;
	printf("\nSalida: \n");
	for(i=0;i<j ;i++){
		printf("B[%d]=%d\n",i+1,B[i]);
	}
}
