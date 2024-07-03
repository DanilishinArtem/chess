#include "Game.h"
#include <iostream>


Game::Game() : currentPlayer(WHITE), board(Board()) {
    font.loadFromFile("Game/fonts/ArialRegular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(10);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(0, 0);
}

void Game::updateScoreText() {
    scoreText.setString("White: " + std::to_string(board.getScoreWhite()) + " - Black:" + std::to_string(board.getScoreBlack()));
}

sf::Vector2i Game::toBoardCoordinates(sf::Vector2i pixelCoords){
    return sf::Vector2i(pixelCoords.x / 100, pixelCoords.y / 100);
}

void Game::start() {
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Chess Game");

    Piece* selectedPiece = nullptr;
    sf::Vector2i selectedPieceOriginalPos;
    bool valid;
    // Basic cycle
    while(window.isOpen()){
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type == sf::Event::Closed){
                window.close();
            }
            // Basic cycle of mouse events
            
            // Logic of mouse pressed event
            if(event.type == sf::Event::MouseButtonPressed){
                if(event.mouseButton.button == sf::Mouse::Left){
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    sf::Vector2i boardPos = toBoardCoordinates(mousePos);

                    selectedPiece = board.getPiece(boardPos.x, boardPos.y);
                    if(selectedPiece && selectedPiece->getColor() == currentPlayer){
                        selectedPieceOriginalPos = boardPos;
                    }else{
                        selectedPiece = nullptr;
                    }
                }
            }

            // Logic of mouse released event
            if(event.type == sf::Event::MouseButtonReleased){
                if(event.mouseButton.button == sf::Mouse::Left){
                    if(selectedPiece){
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        sf::Vector2i boardPos = toBoardCoordinates(mousePos);
                        valid = board.movePiece(selectedPieceOriginalPos.x, selectedPieceOriginalPos.y, boardPos.x, boardPos.y);
                        if(valid){
                           if(currentPlayer == WHITE){
                               currentPlayer = BLACK;
                           }else{
                               currentPlayer = WHITE;
                           }
                           selectedPiece = nullptr;
                        }
                    }
                }
            }
        }
        window.clear();
        board.display(window);
        window.draw(scoreText);
        Game::updateScoreText();
        window.display();
    }
}
