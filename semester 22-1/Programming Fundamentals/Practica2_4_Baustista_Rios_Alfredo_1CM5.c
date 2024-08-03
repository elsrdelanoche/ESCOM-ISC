/*Practica - Problema 4 realice un programa para evaluar el valor 
de x de tipo decimal en la derivada de la siguiente funcion 
f(x)=raiz(x+raiz(x)+raizcub(x))en su libreta obtenga la derivada 
y codifique la expresion matematica resultante*/

 //Archivos de cabecera
#include<stdio.h>
#include<math.h>
//Prototipo de funciones
void entrada(float*);
void operacion(float,float*);
void salida(float,float);

//Funcion principal
void main(){
float x,z;
entrada(&x);
operacion(x,&z);
salida(x,z);
}

//Cuerpo de funciones
void entrada(float*x){
	printf("Digite el valor a ser evaluado en la derivada: \n");
	scanf("%f",x);
}

void operacion(float x, float*z){
	float a,b,c,d,e;
	a=x+sqrt(x)+pow(x,1.0/3);
	b=pow(a,3);
	c=b*x;
	d=(6*pow(x,1.0/6)*abs(x)+3*pow(x,2.0/3)+2*sqrt(x));
	e=(12*pow(c,1.0/6)*abs(x));
	*z=d/e;
}

void salida(float x, float z){
	printf("Al evaluar x=%.2f en la derivada de la funcion, el resultado es: %f \n",x,z);
}

