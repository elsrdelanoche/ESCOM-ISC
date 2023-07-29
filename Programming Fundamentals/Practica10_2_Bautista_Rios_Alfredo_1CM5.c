//Archivos de programa
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Definicion de las estructuras
typedef struct punto{
	int x;
	int y;
}Punto;
//Prototipos de programa
Punto*crearEstructPuntoA();
Punto*crearEstructPuntoB();
void pedirPuntos(Punto*A,Punto*B);
void mostrar(Punto*A,Punto*B);
void puntoMedio(Punto*A,Punto*B);
void distancia(Punto*A,Punto*B);
void mostrarMsg();
void liberar();
//Funcion principal
void main(){
	Punto*A;
	Punto*B;
	int opc;
	printf("Seleccione la opcion a realizar.\n");
	printf("1.Crear dinamicamente la estructura Punto.\n");
	printf("2.Solicitar los valores de Punto A y Punto B.\n");
	printf("3.Obtenga el punto medio entre A y B.\n");
	printf("4.Obtenga la distancia entre el punto A y B.\n");
	printf("5.Salir y liberar.");
	do{
		printf("\nSeleccionar opcion del menu: ");
		scanf("%d",&opc);
		switch(opc){
		case 1: A=crearEstructPuntoA();
				B=crearEstructPuntoB();
			break;
		case 2:	pedirPuntos(A,B);
				mostrar(A,B);
			break;
		case 3:	puntoMedio(A,B);
			break;
		case 4:	distancia(A,B);
			break;
		case 5: liberar(A,B);
				exit(0);
		}	
	}while(opc!=5);
}
//Cuerpo de funciones
Punto*crearEstructPuntoA(){
	printf("Se creo dinamicamente la estructura punto A...\n");
	Punto*nvo;
	nvo=(Punto*)malloc(sizeof(Punto));
	if(nvo==NULL){
		mostrarMsg();
		exit(0);
	}
}
Punto*crearEstructPuntoB(){
	printf("Se creo dinamicamente la estructura punto B...\n");
	Punto*nvo;
	nvo=(Punto*)malloc(sizeof(Punto));
	if(nvo==NULL){
		mostrarMsg();
		exit(0);
	}
}
void pedirPuntos(Punto*A,Punto*B){
	printf("*Introduzca los puntos*\n");
	printf("Punto A en x:");
	scanf("%d",&A->x);
	printf("Punto A en y:");
	scanf("%d",&A->y);
	getchar();
	printf("Punto B en x:");
	scanf("%d",&B->x);
	printf("Punto B en y:");
	scanf("%d",&B->y);
}
void mostrar(Punto*A,Punto*B){
printf("Usted ingreso A(%d,%d) y B(%d,%d)\n",A->x,A->y,B->x,B->y);
}
void puntoMedio(Punto*A,Punto*B){
	int x1,y1;
	x1=((A->x+B->x)/2);
	y1=((A->y+B->y)/2);
	//printf("El punto medio es: (%d,%d)\n",((A->x+B->x)/2),((A->y+B->y)/2));
	printf("El punto medio es: (%d,%d)\n",x1,y1);
}
void distancia(Punto*A,Punto*B){
	float d;
	d=sqrt(pow(B->x-A->x,2)+pow(B->y-A->y,2));
	printf("La distancia entre (%d,%d) y (%d,%d) es: %f\n",A->x,A->y,B->x,B->y,d);
	
}
void mostrarMsg(){
printf("\nNo hay memoria disponible...");
}
void liberar(Punto*A,Punto*B){
free(A);
free(B);
printf("Memoria liberada...\n");
printf("Hasta pronto... :)\n");
}
