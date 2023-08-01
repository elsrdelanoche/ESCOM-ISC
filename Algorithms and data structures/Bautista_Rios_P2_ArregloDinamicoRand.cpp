//autor: Alfredo Bautista 2CV3
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void){
	//int arreglo[10000000];
	//long int 2147483647
	long int *arreglo_dinamico;
	long int n=10e8;
	clock_t t0, t1;
	
	arreglo_dinamico=(long int *) malloc(n*sizeof(long int));  //memory allocation
	
	if (arreglo_dinamico==NULL) 
		printf("�No se pudo reservar la memoria!\n"); 
	else
	{
		//arreglo_dinamico[0] = 5;
		//printf("\n trae el valor: %d", arreglo_dinamico[0]);
		srand(time(NULL));
		t0=clock();
		for(long int i=0;i<n;i++){
			arreglo_dinamico[i]=1+rand()%(20);
			//printf("\n Espacio [%d]= %d",i,arreglo_dinamico[i]);
		if(i==0){
			printf("El primer numero es: %d",arreglo_dinamico[i]);
		}
			
		}t1 = clock();
		printf("\nEl ultimo numero es: %d",arreglo_dinamico[n-1]);
		
	}
	
	
	
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	printf("\nEl tiempo de ejecucion es: %lfs",time);

	return 0;
}
