#include "Game.h"
#include <iostream>


Game::Game() : currentPlayer(WHITE), board(Board()) {
    font.loadFromFile("Game/fonts/ArialRegular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(0, Height + Gap - 50);

    currentPlayerText.setFont(font);
    currentPlayerText.setCharacterSize(20);
    currentPlayerText.setFillColor(sf::Color::Black);
    currentPlayerText.setPosition(0, Height + Gap - 25);
}

void Game::updateText() {
    scoreText.setString("White: " + std::to_string(board.getScoreWhite()) + " - Black:" + std::to_string(board.getScoreBlack()));
    currentPlayerText.setString("Current player: " + static_cast<string>((currentPlayer == WHITE ? "White" : "Black")));
}

sf::Vector2i Game::toBoardCoordinates(sf::Vector2i pixelCoords){
    return sf::Vector2i(pixelCoords.x / 100, pixelCoords.y / 100);
}

void Game::start() {
    // Creating the pc player
    Pc* pc = new Pc();
    pair<pair<int, int>, pair<int, int>> move;
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(Width, Height + Gap), "Chess Game");

    Piece* selectedPiece = nullptr;
    sf::Vector2i selectedPieceOriginalPos;
    bool valid;
    // Basic cycle
    while(window.isOpen()){
        // Movement logic of the PC (computer plays for black)
        if (currentPlayer == BLACK) {
            move = pc->Move(board);
            valid = board.movePiece(move.first.first, move.first.second, move.second.first, move.second.second);
            if(valid){
                if(currentPlayer == WHITE){
                    currentPlayer = BLACK;
                }else{
                    currentPlayer = WHITE;
                }
            }
        // Movement logic of the player (player plays for white)
        }else{
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
                            }
                        }
                    }
                }
            }
        }
        window.clear();
        board.display(window);
        window.draw(scoreText);
        window.draw(currentPlayerText);
        Game::updateText();
        window.display();
    }
}
