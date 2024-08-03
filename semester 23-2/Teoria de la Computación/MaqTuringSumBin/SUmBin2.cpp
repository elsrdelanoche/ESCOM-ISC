#include <iostream>
#include <vector>

using namespace std;

// Función para realizar la suma binaria
vector<int> sumaBinaria(const vector<int>& a, const vector<int>& b) {
    vector<int> resultado;
    int carry = 0;

    // Suma de los dígitos binarios
    for (int i = a.size() - 1; i >= 0; --i) {
        int suma = a[i] + b[i] + carry;
        resultado.insert(resultado.begin(), suma % 2);
        carry = suma / 2;
    }

    // Si queda un último acarreo, se agrega al resultado
    if (carry)
        resultado.insert(resultado.begin(), carry);

    return resultado;
}

int main() {
    vector<int> numero1 = {0,0,1,1,1,0,1};  // 11 en binario
    vector<int> numero2 = {1,1,0,1,0,1,1};  // 13 en binario

    // Se completa con ceros a la izquierda en caso de que los números tengan diferente longitud
    int diff = numero1.size() - numero2.size();
    if (diff > 0) {
        for (int i = 0; i < diff; ++i)
            numero2.insert(numero2.begin(), 0);
    } else if (diff < 0) {
        for (int i = 0; i < -diff; ++i)
            numero1.insert(numero1.begin(), 0);
    }

    // Realizar la suma binaria
    vector<int> resultado = sumaBinaria(numero1, numero2);

    // Mostrar el resultado
    cout << "Resultado: ";
    for (int digit : resultado)
        cout << digit;
    cout << endl;

    return 0;
}
