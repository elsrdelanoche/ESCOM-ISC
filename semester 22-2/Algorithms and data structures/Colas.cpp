#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*anterior;
};
typedef nodo*apuntador;
int main(){
    int opc,dato;
    apuntador entrada=NULL,nuevo=NULL,salida=NULL,auxiliar=NULL;
    do{
        cout<<"Seleccione una opcion para la cola: "<<endl;
        cout<<"1.Agregar\n2.Extraer\n3.Ver\n4.Salir\nOpcion: ";
        cin>>opc;
        switch(opc){
            case 1: //Agregar
                    cout<<"Ingrese dato: ";
                    cin>>dato;
                    if(salida==NULL){
                        nuevo=new(nodo);
                        nuevo->valor=dato;
                        nuevo->anterior=NULL;
                        cout<<"Dato ingresado correctamente :)"<<endl;
                        entrada=nuevo;
                        salida=nuevo;
                    }
                    else{
                        nuevo=new(nodo);
                        nuevo->valor=dato;
                        nuevo->anterior=NULL;
                        entrada->anterior=nuevo;
                        cout<<"Dato ingresado correctamente :)"<<endl;
                        entrada=nuevo;
                    }
                    system("pause");
                    break;
            case 2: //Sacar
                    auxiliar=salida->anterior;
                    delete(salida);
                    cout<<"Salida extraida :)"<<endl;
                    salida=auxiliar;
                    system("pause");
                    break;
            case 3: //Ver
                    auxiliar=salida;
                    cout<<"Salida-> ";
                    while(auxiliar!=NULL){
                        cout<<auxiliar->valor;
                        auxiliar=auxiliar->anterior;
                        if(auxiliar!=NULL){
                            cout<<"-";
                        }
                    }
                    cout<<" <-Entrada"<<endl;
                    system("pause");
                    break;
            case 4://Salir
                    cout<<"Fin del programa, hasta luego :)"<<endl;
                    system("pause");
                    break;
 
            default: cout<<"Opcion no esta en el menu\n";
                    system("pause");
                    break;
        }
        system("cls");
    }while(opc!=4);

}