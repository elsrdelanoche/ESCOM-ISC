

#include<bits/stdc++.h>
using namespace std;
int *euclidesExtendidoMCD(int a, int b);
int inversoMultiplicativo(int a, int z);
char *preMatriz(char *clave,char *letras,char *textCpy);
void ingresarMatriz(int d,int M[][100]);
void mostrarMatriz(int d, int M[][100]);
void multiplicarMatriz(int M[][100],int P[][100], int C[][100], int m,int p,int n);
int subMatriz(int i, int j, int M[][100],int temp[][100],int d);
int determinanteMatriz(int M[][100],int d);
void algoCifradoHill(char *text, int M[][100], int d);
void desencriHill(char *text, int M[][100], int d);
char *agrupar(char *text,char *textAgru,int d);
bool comparar(char *clave,char a,int k);
int *euclidesExtendidoMCD(int a, int b){
 
 int d,x,y;
 int x1,x2,y1,y2;
 int q,r;
 int *rpts=new int[3];
 
 if(b==0){
  d=a;
  x=1;
  y=0; 
  
  rpts[0]=d; rpts[1]=x; rpts[2]=y;
  return rpts;
 }
 x1=0; x2=1;
 y1=1; y2=0; 
 while(b >0){
  q=(a/b); r=a-q*b;
  x=x2-q*x1; y=y2-q*y1;
  a=b; b=r;
  x2=x1; x1=x;
  y2=y1; y1=y;    
 }
 //d=a;
 rpts[0]=a; rpts[1]=x2; rpts[2]=y2;
 
 return rpts;
}

int inversoMultiplicativo(int a, int z){
 
 int *resp;
 int inver;     
 
 resp=euclidesExtendidoMCD(a,z);
 
 if(resp[0]==1){
  if(resp[1]< 0)
   inver=z+resp[1];
  else if(resp[1] >0)
   inver=resp[1];    
  delete(resp);
  return inver;
 }       
 else {            
  delete(resp);
  return -1;
 }
 
}

void ingresarMatriz(int d,int M[][100]){
 
 cout<< "\n";
 for(int i=0;i< d;i++)
  for(int j=0;j< d;j++){
   do{
    
    cout<< "\t\tMatriz ["<< i+1<< "]["<< j+1<< "]: ";
    cin >>M[i][j];
    if(M[i][j]< 0 || M[i][j] >25){
     cout<< "\n\t\tDebe ingresar los numeros en el rango de 0 a 25\n";
    }
    
   }while(M[i][j]< 0 || M[i][j] >25);   
   
  }
 
}

void mostrarMatriz(int d, int M[][100]){
 
 for(int i=0;i< d;i++){
  cout<< "|";
  for(int j=0;j< d;j++)
   cout<< M[i][j]<< " ";
  cout<< "|\n";
 }
}

void multiplicarMatriz(int M[][100],int P[][100], int C[][100], int m,int p,int n){
 int s;  
 
 for (int i=0;i< m;i++){
  for(int j=0;j< n;j++){
   s=0;          
   for(int k=0;k< p;k++){
    s+=M[i][k]*P[k][j];
   }
   C[i][j]=s;
  }
 }
}

int subMatriz(int i, int j, int M[][100],int temp[][100],int d){
 
 int fil=0;
 int col=0;
 
 for(int k=0;k< d;k++){
  if(k!=i){
   col=0;
   for(int l=0;l< d;l++){
    if(l!=j){
     temp[fil][col]=M[k][l];
     col++;
    }
    
   }
   fil++;   
  }
  
 }
 return determinanteMatriz(temp,d-1);
}
int determinanteMatriz(int M[][100],int d){
 
 int temp[100][100];
 
 if(d==2){
  int deter=M[0][0]*M[1][1]-M[1][0]*M[0][1]; 
  
  return deter;
 }else{
  int deter=0;
  
  for(int j=0;j< d;j++){      
   subMatriz(0,j,M,temp,d);
   deter=deter+pow(-1,0+j)*M[0][j]*determinanteMatriz(temp,d-1);
   
  }
  
  return deter;
 }
 
}
bool comparar(char *clave,char a,int k){
 
 for(int i=0;i< k;i++){
  if(clave[i]==a)
   return false;
 }
 
 return true;
}

char *preMatriz(char *clave,char *letras,char *textCpy){
 
 int k=0,i=0; 
 bool band=true;  
 
 while(k< 25){  
  
  if(clave[k]=='j')
   clave[k]='i'; 
  
  if(clave[k]!='\0' && band==true){ 
   if(clave[k]!=' ' && clave[k] >96 && clave[k]< 123){      
    if(comparar(clave,clave[k],k)){
     textCpy[i]=clave[k];
     i++;                          
    }  
   }
  }
  else{
   if(band==true)
    k=0;
   band=false;
   if(comparar(textCpy,letras[k],i)){
    textCpy[i]=letras[k];
    i++;                          
   }
  }     
  
  k++;
 }
 textCpy[25]='\0';
 //cout<< "i: "<< i;
 return textCpy;
}

void algoCifradoHill(char *text, int M[][100], int d){
 
 char textAgru[500]; 
 
 int P[100][100],p=0;
 int C[100][100];
 int inver,deter,verfInver;
 int k=0,m=0,ini=0,tam;
 
 deter=determinanteMatriz(M,d)%26; 
 
 if(deter< 0){
  verfInver=deter+26;
  //cout<< "\n\t\tDeterminante: "<< verfInver << "\n";
 }
 else{ 
  verfInver=deter;
  //  cout<< "\n\t\tDeterminante: "<< verfInver << "\n";
 }
 inver=inversoMultiplicativo(verfInver,26); 
 //cout<< "\n\t\tinverso("<< verfInver << ",26) = "<< inver << "\n";
 
 if(deter!=0 && inver!=-1){
  strcpy(textAgru,agrupar(text,textAgru,d));
  
  tam=strlen(textAgru);
  
  cout<< "\n\t\tTexto: "<< textAgru;
  
  while(k<=tam){   
   
   if(p< d){          
    P[p][0]=textAgru[k]-97; 
    //cout<< P[p][0]<< " " ;
    p++; 
   }else{      
    multiplicarMatriz(M,P,C,d,p,1);
    for(int i=ini;i< k;i++){
     textAgru[i]=(C[m][0]%26)+97;    
     m++;
     
    }            
    ini=k+1;
    m=0;
    p=0;
    
   }  
   k++;
  }
  
  cout<< "\n\t\tTexto Encriptado: "<< textAgru;
 }else
  cout<< "\n\t\tCon la clave matrices ingresada no se puede encriptar el mensaje";
 
}

void desencriHill(char *text, int M[][100], int d){
 
 int inver,deter,verfInver; 
 int resul,tam,ini=0,p=0,k=0,m=0;
 
 int P[100][100];
 int C[100][100]; 
 int A[100][100];
 int temp[100][100];
 
 deter=determinanteMatriz(M,d)%26; 
 
 if(deter< 0){
  verfInver=deter+26;
  cout<< "\n\t\tDeterminante: "<< verfInver<< "\n";
 }
 else{ 
  verfInver=deter;
  cout<< "\n\t\tDeterminante: "<< verfInver<< "\n";
 }
 inver=inversoMultiplicativo(verfInver,26); 
 cout<< "\n\t\tinverso("<< verfInver<< ",26) = "<< inver<< "\n";
 
 if(deter!=0 && inver!=-1){
  
  for(int i = 0; i <  d; i++) 
   for(int j = 0; j <  d ;j++)               
    A[j][i] = pow(-1,i+j)*subMatriz(i,j,M,temp,d);
  
  for(int i = 0; i <  d; i++){    
   for(int j = 0; j <  d ;j++){
    resul=A[i][j]*inver;             
    if(resul< 0)
     A[i][j]=(resul%26)+26;
    else   
     A[i][j]=resul%26;
   }               
   
  } 
  tam=strlen(text); 
  
  cout<< "\n\t\tTexto: "<< text;
  
  while(k<=tam){   
   
   if(p< d){          
    P[p][0]=text[k]-97; 
    //cout<< P[p][0]<< " " ;
    p++; 
   }else{      
    multiplicarMatriz(A,P,C,d,p,1);
    for(int i=ini;i< k;i++){
     text[i]=(C[m][0]%26)+97;    
     m++;
     
    }            
    ini=k+1;
    m=0;
    p=0;
    
   }  
   k++;
  }
  
  cout<< "\n\t\tTexto Desencriptado: "<< text;
  
  
 }else
  {cout<< "\n\t\tCon la clave matrices ingresada no se puede desencriptar el mensaje";}
 cout<< endl;
 system("pause");
 
 
}
char *agrupar(char *text,char *textAgru,int d){
 
 int k=0,i=0;
 int cont=0;
 
 
 while(text[k]!='\0'){
  
  if(text[k]!=' '){
   if(cont!=d){
    textAgru[i]=text[k];
    cont++;
    i++;
   }
   else{         
    textAgru[i]=' ';
    textAgru[i+1]=text[k];
    i+=2;
    cont=1;
   }
   
  } 
  k++; 
 }
 
 while(cont< d){
  textAgru[i]='x';
  cont++;
  i++;
 }
 textAgru[i]='\0';
 
 return textAgru;
}

int main(int argc, char *argv[]) {
 char text[500];
 int M[100][100];
 int d;   
 int opcion;
 while(1)
 {
  system("cls");
  cout<< "\n\t\t\tALGORITMOS DE ENCRIPTACION HILL\n";
  cout<< "1. ENCRRIPTAR\n";
  cout<< "2. DESENCRRIPTAR\n";
  cout<< "INGRESE OPCION: ";
  cin >>opcion;
  switch(opcion)
  {
   case 1:
   {
    system("cls");
    cout<< "\n\t\t\tALGORITMOS DE ENCRIPTACION HILL - ENCRIPTACION\n";
    cout<< "\n\t\tINGRESE TEXTO: ";
    fflush(stdin);
    gets(text);
    strcpy(text,strlwr(text));
    cout<< "\n\t\tINGRESE TAMAÑO DE MATRIZ DXD: ";
    cin >>d; 
    ingresarMatriz(d,M);
    algoCifradoHill(text,M,d);
    cout<< endl;
    system("pause");
    break;
   }
   case 2:
   {
    system("cls");
    cout<< "\n\t\t\tALGORITMOS DE ENCRIPTACION HILL - DESENCRIPTACION\n";
    cout<< "\n\t\tINGRESE TEXTO: ";
    fflush(stdin);
    gets(text);
    strcpy(text,strlwr(text));
    cout<< "\n\t\tINGRESE TAMAÑO DE MATRIZ DXD: ";
    cin >>d; 
    ingresarMatriz(d,M);
    desencriHill(text,M,d);
    cout<< endl;
    system("pause");
    break; 
   }
  }
 }
 return 0;
}