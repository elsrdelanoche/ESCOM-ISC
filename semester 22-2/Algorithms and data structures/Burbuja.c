//autor: Alfredo Bautista 2CV3
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(){
	int A[]={4,1,2,5,8,9,6,10,3,7};
    int i,j,aux;
	clock_t t0, t1;
	//Mostrar en pantalla
	srand(time(NULL));
	t0=clock();
	printf("El arreglo desordenado es: \n");
	for(i=0;i<10;i++){
		printf("%d\t",A[i]);
	}
	//Ordenar
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			if(A[j]>A[j+1]){
				aux=A[j];
				A[j]=A[j+1];           
				A[j+1]=aux;
			}
		}
	}
	//Mostrar en pantalla
	printf("\nEl arreglo ordenado es: \n");
	for(i=0;i<10;i++){
		printf("%d\t",A[i]);
	}
	t1=clock();
	float time = float(t1-t0)/CLOCKS_PER_SEC;
	printf("\nEl tiempo de ejecucion es: %f segundos\n",time);
	int procesos=(120.0/time);
	printf("Es posble realizar %d procesos en 2min.",procesos);
	return 0;
}