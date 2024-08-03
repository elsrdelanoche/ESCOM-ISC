#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

// Función para ejecutar el código y obtener la imagen generada y la salida
std::pair<sf::Image, std::string> executeCodeAndGetImage()
{
    // Aquí deberías escribir el código para ejecutar el código en C++ y obtener la imagen generada y la salida.
    // Esta función devuelve un par, donde el primer elemento es la imagen generada y el segundo elemento es la salida del código.
    // Puedes reemplazar esto con tu propia lógica de ejecución de código.

    sf::Image image;
    image.create(800, 600, sf::Color::White); // Ejemplo: Generar una imagen en blanco

    std::string output = "Este es el resultado del código."; // Ejemplo: Salida del código

    return std::make_pair(image, output);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Generador de Imágenes");

    sf::Font font;
    if (!font.loadFromFile("Roboto-Regular.ttf"))
    {
        std::cout << "Error al cargar la fuente de texto." << std::endl;
        return -1;
    }

    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(10, 10);

    sf::Texture texture;
    sf::Sprite sprite;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            auto result = executeCodeAndGetImage();

            // Mostrar la imagen generada
            texture.loadFromImage(result.first);
            sprite.setTexture(texture);

            // Mostrar la salida del código
            std::string output = "Salida: " + result.second;
            text.setString(output);
        }

        window.clear(sf::Color::White);
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

    return 0;
}

