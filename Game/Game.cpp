#include "Game.h"
#include <iostream>


Game::Game() : currentPlayer(WHITE) {}

void Game::start() {
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(800, 800), "Chess Game");
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