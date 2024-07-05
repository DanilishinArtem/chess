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

void change_current_player(Color& current_player){
    if(current_player == WHITE){
        current_player = BLACK;
    }else{
        current_player = WHITE;
    }
}

void Game::start() {
    Pc* first_player = new Pc();
    // Player* first_player = new Player();
    Player* second_player = new Player();
    pair<pair<int, int>, pair<int, int>> movement_PC;
    pair<pair<int, int>, pair<int, int>> movement_Player;
    // Creating the window
    sf::RenderWindow window(sf::VideoMode(Width, Height + Gap), "Chess Game");

    Piece* selectedPiece = nullptr;
    sf::Vector2i selectedPieceOriginalPos;
    bool valid;
    // Basic cycle
    while(window.isOpen()){
        if (currentPlayer == BLACK) {
            valid = false;
            movement_PC = first_player->move(board, window);
            // movement_PC = second_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            valid = board.movePiece(movement_PC.first.first, movement_PC.first.second, movement_PC.second.first, movement_PC.second.second);
            if(valid){
                change_current_player(currentPlayer);
            }                
        }else{
            valid = false;
            movement_Player = second_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            valid = board.movePiece(movement_Player.first.first, movement_Player.first.second, movement_Player.second.first, movement_Player.second.second);
            if(valid){
                change_current_player(currentPlayer);
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
