#include<bits/stdc++.h>
using namespace std;
struct estado{
    int num;
    bool es_entrada=false;
    bool es_aceptado=false;
    estado *ap0 = nullptr;
    estado *ap1 = nullptr;
};

int main(){
    // Abrir el archivo en modo de lectura
    ifstream archivo("automata2.txt");

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        cout << "No se pudo abrir el archivo" << endl;
        return 1;
    }
    else cout << "Leyendo archivo txt..." << endl;

    //lectura datos principales (Num de estados, estado inicial y num de estados aceptados)
    int n_estados, e_inicial,n_acept;
    archivo>>n_estados>>e_inicial>>n_acept;
    //Lectura de aceptados
    vector<int> e_acept(n_acept);
    for(int i=0;i<n_acept;i++){
        archivo>>e_acept[i];
    }
    
    //Asignación de caracteristicas por estado
    vector<estado> Q(n_estados, estado());
    int numE,temp0,temp1;
    for(int i=0;i<n_estados;i++){
        if(i==e_inicial){           //Asignacion de inicial
            Q[i].es_entrada=true;
        }
        for(int j=0;j<n_acept;j++){         //Asignacion de aceptados
            if(e_acept[j]==i){
                Q[i].es_aceptado=true;      
            }
        }
        archivo>>numE>>temp0>>temp1;
        //cout<<"Ap0: "<<(int*)&Q[i].ap0<<"\tAp1: "<<(int*)&Q[i].ap1<<endl<<endl;         //Asignacion de numero de estado, almacena el estado al que apunta transicion 0 y el estado al que apunta transicion 1
        Q[i].num = numE;       
        Q[i].ap0 = &Q[temp0];                    //Asigna transicion 0 y 1 al 
        Q[i].ap1 = &Q[temp1];                    //Estado actual

        //Impresion de datos 
        cout<<"Estado Q"<<Q[i].num<<"\t";
        cout<<"AC: "<<Q[i].es_aceptado;
        cout<<"\tIN: "<<Q[i].es_entrada<<"\t";
        cout<<"Ap0: "<<temp0<<"\tAp1: "<<temp1<<endl;
        numE=-1,temp0=-1,temp1=-1;
    }

    //cerrar archivo
    archivo.close();
    
    // Generar archivo DOT
    ofstream dot("automata.dot");
    dot << "digraph G {\n";
    for(int i=0;i<n_estados;i++){
        
        dot << "Q" << Q[i].num << " [shape=circle";
        if(Q[i].es_entrada)dot << ",style=bold";
        if(Q[i].es_aceptado) dot << ",peripheries=2";
        dot << "];\n";
        if(Q[i].ap0) dot << "Q" << Q[i].num << " -> Q" << Q[i].ap0->num << " [label=0];\n";
        if(Q[i].ap1) dot << "Q" << Q[i].num << " -> Q" << Q[i].ap1->num << " [label=1];\n";
    }
    // Agregar flecha de entrada
    dot << "entrada [shape=none, label=\"\", height=0.08, width=0.08];\n";dot << "entrada -> Q" << e_inicial ;
    dot << "}";
    dot.close();
    // Llamar al comando dot para generar la imagen del grafo
    system("dot -Tpng -o automata.png automata.dot");
    //Evaluar cadenas
    string cadena;
    int actual=e_inicial;
    while(cadena!="salir"){
        cout<<"ingrese cadena a evaluar: ";
        cin>>cadena;
        for(int i=0;i<cadena.length();i++){
            if(cadena[i]=='0'){
                actual=Q[actual].ap0->num;
            }
            if(cadena[i]=='1'){
                actual=Q[actual].ap1->num;
            }
        }
        if(Q[actual].es_aceptado==true){
            cout<<"Es aceptada tu cadena!!"<<endl;
        }
        else cout<<"Intenta otra vez :("<<endl;
        actual=e_inicial;
    }

    
}
