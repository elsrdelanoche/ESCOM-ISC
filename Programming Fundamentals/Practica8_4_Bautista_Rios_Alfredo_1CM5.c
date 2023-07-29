/*Practica 8 Problema 4: La transpuesta de una matriz A e R^(nxm), es la matriz de mxnque se 
obtiene a partir de A cambiando las filas por columnas, se dentota A^t, Realiza un programa que 
dadas dos matrices de elementos tipo decimal A y B de n filas y m columnas, calcule A^t * B^t 
dejando el resultado en una matriz C. Debe mostrarse las matrices A,B y C. En caso de que no se 
pueda efectuar la multiplicacion debe enviar un mensaje al usuario*/

//Archivos de programa
#include<stdio.h>
#include<math.h>
#define FIL 10
#define COL 10

//Prototipos de programa
void pideDimA(int*,int*);
void pideDimB(int*,int*);
void leerMtzA(int A[FIL][COL],int,int);
void leerMtzB(int B[FIL][COL],int,int);
void mostrarMtz(int A[FIL][COL],int B[FIL][COL],int,int,int,int);
void transponer(int A[FIL][COL],int B[FIL][COL],int AT[FIL][COL], int BT[FIL][COL],int,int,int,int);
void mostrarMtz2(int AT[FIL][COL], int BT[FIL][COL],int Afil, int Acol,int Bfil, int Bcol);
void multiplicar(int AT[FIL][COL], int BT[FIL][COL],int C[FIL][COL],int,int,int,int);
void mostrarMtz3(int C[FIL][COL],int,int);

//Funcion principal
void main(){
	int A[FIL][COL],B[FIL][COL],C[FIL][COL];
	int AT[FIL][COL], BT[FIL][COL];
	int Afil,Acol,Bfil,Bcol;
	printf("Este programa solicita dos matrices, las transpone y las multiplica.\n");
	pideDimA(&Afil,&Acol);
	pideDimB(&Bfil,&Bcol);
	leerMtzA(A,Afil,Acol); 
	leerMtzB(B,Bfil,Bcol);
	mostrarMtz(A,B,Afil,Acol,Bfil,Bcol);
	transponer(A,B,AT,BT,Afil,Acol,Bfil,Bcol);
	mostrarMtz2(AT,BT,Afil,Acol,Bfil,Bcol);
	multiplicar(AT,BT,C,Afil,Acol,Bfil,Bcol);
	mostrarMtz3(C,Acol,Bfil);
	//mostrarMtz3(A,B,Afil,Acol,Bfil,Bcol);
}

//Cuerpo de funciones
void pideDimA(int*Afil,int*Acol){
	printf("Ingrese el numero de filas en A: ");
	scanf("%d",Afil);
	printf("Ingrese el numero de columnas en A: ");
	scanf("%d",Acol);
}
void pideDimB(int*Bfil,int*Bcol){
	printf("Ingrese el numero de filas en B: ");
	scanf("%d",Bfil);
	printf("Ingrese el numero de columnas en B: ");
	scanf("%d",Bcol);
}
void leerMtzA(int A[FIL][COL], int Afil, int Acol){
	int i, j;
	for(i=0; i<Afil; i++){
		for(j=0; j<Acol; j++){
			printf("A[%d][%d]:",i,j);
			scanf("%d",&A[i][j]);
		}
	}
	printf("\n");
}
void leerMtzB(int B[FIL][COL], int Bfil, int Bcol){
	int i, j;
	for(i=0; i<Bfil; i++){
		for(j=0; j<Bcol; j++){
			printf("B[%d][%d]:",i,j);
			scanf("%d",&B[i][j]);
		}
	}
}
void mostrarMtz(int A[FIL][COL], int B[FIL][COL],int Afil, int Acol,int Bfil, int Bcol){
	
int i, j;

printf("\nLas matrices ingresadas son: ");
printf("\nMatriz A: ");
	for(i=0; i<Afil; i++){
		printf("\n");
		for(j=0; j<Acol; j++)
			printf("  %d  ",A[i][j]);
	}
	printf("\n");
printf("Matriz B: ");
	for(i=0; i<Bfil; i++){
		printf("\n");
		for(j=0; j<Bcol; j++)
			printf("  %d  ",B[i][j]);
	}
	printf("\n");	
}
void transponer(int A[FIL][COL], int B[FIL][COL],int AT[FIL][COL], int BT[FIL][COL],int Afil, int Acol,int Bfil, int Bcol){
	int i,j;
	for(j=0;j<Acol;j++){
		for(i=0;i<Afil;i++){
			AT[i][j]=A[i][j];
		} 	
	}
	for(j=0;j<Bcol;j++){
		for(i=0;i<Bfil;i++){
			BT[i][j]=B[i][j];
		} 	
	}	
}
void mostrarMtz2(int AT[FIL][COL], int BT[FIL][COL],int Afil, int Acol,int Bfil, int Bcol){
	int i,j;
	printf("\nMatriz A transpuesta es:");
	for(j=0; j<Acol; j++){
		printf("\n");
		for(i=0; i<Afil; i++)
			printf("  %d  ",AT[i][j]);
	}
	printf("\n");
printf("Matriz B transpuesta es: ");
	for(j=0; j<Bcol; j++){
		printf("\n");
		for(i=0; i<Bfil; i++)
			printf("  %d  ",BT[i][j]);
	}
	printf("\n");	
}
void multiplicar(int AT[FIL][COL], int BT[FIL][COL],int C[FIL][COL],int Afil, int Acol,int Bfil, int Bcol){
	int i,j,k;
//printf("Multiplicacion de Matrices A*B:\n");
	if(Afil != Bcol){
        printf("\nNo se puede realizar la multiplicacion ya que son matrices incompatibles\n");
		printf("Despues de ser transpuestas el numero de columnas de A debe ser igual a el numero de filas de B.\n");
        end(0);
    }else{
//printf("Matriz C:");
	for(j=0; i<Afil; i++){
		printf("\n");
      for(j=0; j<Bcol; j++){
            C[i][k]=0;
            for(k=0; k<Acol; k++){
                C[i][j]+=(AT[i][k]*BT[k][j]);
                printf("  %d  ",C[i][j]);
            }
        }
    }	
	}
}
void mostrarMtz3(int C[FIL][COL],int Acol, int Bfil){
	int i, j;
	printf("\nMatriz C resultante de A*B: \n");
	for(i=0; i<Acol; i++){
		printf("\n");
		for(j=0; j<Bfil; j++)
			printf("  %d  ",C[i][j]);
	}
}

