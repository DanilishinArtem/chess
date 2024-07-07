#include <SFML/Graphics.hpp>
#include <iostream>

class Game {
public:
    Game();
    void start();
    void updateInfo();
    void renderGame();
    void renderInfo();

private:
    sf::RenderWindow window;
    sf::View gameView;
    sf::View infoView;
    sf::Font font;
    sf::Text scoreText;
    sf::Text currentPlayerText;
    int scoreWhite;
    int scoreBlack;
    std::string currentPlayer;
};

Game::Game() : window(sf::VideoMode(800, 600), "Chess Game") {
    // Load font
    if (!font.loadFromFile("/home/adanilishin/chess/test/ArialRegular.ttf")) {
        std::cerr << "Error loading font" << std::endl;
    }

    // Initialize texts
    scoreText.setFont(font);
    scoreText.setCharacterSize(10);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(10, 10);

    currentPlayerText.setFont(font);
    currentPlayerText.setCharacterSize(10);
    currentPlayerText.setFillColor(sf::Color::Black);
    currentPlayerText.setPosition(10, 40);

    // Initialize scores and player
    scoreWhite = 0;
    scoreBlack = 0;
    currentPlayer = "White";

    // Setup views
    gameView = window.getDefaultView();
    infoView.setSize(200, 600);
    infoView.setCenter(100, 300);
}

void Game::updateInfo() {
    scoreText.setString("White: " + std::to_string(scoreWhite) + " - Black: " + std::to_string(scoreBlack));
    currentPlayerText.setString("Current Player: " + currentPlayer);
}

void Game::renderGame() {
    window.setView(gameView);
    // Render your game board and pieces here
}

void Game::renderInfo() {
    window.setView(infoView);
    window.draw(scoreText);
    window.draw(currentPlayerText);
}

void Game::start() {
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color::White);
        renderGame();
        updateInfo();
        renderInfo();
        window.display();
    }
}

int main() {
    Game game;
    game.start();
    return 0;
}



// g++ main.cpp -o chess_game -lsfml-graphics -lsfml-window -lsfml-system