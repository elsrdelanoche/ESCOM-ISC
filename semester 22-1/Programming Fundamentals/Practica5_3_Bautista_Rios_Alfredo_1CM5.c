/*Practica 5 - Problema 3: El profesor de una materia desea conocer la 
cantidad de sus alumnos que NO tienen derecho a examen extraordinario. 
Realice un programa que lea las calificaciones obtenidas en las N unidades 
por casa uno de los M alumnos y muestre la cantidad de ellos que no tienen
derecho a examen extraordinario.*/

//Archivos de cabecera
#include<stdio.h>

//Prototipos de funciones

void entrada(int*,int*);
void evalua(int,int);
void entradaCalif(int,int,int*);
void salidaProm(int,int);
void salida(int,int);

//Funcion principal
void main(){
	int M,N ;
	entrada(&M,&N);
	evalua(M,N);
}

//Cuerpo de funciones
void entrada(int*M,int*N){
	printf("**Este programa indica la cantidad de alumnos que no tienen derecho a extra (Alumnos con calificacion>=7)**\n");
	printf("Digite el numero de alumnos: ");
	scanf("%d",M);
	printf("Digite el numero de unidades: ");
	scanf("%d",N);
}

void evalua(int M,int N){
	int a=1,u=1;
	int suma=0,SD=0;
	int promedio,calificacion;

for(a=1;a<=M;a++){
	
	for(u=1,suma=0;u<=N;u++){
		entradaCalif(a,u,&calificacion);
		suma=suma+calificacion;
	}
	
	promedio=suma/3;
	salidaProm(a,promedio);
	if(promedio>=7)
	SD++;
	
}
salida(SD,M);
}
void entradaCalif(int a, int u, int*calificacion){
	printf("Ingrese calificacion del Alumno %i en Unidad %i: ",a,u);
	scanf("%i",calificacion);
}
void salidaProm(int a, int promedio){
	printf("El promedio del alumno %i es: %i\n",a,promedio);
}

void salida(int SD,int M){
	printf("\nLa cantidad de alumnos sin derecho a extrardinario es: %i, no necesitan mejorar su calificacion.",SD);
	printf("\nLa cantidad de alumnos con derecho a extrardinario es: %i, necesitan mejorar su calificacion ",M-SD);
}


