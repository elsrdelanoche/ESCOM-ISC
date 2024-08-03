/*
ARCHIVO: Ordenamiento.cpp
VERSION: 1.0
PROGRAMADOR: Esponda Cervantes Alfredo Daniel
FECHA: 02/03/2022
DESCRIPCION: El programa genera y ordena una serie de numeros aletorios por diversos metodos.
*/

//directivas de preprocesador
#ifdef _WIN32
#define CLEAR "cls"
#else 
#define CLEAR "clear"
#endif

#include <iostream>
#include <ctime>
using namespace std;

//variables globales y prototipos de funcion
void Burbuja(int *Lista, int Max_Limite, int generada);
void Insercion(int *Lista, int Max_Limite, int generada);
void Seleccion(int *Lista, int Max_Limite, int generada);
void MergeSort(int *Lista, int Max_Limite, int generada);
void Merge(int *Lista,int Min_Limite,int Max_Limite,int Orden);
void SortMayor(int *Lista,int Min_Limite,int corte,int Max_Limite);
void Sortmenor(int *Lista,int Min_Limite,int corte,int Max_Limite);
void QuickSort(int *Lista, int Max_Limite, int generada);
void QuickSortingM(int *Lista,int Min_Limite,int Max_Limite);
void QuickSortingm(int *Lista,int Min_Limite,int Max_Limite);
void Esperar(){
#ifdef _WIN32
    system("PAUSE");
#else
  cout << "Presione una tecla para continuar . . .";
  cin.ignore();
  cin.get();
#endif
};

//funcin principal
int main(){
    //Variables locales
    int *Lista;
    delete Lista;
    bool generada= false;
    int Op = 0,Max_Limite;

    menu_principal:

    do{


        cout << "Bienvenido a Ordenamientos\n";
        cout << "Por favor elije una opcion valida \n";
        if(Op!=0)	system(CLEAR);

        cout << "\n1.Generacion de datos \n";
        cout << "2.Imprimir datos \n";
        cout << "3.Ordenamiento Burbuja \n";
        cout << "4.Ordenamiento por Insercion \n";
        cout << "5.Ordenamiento por Seleccion \n";
        cout << "6.Ordenamiento por MergeSort \n";
        cout << "7.Ordenamiento por QuickSort \n";
        cout << "8.Salir \n\n";
        cout<<"Opcion: ";
        cin >> Op;
        system(CLEAR);

        if(Op<1 || Op>8){

            cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
            Esperar();
        }

    }while(Op<1 || Op>8);

    switch(Op){

        case 1 : //Generar Datos
            repito:
            system(CLEAR);
            generada = false;
            delete Lista;
            cout << "Escriba la cantidad de numeros a generar: ";
            cin >> Max_Limite;
            if(Max_Limite<=0) {
              goto repito;
            }
            Lista = new int [Max_Limite];
            if (Max_Limite > 50001){
                cout << "\n\nEs mucha memoria, intenta otra cantidad\n\n";
                Esperar();
                goto repito;
              }

            if(Max_Limite<1000){
              for(int i=0;i<Max_Limite;i++){

                Lista[i]= rand()%201 -100;
              }
            }else{
              for(int i=0;i<Max_Limite;i++){

                Lista[i]= rand()%601 -300;
              }
            }


            cout << "\n\nLa lista de ";
            cout<< Max_Limite;
            cout<<" elementos se genero correctamente \n\n";
            generada = true;
            Esperar();

            goto menu_principal;
            break;

        case 2 : //Imprimir Datos           //Este codigo es propiedad de Alfredo Daniel Esponda Cervantes
            if(generada){
              cout<<"La lista de numeros es: ";

              for(int i=0;i<Max_Limite;i++){
                cout << Lista[i];
                if(i<Max_Limite) cout <<", ";
              }
              cout<<"\n\n";
              Esperar();
            }else{
              cout <<"Lo siento, primero debes generar la lista de numeros\n\n";
              Esperar();
            }

            goto menu_principal;
            break;

        case 3 : //Ordenamiento Burbuja

            Burbuja(Lista,Max_Limite,generada);
            goto menu_principal;
            break;

        case 4 : //Ordenamiento Insercion

            Insercion(Lista,Max_Limite,generada);
            goto menu_principal;
            break;

        case 5 : //Ordenamiento Seleccion

            Seleccion(Lista,Max_Limite,generada);
            goto menu_principal;
            break;

        case 6 : //Ordenamiento MergeSort

            MergeSort(Lista,Max_Limite,generada);
            goto menu_principal;
            break;

        case 7 : //Ordenamiento QuickSort

            QuickSort(Lista,Max_Limite,generada);
            goto menu_principal;
            break;

        case 8 : // Salir

            cout << "Hasta la proxima\n\n";
            cout << "Presione una tecla para salir . . .";
            cin.ignore();
            cin.get();

            break;

        default: //Error en la verificacion de [Op]
            cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
            Esperar();
            break;
    }



    return 0;
}

//funciones secundarias o funciones definidas por el usuario
void Burbuja(int *Lista, int Max_Limite, int generada){
  //Variables locales
  int Orden,aux;

  if(generada){

    do{

      cout<<"¿Como deseas ordenar la lista?\n\n";
      cout<<"1. Mayor a menor\n";
      cout<<"2.menor a Mayor\n\n";
      cout<<"Opcion: ";
      cin>> Orden;

      if(Orden<1 || Orden>2){
        cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
        Esperar();
      }
      system(CLEAR);
    }while(Orden<1 || Orden>2);

    if(Orden == 1 ){ //Mayor a menor

        for(int i = 0; i< Max_Limite; i++){
          for(int compara = 0; compara < Max_Limite-1; compara++){
            if(Lista[compara]<Lista[compara+1]){
                aux = Lista[compara+1];
                Lista[compara+1] = Lista[compara];
                Lista[compara]=aux;
            }
            if(Max_Limite<20){
              cout<<compara+(i*Max_Limite);                 //Este codigo es propiedad de Alfredo Daniel Esponda Cervantes
              cout<<".- ";
              for(int im= 0; im<Max_Limite;im++){
                cout<<" ";
                cout<<Lista[im];
                cout<<",";
              }
            cout<<"\n";
            }
          }
        }
        if(Max_Limite>=20){
          for(int im= 0; im<Max_Limite;im++){
            cout<<" ";
            cout<<Lista[im];
            cout<<",";
            }
          }

        cout << "\n\nSe Ordeno de Mayor a menor por metodo de Burbuja \n\n";
        Esperar();

    }else if(Orden ==2 ){ //menor a Mayor

      for(int i = 0; i< Max_Limite; i++){
        for(int compara = 0; compara <Max_Limite-1; compara++){
          if(Lista[compara]>Lista[compara+1]){
              aux = Lista[compara+1];
              Lista[compara+1] = Lista[compara];
              Lista[compara]=aux;
          }
          if(Max_Limite<20){
            cout<<compara+(i*Max_Limite);
            cout<<".- ";
            for(int im= 0; im<Max_Limite;im++){
              cout<<" ";
              cout<<Lista[im];
              cout<<",";
            }
          cout<<"\n";
          }
        }
      }
      if(Max_Limite>=20){
        for(int im= 0; im<Max_Limite;im++){
          cout<<" ";
          cout<<Lista[im];
          cout<<",";
          }
        }


      cout << "\n\nSe Ordeno de menor a Mayor por metodo de Burbuja \n\n";
      Esperar();

    }else{
      cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
      Esperar();
    }

  }else{
    cout <<"Losiento, primero debes generar la lista de numeros\n\n";
    Esperar();
  }

}

void Insercion(int *Lista, int Max_Limite, int generada){
  //Variables locales
  int dir,Orden,aux,contador= 0;

  if(generada){

    do{

      cout<<"¿Como deseas ordenar la lista?\n\n";
      cout<<"1. Mayor a menor\n";
      cout<<"2.menor a Mayor\n\n";
      cout<<"Opcion: ";
      cin>> Orden;

      if(Orden<1 || Orden>2){
        cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
        Esperar();
      }
      system(CLEAR);
    }while(Orden<1 || Orden>2);

    if(Orden == 1 ){ //Mayor a menor

      for(int i=0;i<Max_Limite;i++){

        dir=i;
        aux=Lista[i];
        while(dir>0 && Lista[dir-1]<aux){
          Lista[dir]= Lista[dir-1];
          dir--;

          if(Max_Limite<10){
            contador++;
            cout<<contador;
            cout<<".- ";
            for(int im= 0; im<Max_Limite;im++){
              cout<<" ";
              cout<<Lista[im];
              cout<<",";
            }
          cout<<"\n";
          }

        }
        Lista[dir]=aux;

        if(Max_Limite<20){
          contador++;
          cout<<contador;
          cout<<".- ";
          for(int im= 0; im<Max_Limite;im++){
            cout<<" ";
            cout<<Lista[im];
            cout<<",";
          }
        cout<<"\n";
        }

        }
        if(Max_Limite>=20){
          for(int im= 0; im<Max_Limite;im++){
            cout<<" ";
            cout<<Lista[im];
            cout<<",";
          }
        }

      cout << "\n\nSe Ordeno de Mayor a menor por metodo de Insercion \n\n";
      Esperar();


    }else if(Orden ==2 ){ //menor a Mayor

      for(int i=0;i<Max_Limite;i++){

        dir=i;
        aux=Lista[i];
        while(dir>0 && Lista[dir-1]>aux){
          Lista[dir]= Lista[dir-1];
          dir--;

          if(Max_Limite<10){
            contador++;
            cout<<contador;
            cout<<".- ";
            for(int im= 0; im<Max_Limite;im++){
              cout<<" ";
              cout<<Lista[im];
              cout<<",";
            }
          cout<<"\n";
          }

        }
        Lista[dir]=aux;

        if(Max_Limite<20){
          contador++;
          cout<<contador;
          cout<<".- ";
          for(int im= 0; im<Max_Limite;im++){
            cout<<" ";
            cout<<Lista[im];
            cout<<",";
          }
        cout<<"\n";
        }

        }

        if(Max_Limite>=20){
          for(int im= 0; im<Max_Limite;im++){
            cout<<" ";
            cout<<Lista[im];
            cout<<",";
          }
        }
      cout << "\n\nSe Ordeno de menor a Mayor por metodo de Insercion \n\n";
      Esperar();

    }else{
      cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
      Esperar();
    }

  }else{
    cout <<"Losiento, primero debes generar la lista de numeros\n\n";
    Esperar();
  }

}

void Seleccion(int *Lista, int Max_Limite, int generada){
  //Variables locales
  int Orden,aux, selector, contador= 0;
  if(generada){

    do{

      cout<<"¿Como deseas ordenar la lista?\n\n";
      cout<<"1. Mayor a menor\n";
      cout<<"2.menor a Mayor\n\n";
      cout<<"Opcion: ";
      cin>> Orden;

      if(Orden<1 || Orden>2){
        cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
        Esperar();
      }
      system(CLEAR);
    }while(Orden<1 || Orden>2);

    if(Orden == 1 ){ //Mayor a menor

      for(int separa=0;separa < Max_Limite;separa++){
          selector=separa;
          for(int compara=separa+1; compara < Max_Limite; compara++){
            if(Lista[compara]> Lista[selector]){
              selector=compara;
            }
            aux= Lista[separa];
            Lista[separa]=Lista[selector];
            Lista[selector]=aux;

            if(Max_Limite<20){
              contador++;
              cout<<contador;
              cout<<".- ";
              for(int im= 0; im<Max_Limite;im++){
                cout<<" ";
                cout<<Lista[im];
                cout<<",";
              }
            cout<<"\n";
            }

          }
      }

      if(Max_Limite>=20){
        for(int im= 0; im<Max_Limite;im++){
          cout<<" ";
          cout<<Lista[im];
          cout<<",";
        }
      }
      cout << "\n\nSe Ordeno de Mayor a menor por metodo de Seleccion \n\n";
      Esperar();


    }else if(Orden ==2 ){ //menor a Mayor

      for(int separa=0;separa < Max_Limite;separa++){
          selector=separa;
          for(int compara=separa+1; compara < Max_Limite; compara++){
            if(Lista[compara]< Lista[selector]){
              selector=compara;
            }
            aux= Lista[separa];
            Lista[separa]=Lista[selector];
            Lista[selector]=aux;

            if(Max_Limite<20){
              contador++;
              cout<<contador;
              cout<<".- ";
              for(int im= 0; im<Max_Limite;im++){
                cout<<" ";
                cout<<Lista[im];
                cout<<",";
              }
            cout<<"\n";
            }

          }
      }

      if(Max_Limite>=20){
        for(int im= 0; im<Max_Limite;im++){
          cout<<" ";
          cout<<Lista[im];
          cout<<",";
        }
      }

      cout << "\n\nSe Ordeno de menor a Mayor por metodo de Seleccion \n\n";
      Esperar();

    }else{
      cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
      Esperar();
    }

  }else{
    cout <<"Losiento, primero debes generar la lista de numeros\n\n";
    Esperar();
  }

}

void MergeSort(int *Lista, int Max_Limite, int generada){
  //Variables locales
  int Orden;
  if(generada){

    do{

      cout<<"¿Como deseas ordenar la lista?\n\n";
      cout<<"1. Mayor a menor\n";
      cout<<"2.menor a Mayor\n\n";
      cout<<"Opcion: ";
      cin>> Orden;

      if(Orden<1 || Orden>2){
        cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
        Esperar();
      }
      system(CLEAR);
    }while(Orden<1 || Orden>2);

    if(Orden == 1 ){ //Mayor a menor

      Merge(Lista,0,Max_Limite-1,Orden);
      for(int im= 0; im<Max_Limite;im++){
        cout<<" ";
        cout<<Lista[im];
        cout<<",";
      }

      cout << "\n\nSe Ordeno de Mayor a menor por metodo de MergeSort \n\n";
      Esperar();


    }else if(Orden ==2 ){ //menor a Mayor

      Merge(Lista,0,Max_Limite-1,Orden);
      for(int im= 0; im<Max_Limite;im++){
        cout<<" ";
        cout<<Lista[im];
        cout<<",";
      }
      cout << "\n\nSe Ordeno de menor a Mayor por metodo de MergeSort \n\n";
      Esperar();

    }else{
      cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
      Esperar();
    }

  }else{
    cout <<"Losiento, primero debes generar la lista de numeros\n\n";
    Esperar();
  }

}

void QuickSort(int *Lista, int Max_Limite, int generada){
  //Variables locales
  int Orden;

  if(generada){

    do{

      cout<<"¿Como deseas ordenar la lista?\n\n";
      cout<<"1. Mayor a menor\n";
      cout<<"2.menor a Mayor\n\n";
      cout<<"Opcion: ";
      cin>> Orden;

      if(Orden<1 || Orden>2){
        cout<< "Lo siento esta no es una opcion valida, intenta nuevamente\n\n";
        Esperar();
      }
      system(CLEAR);
    }while(Orden<1 || Orden>2);

    if(Orden == 1 ){ //Mayor a menor

      QuickSortingM(Lista, 0, Max_Limite-1);
      for(int im= 0; im<Max_Limite;im++){
        cout<<" ";
        cout<<Lista[im];
        cout<<",";
      }

      cout << "\n\nSe Ordeno de Mayor a menor por metodo de QuickSort \n\n";
      Esperar();


    }else if(Orden ==2 ){ //menor a Mayor

      QuickSortingm(Lista, 0, Max_Limite-1);
      for(int im= 0; im<Max_Limite;im++){
        cout<<" ";
        cout<<Lista[im];
        cout<<",";
      }

      cout << "\n\nSe Ordeno de menor a Mayor por metodo de QuickSort \n\n";
      Esperar();

    }else{
      cout<< "Lo siento parece que ocurrio un error inesperado\n\n";
      Esperar();
    }

  }else{
    cout <<"Losiento, primero debes generar la lista de numeros\n\n";
    Esperar();
  }

}


//Auxiliares de los Metodos
void Merge(int *Lista,int Min_Limite,int Max_Limite,int Orden){
  //Variables locales
  int corte;
  corte=(Min_Limite+Max_Limite)/2;
  if(Min_Limite < Max_Limite){
    Merge(Lista,Min_Limite,corte,Orden);
    Merge(Lista,corte+1,Max_Limite,Orden);
    if(Orden==1){
      SortMayor(Lista,Min_Limite,corte,Max_Limite);
    }else{
      Sortmenor(Lista,Min_Limite,corte,Max_Limite);
    }
  }
}

void SortMayor(int *Lista,int Min_Limite,int corte,int Max_Limite){
    //Variables locales
    int aux[Max_Limite+2],inferior,superior,registro_aux;
    registro_aux=0;
    inferior=Min_Limite;
    superior=corte+1;

    while(inferior<= corte && superior<=Max_Limite){
      registro_aux++;
      if(Lista[inferior]>Lista[superior]){
        aux[registro_aux]=Lista[inferior];
        inferior++;
      }else{
          aux[registro_aux]=Lista[superior];
          superior++;
      }
    }

    for(int sobra=inferior; sobra<=corte;sobra++){
      registro_aux++;
      aux[registro_aux]=Lista[sobra];
    }

    for(int sobra=superior; sobra<=Max_Limite;sobra++){
      registro_aux++;
      aux[registro_aux]=Lista[sobra];
    }

    for(int transpaso=1; transpaso<=registro_aux;transpaso++)
      Lista[Min_Limite+transpaso-1]=aux[transpaso];

}

void Sortmenor(int *Lista,int Min_Limite,int corte,int Max_Limite){
    //Variables locales
    int aux[Max_Limite+2],inferior,superior,registro_aux;
    registro_aux=0;
    inferior=Min_Limite;
    superior=corte+1;

    while(inferior<= corte && superior<=Max_Limite){
      registro_aux++;
      if(Lista[inferior]<Lista[superior]){
        aux[registro_aux]=Lista[inferior];
        inferior++;
      }else{
          aux[registro_aux]=Lista[superior];
          superior++;
      }
    }

    for(int sobra=inferior; sobra<=corte;sobra++){
      registro_aux++;
      aux[registro_aux]=Lista[sobra];
    }

    for(int sobra=superior; sobra<=Max_Limite;sobra++){
      registro_aux++;
      aux[registro_aux]=Lista[sobra];
    }

    for(int transpaso=1; transpaso<=registro_aux;transpaso++)
      Lista[Min_Limite+transpaso-1]=aux[transpaso];

}

void QuickSortingM(int *Lista,int Min_Limite,int Max_Limite){
  //Variables locales
  int respaldo,inferior,superior,corte;

  if(Min_Limite<Max_Limite){
    respaldo=Lista[Min_Limite];
    inferior=Min_Limite;
    superior=Max_Limite;

    while(superior>inferior){

      while(superior>inferior && Lista[superior]<respaldo)
      superior--;

      if(superior >inferior){
        Lista[inferior] = Lista[superior];
        inferior++;
      }

      while(superior>inferior && Lista[inferior]>respaldo)
      inferior++;

      if(superior>inferior){
        Lista[superior] = Lista[inferior];
        superior--;
      }
    }
    Lista[inferior]=respaldo;
    corte=superior;

    QuickSortingM(Lista,Min_Limite,corte-1);
    QuickSortingM(Lista,corte+1,Max_Limite);
  }
}

void QuickSortingm(int *Lista,int Min_Limite,int Max_Limite){
  //Variables locales
  int respaldo,inferior,superior,corte;

  if(Min_Limite<Max_Limite){
    respaldo=Lista[Min_Limite];
    inferior=Min_Limite;
    superior=Max_Limite;

    while(superior>inferior){

      while(superior>inferior && Lista[superior]>respaldo) superior--;

      if (superior>inferior) {
        Lista[inferior]=Lista[superior];
        inferior++;
      }

      while(superior>inferior && Lista[inferior]<respaldo) inferior++;

      if (superior>inferior) {
        Lista[superior]=Lista[inferior];
        superior--;
      }
    }
    Lista[inferior]=respaldo;
    corte=superior;

    QuickSortingm(Lista,Min_Limite,corte-1);
    QuickSortingm(Lista,corte+1,Max_Limite);
  }
}
