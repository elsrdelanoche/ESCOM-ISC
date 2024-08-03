//T2-Analisis
//Alumno: Alfredo Bautista Ríos
#include <bits/stdc++.h>
#include <time.h>
using namespace std;
//Prototipos
void impresionArreglo(int arreglo[],int tamano);
void mergeSort(int arreglo[],int inicio, int final);
void merge(int arreglo[],int inicio, int mitad, int final);
void quickSort(int arr[], int start, int end);
int partition(int arr[], int start, int end);
void burbuja(int vector[],int tamano);
//cuerpo del programa
int main(){
    int tamano=20,t0,t1;
    float time;
    cout<<"Bienvenido a la tarea 2"<<endl;

    //Metodo mergeSort
    cout<<"\nMergeSort"<<endl;
    int RGA1[]={5,62,52,7,3,4,6,77,12,16,24,2,8,59,21,46,97,1,34,69};
    impresionArreglo(RGA1,tamano);
	t0=clock();
    cout<<"TIME"<<endl;
    cout<<t0<<endl;
    mergeSort(RGA1,0,tamano-1);
    t1=clock();
    cout<<t1<<endl;
    time = float(t1-t0)/CLOCKS_PER_SEC;
    impresionArreglo(RGA1,tamano);
    printf("El tiempo de ejecucion es: %f segundos\n",time);
    
    //Metodo de quicksort
    cout<<"\nQuickSort"<<endl;
    int RGA2[]={5,62,52,7,3,4,6,77,12,16,24,2,8,59,21,46,97,1,34,69};
    impresionArreglo(RGA2,tamano);
	t0=clock();
    cout<<"TIME"<<endl;
    cout<<t0<<endl;
    quickSort(RGA2, 0, tamano - 1);
    t1=clock();
    cout<<t1<<endl;
    time = float(t1-t0)/CLOCKS_PER_SEC;
    impresionArreglo(RGA2,tamano);
    printf("El tiempo de ejecucion es: %f segundos\n",time);

    //Metodo de burbuja
    cout<<"\nBurbuja"<<endl;
    int RGA3[]={5,62,52,7,3,4,6,77,12,16,24,2,8,59,21,46,97,1,34,69};
    impresionArreglo(RGA3,tamano);
	t0=clock();
    cout<<"TIME"<<endl;
    cout<<t0<<endl;
    burbuja(RGA3, tamano);
    t1=clock();
    cout<<t1<<endl;
    time = float(t1-t0)/CLOCKS_PER_SEC;
    impresionArreglo(RGA3,tamano);
    printf("El tiempo de ejecucion es: %f segundos\n",time);
    return 0;
}

void impresionArreglo(int arreglo[],int tamano){
    for(int i = 0; i < tamano; i++){
        cout << arreglo[i] << " ";
    }
    cout<<endl;
}
void mergeSort(int arreglo[],int inicio, int final){
    if(inicio < final){
        int mitad = inicio + (final - inicio)/2;
        mergeSort(arreglo,inicio,mitad);
        mergeSort(arreglo,mitad+1,final);
        merge(arreglo,inicio,mitad,final);
    }
}
void merge(int arreglo[],int inicio, int mitad, int final){
    int i,j,k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int>izquierda(elementosIzq);
    vector<int>derecha(elementosDer);

    for(int i = 0; i < elementosIzq; i++){
        izquierda[i] = arreglo[inicio+i];
    }
    for(int j = 0; j < elementosDer; j++){
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer){
        if(izquierda[i] <= derecha[j]){
            arreglo[k] = izquierda[i];
            i++;
        }else{
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j < elementosDer){
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while(i < elementosIzq){
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }

}
void quickSort(int arr[], int start, int end)
{
 
    // base case
    if (start >= end)
        return;
 
    // partitioning the array
    int p = partition(arr, start, end);
 
    // Sorting the left part
    quickSort(arr, start, p - 1);
 
    // Sorting the right part
    quickSort(arr, p + 1, end);
}
int partition(int arr[], int start, int end)
{
 
    int pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}
void burbuja(int vector[],int tamano){
    int i,j,temp;
    for (i = 0; i < tamano; ++i){
        for (j = 0; j < tamano; ++j){
            if (vector[j] > vector[j+1]){
                temp = vector[j];
                vector[j] = vector[j+1];
                vector[j+1] = temp;
            }
        }
    }
}
