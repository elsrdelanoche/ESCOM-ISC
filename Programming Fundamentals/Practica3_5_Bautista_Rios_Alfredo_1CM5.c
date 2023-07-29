/*Practica 3	Problema 5
Haga un menu que permita elegir una figura (esfera, cubo, prisma restangular) y calcular su volumen.
Considere tambien el caso de salir y el de default Utilice una estructura selectiva multiple*/
//archivos de cabecera
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define Pi 3.1416

//Prototipo de funciones
void entrada(int*);
void menu(int,float*);
void salida(float);

//Funcion principal
int main( ){
    float v;
    int opc;
	entrada(&opc);
	menu(opc,&v);
    salida(v);
}

//Cuerpo de funciones
void entrada(int*opc){
printf("Este programa calcula las siguientes operaciones \n");
printf(" 1. Volumen de una esfera. \n");
printf(" 2. Volumen de un cubo. \n");
printf(" 3. Volumen de un prisma rectangular. \n");
printf(" 4. Salir  \n\n");
printf("Elija una opcion: ");
scanf("%d", opc); 
}

void menu(int opc,float*v){
float r, a, largo, ancho, alto;
switch(opc){
	case 1:
		printf("\nVolumen de una esfera.\n");
		printf("Inserte el radio de la esfera: \n");
		scanf("%f",&r);
		*v=(4*Pi/3)*(pow(r,3));
		break;
	case 2: 
		printf("\nVolumen de un cubo.\n");
		printf("Inserte la arista del cubo: \n");
		scanf("%f",&a);
		*v=pow(a,3);
		break;
	case 3: 
		printf("\nVolumen de un prisma rectangular.\n");
		printf("Inserte el largo del prisma: \n");
		scanf("%f",&largo);
		printf("Inserte el ancho del prisma: \n");
		scanf("%f",&ancho);
		printf("Inserte el alto del prisma: \n");
		scanf("%f",&alto);
		*v=largo*ancho*alto;
		break;
	case 4: exit(0);
		break;
	default: printf("\nOpcion no valida \n");
		break;
		}     
}

void salida(float v){
	printf("\nEl volumen es: %.2f \n", v);
	printf("Hasta Pronto\n");
}

