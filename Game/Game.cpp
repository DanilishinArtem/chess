#include "Game.h"
#include <iostream>

// const int Width = 800;
// const int Height = 800;

Game::Game() : currentPlayer(WHITE) {}

void Game::start() {
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Chess Game");
    // Creating the board
    Board board;
    // Basic cycle
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }

        window.clear();
        board.display(window);
        window.display();
    }
}