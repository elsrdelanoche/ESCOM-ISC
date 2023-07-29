//Archivos de cabecera
#include<stdio.h>
#include<math.h>

//Prototipos de funciones
float formula1(float A, float B, float C, float D, float E, float F, float G, float H);
float formula2(float A, float B, float C, float D, float E, float F, float G, float H);
float formula3(float A, float B, float C, float D, float E, float F, float G, float H);
float formula4(float A, float B, float C, float D, float E, float F, float G, float H);
float VA(void);
float VB(void);
float VC(void);
float VD(void);
float VE(void);
float VF(void);
float VG(void);
float VH(void);
void mostrarResul(float X1,float X2, float Y1, float Y2);
float A (void);
float B (void);
float C (void);
float D (void);
float E (void);
float F (void);
float G (void);
float H (void);

//Funcion principal
void main(){
	float A,B,C,D,E,F,G,H,X1,X2,Y1,Y2;
	A = VA();
	B = VB();
	C = VC();
	D = VD();
	E = VE();
	F = VF();
	G = VG();
	H = VH();
	X1 = formula1(A,B,C,D,E,F,G,H);
	X2 = formula2(A,B,C,D,E,F,G,H);
	Y1 = formula3(A,B,C,D,E,F,G,H);
	Y2 = formula4(A,B,C,D,E,F,G,H);
	mostrarResul(X1,X2,Y1,Y2);
}

//Cuerpo de las funciones
float formula1(float A, float B, float C, float D, float E, float F, float G, float H){
	float a,b,c,x1;
	a= (D+(E*(pow(A,2))/(pow(B,2))));
	b= (F-((2*C*A*E)/(pow(B,2)))-(G*A/B));
	c= ((E*(pow(C,2))/pow(B,2))+(G*C/B)+H);

	 x1 = (-b + (sqrt(b * b - 4 * a * c)) / (2 * a));  
	return x1;
}
float formula2(float A, float B, float C, float D, float E, float F, float G, float H){
	float a, b,c,x2;
	a= (D+(E*(pow(A,2))/(pow(B,2))));
	b= (F-((2*C*A*E)/(pow(B,2)))-(G*A/B));
	c= ((E*(pow(C,2))/pow(B,2))+(G*C/B)+H);

	 x2 = (-b - (sqrt(b * b - 4 * a * c)) / (2 * a)); 
	return x2;
}

float formula4(float A, float B, float C, float D, float E, float F, float G, float H){
	float a,b,c,y2;
	a= (E+(D*(pow(B,2))/(pow(A,2))));
	b= (G-((2*D*B*C)/(pow(A,2)))-(F*B/A));
	c= ((D*(pow(C,2))/pow(A,2))+(F*C/A)+H);

	 y2 = ((-b + (sqrt(b * b - 4 * a * c))) / (2 * a));  
	return y2;
}
float formula3(float A, float B, float C, float D, float E, float F, float G, float H){
	float a, b,c,y1;
	a= (((D*(pow(B,2)))/pow(A,2))+E);
	b= ((G-(2*D*B*C)/pow(A,2))-((F*B)/A));
	c= (((D*(pow(C,2))/pow(A,2))+(F*C/A)+H));

	 y1 = ((-b - (sqrt(b * b - 4 * a * c))) / (2 * a)); 
	return y1;
}
float VA(void){
	float x;
	printf("Introduzca el valor A: \n");
	scanf("%f",&x);
	return x;
}

float VB(void){
	float x;
	printf("Introduzca el valor B: \n");
	scanf("%f",&x);
	return x;
}
float VC(void){
	float x;
	printf("Introduzca el valor C: \n");
	scanf("%f",&x);
	return x;
}
float VD(void){
	float x;
	printf("Introduzca el valor D: \n");
	scanf("%f",&x);
	return x;
}
float VE(void){
	float x;
	printf("Introduzca el valor E: \n");
	scanf("%f",&x);
	return x;
}
float VF(void){
	float x;
	printf("Introduzca el valor F: \n");
	scanf("%f",&x);
	return x;
}
float VG(void){
	float x;
	printf("Introduzca el valor G: \n");
	scanf("%f",&x);
	return x;
}
float VH(void){
	float x;
	printf("Introduzca el valor H: \n");
	scanf("%f",&x);
	return x;
}
void mostrarResul(float X1, float X2, float Y1, float Y2){
	printf("X1:  %f\n",X1);
	printf("X2: %f\n",X2);
	printf("Y1: %f\n",Y1);
	printf("Y2: %f\n",Y2);
}
