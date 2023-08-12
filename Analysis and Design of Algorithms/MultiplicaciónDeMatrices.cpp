//Alumno: Alfredo Bautista Ríos
#include <bits/stdc++.h>
#define N 100
using namespace std;
//Prototipos
void evaluar(int columA, int filasB);
void leer_matriz(int A[N][N],int filas,int columnas);
void imprimir_matriz(int A[N][N],int filas,int columnas);
void multiplicar(int A[N][N], int B[N][N],int C[N][N],int m, int r, int n);

int main(){
    int m,r,r1,n;
    int A[N][N],B[N][N],C[N][N];
    cout<<"Datos de matriz A"<<endl;
    cout<<"Filas: "; cin>>m;
    cout<<"Columnas: "; cin>>r;
    leer_matriz(A,m,r);
    cout<<"Datos de matriz B"<<endl;
    cout<<"Filas: "; cin>>r;//debe ser el mismo numero que columnas en A
    cout<<"Columnas: "; cin>>n;
    evaluar(r,r1);
    leer_matriz(B,r,n);
    cout<<"Matriz A:"<<endl;
    imprimir_matriz(A,m,r);
    cout<<"Matriz B:"<<endl;
    imprimir_matriz(B,r,n);
    multiplicar(A,B,C,m,r,n);
    cout<<"Matriz C:"<<endl;
    imprimir_matriz(C,m,n);
}

void evaluar(int columA, int filasB){
if(columA!=filasB){
        cout<<"No es posible realizar la operacion"<<endl;
        cout<<"El numero de columnas en A y filas en B debe ser el mismo"<<endl;
        exit(0);
    }
}
void leer_matriz(int A[N][N],int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<"Ingresa ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>A[i][j];
        }
    }
}
void imprimir_matriz(int A[N][N],int filas,int columnas){
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<A[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}
void multiplicar(int A[N][N], int B[N][N],int C[N][N],int m, int r, int n){
    //Preparar C
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            C[i][j]=0;
        }
    }
    //Multiplicar
    for(int i=0;i<m;i++){
        for(int j=0;j<r;j++){
            for(int k=0;k<n;k++){
                C[i][k]=C[i][k]+A[i][j]*B[j][k]; 
            }
        }
    }
}
