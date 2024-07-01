#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    // Создание окна
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Sprite Example");

    // Загрузка текстуры из файла
    sf::Texture texture;
    if (!texture.loadFromFile("/home/adanilishin/chess/Game/Board/images/black_king.png")) {
        std::cerr << "Error loading texture" << std::endl;
        return -1;
    }

    // Создание спрайта и установка текстуры
    sf::Sprite sprite;
    sprite.setTexture(texture);

    // Позиционирование спрайта (опционально)
    sprite.setPosition(0, 0);

    sf::Vector2u textureSize = texture.getSize();
    float scaleX = static_cast<float>(800) / textureSize.x;
    float scaleY = static_cast<float>(600) / textureSize.y;
    sprite.setScale(scaleX / 8.0f, scaleY / 8.0f);

    // Основной цикл программы
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite); // Отрисовка спрайта
        window.display();
    }

    return 0;
}
