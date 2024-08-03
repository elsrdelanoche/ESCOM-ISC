#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector <int> vector1;   //Vector, tipo de dato, nombre

    vector1.push_back(80);
    vector1.push_back(100);
    vector1.push_back(3);
    vector1.push_back(45);
    vector1.push_back(4);

    for (int numero : vector1){ //Se indica que quiero extraer del vector1 de uno en uno los datos contenidos en el e incluirlos en la variable numero
        cout<<numero<<endl;
    }
    cout<<endl;
    vector1[2]=37;  //Modificar un valor en especifico
    cout<<vector1[2]<<endl;
    cout<<endl;

    for(auto numero = vector1.begin();numero!= vector1.end();numero++){  //Obtenemos un puntero al vector
        cout<<*numero<<endl;
    }
    cout<<endl;
    vector1.clear();
    //Recorrer en forma inversa
    for(auto numero = vector1.rbegin(); numero != vector1.rend();numero++){   //reverse begin && reverse end
        cout<<*numero<<endl;
    }
    cout<<endl;
}