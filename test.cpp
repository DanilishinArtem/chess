#include <SFML/Graphics.hpp>

int main() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

    // Создаем круг
    sf::CircleShape shape(50);
    shape.setFillColor(sf::Color::Red);

    // Основной цикл приложения
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Очищаем окно
        window.clear();
        // Рисуем круг
        window.draw(shape);
        // Отображаем содержимое окна на экран
        window.display();
    }

    return 0;
}


// g++ main.cpp -o sfmlTest -lsfml-graphics -lsfml-window -lsfml-system
// sudo apt-get install libsfml-dev