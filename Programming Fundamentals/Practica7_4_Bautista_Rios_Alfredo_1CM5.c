/*Problema 4 Escriba un programa que tenga una funci�n rotaDerecha(int*A, int num, int nelem, int*B) que
reciba un arreglo A de n elementos tipo caracter y un entero num que indica el n�mero de veces a desplazarse
almacenando dicho resultado en el arreglo B. La funci�n debe mover a cada elemento una posici�n hacia la
derecha de acuerdo al valor de num. Por ejemplo, si el arreglo A de nelem=8 tuviera los valores A=[a bc de f
g h] y num�2, despu�s de invocar a la funci�n rotaDerecha el arreglo B quedar�a de la siguiente manera: B=
[h gabe def] El programa debe desplegar ambos arreglos (A y B) a trav�s de la funci�n mostrar. Considere
el tama�o de los arreglos es de 30.*/

//Archivos de programa
#include<stdio.h>
#include<string.h>
#define MAX 50

//Prototipos de funciones
void entrada(char*A,int*num);
int longitud(char* );
void rotarDerecha(char*A,int num,int nelem,char*B);
void salida(char*B,char*A);

//Funcion Principal
void main(){
	int nelem,num;
	char A[MAX], B[MAX];
	entrada(A,&num);
	nelem=longitud(B);
	rotarDerecha(A,num,nelem,B);
	salida(B,A);
}

//Cuerpo de funciones
void entrada(char*A,int*num){
	printf("Inserte la cadena 1: ");
	scanf("%[^\n]",A);
	getchar();
	printf("Indique cuantas veces se desplazara a la derecha:");
	scanf("%i",num);
}

int longitud(char*B){
	return(strlen(B));
}

void rotarDerecha(char*A,int num,int nelem,char*B){
	int i,temp,j;
	nelem=strlen(A);
/*	printf("La cadena ingresada fue: %s\n",A);
	printf("Se recorrera a la derecha %d veces.\n",num);
	printf("El numero de elementos es: %d\n",nelem);*/
	strcpy(B,A);

	while(num--){
		temp=B[nelem-1];
//printf(" %s\n",B);
			for(j=nelem-1;j>0;j--){
				B[j]=B[j-1];
//printf(" %s\n",B);
			}
		B[0]=temp;
//printf(" %s\n",B);
	}

}

void salida(char*B,char*A){
	printf(" la cadena B queda: %s\n",B);
	printf("La cadena A ingresada fue: %s\n",A);
}
