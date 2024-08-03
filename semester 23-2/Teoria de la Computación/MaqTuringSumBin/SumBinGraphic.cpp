#include <SFML/Graphics.hpp>
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

    // Crear una ventana gráfica
    sf::RenderWindow window(sf::VideoMode(800, 600), "Máquina de Turing");

    // Crear un texto para mostrar el resultado
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        cout << "Error al cargar la fuente de texto." << endl;
        return -1;
    }
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    text.setString("Resultado:");

    // Bucle principal de la ventana
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Limpiar la ventana
        window.clear(sf::Color::Black);

        // Dibujar el texto del resultado
        window.draw(text);

        // Dibujar el resultado
        string resultadoStr;
        for (int digit : resultado)
            resultadoStr += to_string(digit);
        sf::Text resultadoText;
        resultadoText.setFont(font);
        resultadoText.setCharacterSize(24);
        resultadoText.setFillColor(sf::Color::White);
        resultadoText.setPosition(10, 50);
        resultadoText.setString(resultadoStr);
        window.draw(resultadoText);

        // Mostrar la ventana
        window.display();
    }

    return 0;
}
