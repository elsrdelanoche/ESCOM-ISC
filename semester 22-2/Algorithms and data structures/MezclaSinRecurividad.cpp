//Un programa de Alfredo Bautista 2CV3
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tamano;
    printf("Ingrese el tamano del arreglo: ");  //Entrada de datos
    scanf("%d",&tamano);
    long int *arreglo_principal;
	arreglo_principal=(long int *) malloc(tamano*sizeof(long int));  //memory allocation
	if (arreglo_principal==NULL) 
		printf("�No se pudo reservar la memoria!\n"); 
	else{
        srand(time(NULL));
        printf("El arreglo generado es:\n"); 
        for(long int i=0;i<tamano;i++){
			arreglo_principal[i]=1+rand()%(tamano);
            printf("%ld ",arreglo_principal[i]); //Mostrar datos generados
        }
        printf("\n");
    }
    
    int n_unidades=0;   //mezcla
    int mitadI[tamano/2],mitadD[tamano-tamano/2];
    int izq=0,der=0;
    while (n_unidades<tamano){              //mientras se llegue a N unidades
        for(int i=0;i<(tamano/2);i++){      //Lado izquierdo
            mitadI[izq]=arreglo_principal[i];
            for(int j=0;j<i;j++){
                if(mitadI[j]>mitadI[i]){    //Se evaluaran el mayor y el menor entre 2 unidades
                swap(mitadI[j],mitadI[i]);
                }
            }
            izq++;
            n_unidades++;
        }
        int k=0;
        for(int i=(tamano/2);i<tamano;i++){ //Lado derecho
            mitadD[der]=arreglo_principal[i];
            for(int j=0;j<k;j++){
                if(mitadD[j]>mitadD[k]){    //Se evaluaran el mayor y el menor entre 2 unidades
                swap(mitadD[j],mitadD[k]);
                }
            }
            k++;
            der++;
            n_unidades++;
        }
    }
    
    printf("Mitad Izquierda:\n");   //Imprimir mitad izquierda
        for(int i=0;i<tamano/2;i++){
            printf("%d ",mitadI[i]);
        }
    printf("\nMitad derercha:\n");  //Imprimir mitad derecha
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

    int p=0,q=0,r=0;
    int arreglo_final[tamano];      //Mezcla de mitades
    while(r<tamano){
            if(mitadI[p]<=mitadD[q]&&p<tamano/2&&q<(tamano-tamano/2)){
               arreglo_final[r]=mitadI[p];
               p++;
               r++;
            }
           else{
               arreglo_final[r]=mitadD[q];
               q++;
               r++;
           } 
    }
    arreglo_final[tamano-1]=max(mitadI[(tamano/2)-1],mitadD[(tamano/2)+1-1]);
    arreglo_final[tamano-2]=min(mitadI[(tamano/2)-1],mitadD[(tamano/2)+1-1]);
    printf("\nArreglo final:\n");   //Mostrar
    for(int i=0;i<tamano;i++){
        printf("%d ",arreglo_final[i]);
    }
    return 0;
}