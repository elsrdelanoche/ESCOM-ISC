//===================================LIBRERIAS
#include <iostream>
#include <ctime>
#include <vector>
#include <numeric>
using namespace std;
//===================================PROTOTIPOS
vector<float>ejecutarCodigo(int,int);
vector<float>familiaParabola(int);
void imprimir(vector<float>);
float sumaTiempo=0;
//===================================MAIN
int main() {
    int Ns=4000;
    vector<float>Tiempos=ejecutarCodigo(Ns,1);
    vector<float>fParabola=familiaParabola(Ns);
    imprimir(fParabola);
    sumaTiempo= accumulate(Tiempos.begin(),Tiempos.end(),0);
    cout<<sumaTiempo;
    return 0;
}
//===================================FUNCIONES
vector<float>familiaParabola(int ejecuciones){
    vector<float>Familia;
    for (int i=0; i<ejecuciones; i++) {
        Familia.push_back(i*i);
    }
    return Familia;
}

void imprimir(vector<float>Datos){
    for (int i=0; i<Datos.size(); i++) {
        cout<<Datos[i]<<endl;
    }
}

vector<float>ejecutarCodigo(int Ns,int bandera){
    vector<float>Tiempos;
    
    if(bandera==1){
        int Multiplicacion;
        clock_t Tiempo;
        for (int i=0; i<Ns; i++) {
            Tiempo=clock();
            Multiplicacion=3*5;
            Tiempo=clock()-Tiempo;
            Tiempos.push_back(float(Tiempo));
        }
    }
    return Tiempos;
}