//autor: Alfredo Bautista 2CV3
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void){
	clock_t t0, t1;
    int A[]={4,1,2,5,8,9,6,10,3,7};
    int i,j,aux;
	
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
    t1 = clock();
		
	double time = (double(t1-t0)/CLOCKS_PER_SEC);
	printf("\nEl tiempo de ejecucion es: %lfs",time);
    printf("\nEs posible realizar %lf procesos en 2 minutos.",(120/time));
	return 0;
}