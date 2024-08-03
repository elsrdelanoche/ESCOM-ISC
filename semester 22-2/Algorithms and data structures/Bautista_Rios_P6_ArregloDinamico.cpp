//Un programa de Alfredo Bautista 2CV3
#include<bits/stdc++.h>
using namespace std;
int main(){
    //Entrada de datos
    int tamano;
    long int *arreglo_principal;
    printf("Ingrese el tamano del arreglo: ");
    scanf("%d",&tamano);
    arreglo_principal=(long int *) malloc(tamano*sizeof(long int));  //memory allocation

	if (arreglo_principal==NULL) 
		printf("�No se pudo reservar la memoria!\n"); 
	else
	{   
        srand(time(NULL));
		for(long int i=0;i<tamano;i++){
			arreglo_principal[i]=1+rand()%(tamano);
        }
	}

    //Mostrar datos generados
    printf("Arreglo generado:\n");
    for(int i=0;i<tamano;i++){
        printf("%d ",arreglo_principal[i]);
    }
    printf("\n");

    //mezcla
    int n_unidades=0;
    int mitadI[tamano/2],mitadD[tamano-tamano/2];
    int izq=0,der=0;
    while (n_unidades<tamano){
        //Lado izquierdo
        for(int i=0;i<(tamano/2);i++){
            mitadI[izq]=arreglo_principal[i];
            for(int j=0;j<i;j++){
                if(mitadI[j]>mitadI[i]){
                swap(mitadI[j],mitadI[i]);
                }
            }
            izq++;
            n_unidades++;
        }
        //Lado derecho
        int k=0;
        for(int i=(tamano/2);i<tamano;i++){
            mitadD[der]=arreglo_principal[i];
            for(int j=0;j<k;j++){
                if(mitadD[j]>mitadD[k]){
                swap(mitadD[j],mitadD[k]);
                }
            }
            k++;
            der++;
            n_unidades++;
        }
    }
    
    //Imprimir mitades
    printf("Mitad Izquierda:\n");
        for(int i=0;i<tamano/2;i++){
            printf("%d ",mitadI[i]);
        }
    printf("\nMitad derercha:\n");
    if(tamano%2==0){
        for(int i=0;i<tamano/2;i++){
            printf("%d ",mitadD[i]);
        }
    }
    else{
        for(int i=0;i<tamano/2+1;i++){
            printf("%d ",mitadD[i]);
        }
    }

    //Union de dos arreglos
    int p=0,q=0,r=0;
    int arreglo_final[tamano];
    
    while(r<tamano){
            if(mitadI[p]<mitadD[q]&&p<(tamano/2)&&q<(tamano-tamano/2)){
               arreglo_final[r]=mitadI[p];
               p++;
            }
           else{
                 if(p<(tamano/2)&&q<(tamano-tamano/2)){
                    arreglo_final[r]=mitadD[q];
                    q++; 
               }
               
           } 
       r++;
    }

    //Mostrar
    printf("\nArreglo final:\n");
    for(int i=0;i<tamano;i++){
        printf("%d ",arreglo_final[i]);
    }
    return 0;
}