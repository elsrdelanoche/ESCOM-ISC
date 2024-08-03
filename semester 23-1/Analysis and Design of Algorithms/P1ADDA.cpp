//Alfredo Bautista Ríos
//Analisis y diseño de algoritmos
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
using namespace std;

static void tradicional(float* matA,float* matB,float* matC,const int M,const int N,const int K){
	for (int i = 0; i < M;i++){
		for (int j = 0; j < N;j++){
			float sum = 0.0f;
			for (int k = 0; k < K;k++){
				sum += matA[i*K + k] * matB[k*N + j];
			} 
			matC[i*N + j] = sum;
		}
	}
}

static void mostrarMatrix(float* C, int M, int N){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            printf("%.0f\t",C[i*N + j]);
        }
        printf("\n");
    }
	printf("\n");
}

static void mm_strassen(float* matA, float* matB, float* matC, const int M, const int N, const int K){
	if ((M <= 2) || M%2 != 0 || N%2 != 0 || K%2!=0){
		return tradicional(matA, matB, matC, M, N, K);
	}

	int offset = 0;
	//M1 = (A11+A22)*(B11+B22)
	float* M1 = (float*) malloc((M/2) * (N/2) * sizeof(float));
	{
		//M1_0 = (A11+A22)
		float * M1_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		offset = M*K / 2 + K / 2;
		for (int i = 0; i < M / 2; i++){
			for (int j = 0; j < K/2; j++){
				const int baseIdx = i*K + j;
				M1_0[i*K/2+j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M1_1 = (B11+B22)
		float* M1_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = K*N / 2 + N / 2;
		for (int i = 0; i < K / 2; i++){
			for (int j = 0; j < N / 2; j++){
				const int baseIdx = i*N + j;
				M1_1[i*N/2+j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		mm_strassen(&M1_0[0], &M1_1[0], &M1[0], M / 2, N / 2, K / 2);

		free(M1_0);         M1_0=NULL;
		free(M1_1);         M1_1=NULL;
	}

	//M2 = (A21+A22)*B11
	float* M2 = (float*) malloc((M/2) * (N/2) * sizeof(float));{
		//M2_0 = (A21+A22)
		float* M2_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		offset = K / 2;
		for (int i = M / 2; i < M; i++){
			for (int j = 0; j < K / 2; j++){
				const int baseIdx = i*K + j;
				M2_0[(i-M/2)*K/2+j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M2_1 = B11
        float* M2_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
        for(int i = 0; i < K / 2; i++) {
            for(int j = 0; j < N / 2; j++){
                M2_1[i * N/2 + j] = matB[i * N + j];
            }
        }
		mm_strassen(&M2_0[0], &M2_1[0], &M2[0], M / 2, N / 2, K / 2);

		free(M2_0);         M2_0=NULL;
		free(M2_1);         M2_1=NULL;
	}

	//M3 = A11*(B12-B22)
	float* M3 = (float*) malloc((M/2) * (N/2) * sizeof(float));
	{
		//M3_0 = A11
		float* M3_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		for(int i = 0; i < M / 2; i++){
            for(int j = 0; j < K / 2; j++){
                M3_0[i * K/2 + j] = matA[i * K + j];
            }
		}
		//M3_1 = (B12-B22)
		float* M3_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = K*N / 2;
		for (int i = 0; i < K/2; i++){
			for (int j = N/2; j < N; j++){
				const int baseIdx = i*N + j;
				M3_1[i*N/2+j-N/2] = matB[baseIdx] - matB[baseIdx + offset];
			}
		}
		mm_strassen(&M3_0[0], &M3_1[0], &M3[0], M / 2, N / 2, K / 2);

		free(M3_0);         M3_0=NULL;
		free(M3_1);         M3_1=NULL;
	}

	//M4 = A22*(B21-B11)
	float* M4 = (float*) malloc((M/2) * (N/2) * sizeof(float));{
		//M4_0 = A22
		float* M4_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		for(int i = M / 2; i < M; i++){
            for(int j = K / 2; j < K; j++){
                M4_0[(i-M/2) * K/2 + j - K/2] = matA[i * K + j];
            }
		}
		//M4_1 = (B21-B11)
		float* M4_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = N*K/2;
		for (int i = 0; i < K / 2; i++){
			for (int j = 0; j < N/2; j++){
				const int baseIdx = i*N + j;
				M4_1[i*N/2 + j] = matB[baseIdx + offset] - matB[baseIdx];
			}
		}
		mm_strassen(&M4_0[0], &M4_1[0], &M4[0], M / 2, N / 2, K / 2);

		free(M4_0);         M4_0=NULL;
		free(M4_1);         M4_1=NULL;
	}

	//M5 = (A11+A12)*B22
	float* M5 = (float*) malloc((M/2) * (N/2) * sizeof(float));
	{
		//M5_0 = (A11+A12)
		float* M5_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		offset = K / 2;
		for (int i = 0; i < M/2; i++){
			for (int j = 0; j < K / 2; j++){
				const int baseIdx = i*K + j;
				M5_0[i*K / 2 + j] = matA[baseIdx] + matA[baseIdx + offset];
			}
		}
		//M5_1 = B22
		float* M5_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = N*K/2 + N/2;
		for(int i = 0; i < K / 2; i++){
            for(int j = 0; j < N / 2; j++){
                M5_1[i * N/2 + j] = matB[i * N + j + offset];
            }
		}
		mm_strassen(&M5_0[0], &M5_1[0], &M5[0], M / 2, N / 2, K / 2);

		free(M5_0);         M5_0=NULL;
		free(M5_1);         M5_1=NULL;
	}

	//M6 = (A21-A11)*(B11+B12)
	float* M6 = (float*) malloc((M/2) * (N/2) * sizeof(float));
	{
		//M6_0 = (A21-A11)
		float* M6_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		offset = K * M / 2;
		for (int i = 0; i < M / 2; i++){
			for (int j = 0; j < K/2; j++){
				const int baseIdx = i*K + j;
				M6_0[i*K/2+j] = matA[baseIdx + offset] - matA[baseIdx];
			}
		}
		//M6_1 = (B11+B12)
		float* M6_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = N / 2;
		for (int i = 0; i < K / 2; i++){
			for (int j = 0; j < N/2; j++){
				const int baseIdx = i*N + j;
				M6_1[i*N/2+j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		mm_strassen(&M6_0[0], &M6_1[0], &M6[0], M / 2, N / 2, K / 2);

		free(M6_0);         M6_0=NULL;
		free(M6_1);         M6_1=NULL;
	}

	//M7 = (A12-A22)*(B21+B22)
	float* M7 = (float*) malloc((M/2) * (N/2) * sizeof(float));
	{
		//M7_0 = (A12-A22)
		float* M7_0 = (float*) malloc((M/2) * (K/2) * sizeof(float));
		offset = M*K / 2;
		for (int i = 0; i < M / 2; i++){
			for (int j = K/2; j < K; j++){
				const int baseIdx = i*K + j;
				M7_0[i*K / 2 + j - K / 2] = matA[baseIdx] - matA[baseIdx + offset];
			}
		}
		//M7_1 = (B21+B22)
		float* M7_1 = (float*) malloc((K/2) * (N/2) * sizeof(float));
		offset = N / 2;
		for (int i = K/2; i < K; i++){
			for (int j = 0; j < N / 2; j++){
				const int baseIdx = i*N + j;
				M7_1[(i-K/2)*N / 2 + j] = matB[baseIdx] + matB[baseIdx + offset];
			}
		}
		mm_strassen(&M7_0[0], &M7_1[0], &M7[0], M / 2, N / 2, K / 2);

		free(M7_0);         M7_0=NULL;
		free(M7_1);         M7_1=NULL;
	}

	for (int i = 0; i < M / 2;i++){
		for (int j = 0; j < N / 2;j++){
			const int idx = i*N / 2 + j;
			//C11 = M1+M4-M5+M7
			matC[i*N + j] = M1[idx] + M4[idx] - M5[idx] + M7[idx];
			//C12 = M3+M5
			matC[i*N + j + N/2] = M3[idx] + M5[idx];
			//C21 = M2+M4
			matC[(i+M/2)*N + j] = M2[idx] + M4[idx];
			//C22 = M1-M2+M3+M6
			matC[(i+M/2)*N + j + N/2] = M1[idx] - M2[idx] + M3[idx] + M6[idx];
		}
	}
	free(M1);           M1=NULL;
	free(M2);           M2=NULL;
	free(M3);           M3=NULL;
	free(M4);           M4=NULL;
	free(M5);           M5=NULL;
	free(M6);           M6=NULL;
	free(M7);           M7=NULL;
}

static void tradicional(float* matA, float* matB, float* matC, const int M, const int N, const int K,
                        const int strideA, const int strideB, const int strideC){
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            float sum = 0.0f;
            for(int k = 0; k < K; k++){
                sum += matA[i*strideA + k] * matB[k*strideB + j];
            }
            matC[i*strideC + j] = sum;
        }
    }
}

//Funcion de testeo
static void mm_test(int M, int N, int K, int rangeTop,int testeos){
    unsigned seed = time(0);
    srand(seed);
    //Declarar variables de tiempo
    clock_t start,end;
    for(int i = 0; i < testeos; i++){
        float * mA = (float*) malloc(M*K*sizeof(float));
        float * mB = (float*) malloc(K*N*sizeof(float));
        float * mC = (float*) malloc(M*N*sizeof(float));
        float * mD = (float*) malloc(M*N*sizeof(float));
        float * mE = (float*) malloc(M*N*sizeof(float));
        
		for(int j = 0; j < M*K; j++){//Llenar AyB aleatoriamente
            mA[j] = rand() % rangeTop;
        }
		cout<<"Matriz A generada: "<<endl;
		mostrarMatrix(mA, M, K);
        for(int j = 0; j < K*N; j++){
            mB[j] = rand() % rangeTop;
        }
		cout<<"Matriz B generada: "<<endl;
		mostrarMatrix(mB, K, N);
		system("pause");system("cls");
        start = clock();
        mm_strassen(mA, mB, mC, M, N, K);
        end = clock();
		printf("========Strassen========\n");
        mostrarMatrix(mC, M, N);
        double endtime = (double) (end-start)/CLOCKS_PER_SEC;
        printf("%d Strassen \ttime: %.2fms\n", i+1, endtime*1000);

        start = clock();
        tradicional(mA, mB, mD, M, N, K);
        end = clock();
		printf("======Tradicional=======\n");
		mostrarMatrix(mD, M, N);
        endtime = (double) (end-start)/CLOCKS_PER_SEC;
        printf("%d Tradicional \ttime: %.2fms\n", i+1, endtime*1000);

        for(int j = 0; j < M*N; j++){
            if(mC[j] != mD[j] || mC[j] != mD[j]){
                printf("========A========\n");
                mostrarMatrix(mA, M, K);
                printf("========B========\n");
                mostrarMatrix(mB, K, N);
                printf("========Strassen========\n");
                mostrarMatrix(mC, M, N);
                printf("======Tradicional=======\n");
                mostrarMatrix(mD, M, N);
                return ;
            }
        }
        printf("\n");
    }
}

int main(){;
    int M, N, K, rangeTop=10,testeos;
    system("cls");
    cout<<"**********************Bienvenido*********************"<<endl;
    cout<<"Este programa comparara los tiempos de dos algoritmos"<<endl;
    cout<<"para multiplicacion de matrices:"<<endl;
    cout<<"1.ALgoritmo de Strassen\n2.Algoritmo tradicional"<<endl;
    system("pause");system("cls");
    //Solicitar dimensiones
    cout<<"Ingrese [FIL] de A: ";
    cin>>M;
    cout<<"Ingrese [COL] de A: ";
    cin>>K;
	cout<<"Ingrese [FIL] de B: ";
	cin>>K;
    cout<<"Ingrese [COL] de B: ";
    cin>>N;
    cout<<"Indique el numero de pruebas a realizar: ";
    cin>>testeos;


    system("cls");
    cout<<"Las dimensiones ingresadas son:"<<endl;
    cout<<"A=["<<M<<"]["<<N<<"] B=["<<N<<"]["<<K<<"]"<<endl;
    cout<<testeos<<" Ejecuciones."<<endl;
    system("pause");system("cls");
    mm_test(M, N, K, rangeTop,testeos);
    return 0;
}