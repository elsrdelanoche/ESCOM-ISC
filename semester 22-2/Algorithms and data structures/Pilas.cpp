#include<bits/stdc++.h>
using namespace std;
struct nodo{
    int valor;
    nodo*anterior;
};
typedef nodo*apuntador;
int main(){
    int opc,dato;
    apuntador tope=NULL, auxiliar=NULL;
    do{
        cout<<"Seleccione una opcion para la pila: "<<endl;
        cout<<"1.Agregar\n2.Extraer\n3.Ver\n4.Salir\nOpcion: ";
        cin>>opc;
        switch(opc){
            case 1: //Agregar
                    cout<<"Ingrese dato: ";
                    cin>>dato;
                    auxiliar=new(nodo);
                    auxiliar->valor=dato;
                    cout<<"Dato ingresado correctamente :)"<<endl;
                    auxiliar->anterior=tope;
                    tope=auxiliar;
                      system("pause");
                    break;
            case 2: //Sacar
                    auxiliar=tope;
                    tope=tope->anterior;
                    delete(auxiliar);
                    cout<<"EL tope ha sido sacado :)"<<endl;
                    system("pause");
                    break;
            case 3: //Ver
                    auxiliar=tope;
                    while(auxiliar!=NULL){
                        cout<<"|"<<auxiliar->valor<<"|"<<endl;
                        auxiliar=auxiliar->anterior;
                    }
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