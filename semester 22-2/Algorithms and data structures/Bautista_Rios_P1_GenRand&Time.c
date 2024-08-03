//Un programa de Bautista Ríos Alfredo 2CV3
//Archivos de programa
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//Funcion principal
int main(){
    int num,numero;
    printf("Se generaran dos numeros aleatorios.\n");
    printf("Con rand: ");
    printf(" %d ", rand());
    printf("\nCon srand: ");
    srand(time(0));
    printf("%d",rand()%(100-(0+1))+0);

    printf("\nCuantos numeros aleatorios quiere generar?: ");
    scanf("%d",&num);
    srand(time(0));
    for(int i=0;i<num;i++){
        printf("%d\n",rand());
    }
    printf("Desea generar numeros (0.pares/1.impares): ");
    scanf("%d",&numero);
    switch(numero){
        case 0:
            for (int i=0 ; i<num ; i++){
                printf( "%d\n",(rand()*2));
                }
            break;
        case 1:
            for (int j = 0; j<num ; j++){
                printf("%d\n",(rand()*2)-1);
            }
    }
    printf("Fin del programa.");
    return 0;
}
