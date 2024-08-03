///Un programa de Alfredo Bautista 2CV3
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;

int main(){
	int *arreglo_dinamico;
    char opc;
	int n=9999,num,aux,busq;
	arreglo_dinamico=(int *) malloc(n*sizeof(int));  //memory allocation
	if (arreglo_dinamico==NULL) 
	printf("No se pudo reservar la memoria!\n"); 
	else{
	    printf("Digite la cantidad de numeros aleatorios a generar: ");
	    scanf("%i",&num);
	    srand(time(0));
		for(int i=0;i<num;i++){
			arreglo_dinamico[i]=1+rand()%(9999);
		for(int j=0;j<i;j++){
		    while(arreglo_dinamico[i]==arreglo_dinamico[j]){
		    	srand(time(0));
		        arreglo_dinamico[i]=1+rand()%(9999);
		    }
		}
		}   
	    printf("Desea mostrar el arreglo generado?(S/N): ");
	    cin>>opc;
	    switch(opc){
	    	case 'S':
	    	case 's':
	    		for(int i=0;i<num;i++){
	            printf("%d  ",arreglo_dinamico[i]);
	        	}
	        break;
		}
		printf(" \n");
	    printf("Ordenando el arreglo... \n");
	    	//Ordenar
	        for(int i=0;i<num-1;i++){
	        	for(int j=0;j<num-1;j++){
	           		if(arreglo_dinamico[j]>arreglo_dinamico[j+1]){
		            	aux=arreglo_dinamico[j];
		            	arreglo_dinamico[j]=arreglo_dinamico[j+1];           
		            	arreglo_dinamico[j+1]=aux;
	           		}
	          	}
	        }
	        printf("Desea mostrar el arreglo ordenado?(S/N): ");
	        cin>>opc;
	        if(opc=='S'||opc=='s'){
	            for(int i=0;i<num;i++){
	                printf("%d  ",arreglo_dinamico[i]);
	            }
	        }
	    int b,i,j,k;    
		printf("\nIngrese numero a buscar: ");
	    scanf("%d",&b);
	    
	    i=0;
	    j=num-1;
	    do{
	        k=(i+j)/2;
	        if(arreglo_dinamico[k]<=b){
	            i=k+1;
	        }
	        if(arreglo_dinamico[k]>=b){
	            j=k-1;
	        }
	    }while(i<=j);
	    printf("\nElemento %d esta en %d\n",arreglo_dinamico[k],k);	
	}
	return 0;  
}
