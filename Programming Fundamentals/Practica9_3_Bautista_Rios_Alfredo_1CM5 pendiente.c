//Archivo de programa
#include<stdio.h>
#include<stdlib.h>
//Prototipos de programa
void darDim(int*n,int*m);
void validacion(int n,int m);
int**crearMatrizA(int n);
int**crearMatrizB(int n);
int*crearArregloC(int n);
int*crearArreglotemp(int n);
void darDatosA(int**A,int n,int m);
void darDatosB(int**B,int n,int m);
void mostrar(int**A,int**B,int n,int m);
void operacion(int**A,int**B,int*C,int*temp,int n,int m);
void mensaje1();
//Funcion principal
int main(){
	int i,j,n,m,**A,**B,*C,*temp;
	darDim(&n,&m);
	validacion(n,m);
	A=crearMatrizA(n);
	B=crearMatrizB(n);
	C=crearArregloC(n);
	temp=crearArreglotemp(n);
	darDatosA(A,n,m);
	darDatosB(B,n,m);
	mostrar(A,B,n,m);
	operacion(A,B,C,temp,n,m);
}
//Cuerpo de funciones
void darDim(int*n,int*m){
	printf("Indique el numero filas: ");
	scanf("%d",n);
	printf("Indique el numero de columnas: ");
	scanf("%d",m);
}
void validacion(int n,int m){
	if(n!=m){
		printf("El numero de filas debe ser igual al de columnas.\n");
		exit(0);
	}
}
int**crearMatrizA(int n){
	int **A,i;
	A=(int**)malloc(n*sizeof(int*));
	if(A==NULL){
		mensaje1();
		exit(0);
	}
	for(i=0;i<n;i++){
		A[i]=(int*)malloc(sizeof(int)*n);
	}
	return A;
}
int**crearMatrizB(int n){
	int **B,i;
	B=(int**)malloc(n*sizeof(int*));
	if(B==NULL){
		mensaje1();
		exit(0);
	}
	for(i=0;i<n;i++){
	B[i]=(int*)malloc(sizeof(int)*n);
	}
	return B;
}
int*crearArregloC(int n){
	int *C;
	C=(int*)malloc(n*sizeof(int));
	if(C==NULL){
		mensaje1();
		exit(0);
	}
	return C;
}
int*crearArreglotemp(int n){
	int *temp;
	temp=(int*)malloc(n*sizeof(int));
	if(temp==NULL){
		mensaje1();
		exit(0);
	}
	return temp;
}
void darDatosA(int**A,int n,int m){
	int i,j;
	printf("Ingrese los datos de la matriz.\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Dato[%d][%d]= ",i,j);
			scanf("%d",&A[i][j]);
		}
	}
}
void darDatosB(int**B,int n,int m){
	int i,j;
	printf("Ingrese los datos de la matriz.\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Dato[%d][%d]= ",i,j);
			scanf("%d",&B[i][j]);
		}
	}
}
void mostrar(int**A,int**B,int n,int m){
	int x,y;
	printf("\nUsted ingreso: ");
	printf("Matriz A:\n");
	for(x=0;x<n;x++){
		printf("\n");
		for(y=0;y<m;y++){
			printf("%d\t",A[x][y]);
		}
	}
		printf("\nMatriz B:\n");
	for(x=0;x<n;x++){
		printf("\n");
		for(y=0;y<m;y++){
			printf("%d\t",B[x][y]);
		}
	}
}
void operacion(int**A,int**B,int*C,int*temp,int n,int m){
	int i,j,k,l,aux;
	int sumaA,promA;
	for(i=0;i<n;i++){
		sumaA=0;
		A[i][j]=temp[i];
		for(j=0;j<m;j++){
			sumaA=sumaA+A[j][i];
		}
		promA=sumaA/n;
		printf("\nprom=%d",promA);
	}
	

	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			temp[j]=B[i][j];//copiar cada fila a un arreglo temporal
		}
	//------------------		
				//Para obtener el mayor de cada fila hare metodo burbuja
			for(k=0;k<n;k++){
				for(l=0;l<n;l++){
					if(temp[l]<temp[l+1]){
						aux=temp[l];
						temp[l]=temp[k];
						temp[k]=aux;
					}
					
				}
			}
			for(i=0; i<n; i++){
			printf("| %d ",temp[i]);
			}
			printf("|\n");
			printf("El mmayor de la fila %d es %d\n",k+1,temp[0]);
	}
	//--------------------
	
	
	
}
void mensaje1(){
	printf("No hay memoria disponible.\n");	
}
