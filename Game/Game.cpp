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

    fontStatus.setFont(font);
    fontStatus.setCharacterSize(20);
    fontStatus.setFillColor(sf::Color::Black);
    fontStatus.setPosition(500, Height + Gap - 50);
}

void Game::updateText(string textStatus) {
    scoreText.setString("White: " + std::to_string(board.getScoreWhite()) + " - Black:" + std::to_string(board.getScoreBlack()));
    currentPlayerText.setString("Current player: " + static_cast<string>((currentPlayer == WHITE ? "White" : "Black")));
    fontStatus.setString(textStatus);
}

void Game::change_current_player(Color& current_player){
    if(current_player == WHITE){
        current_player = BLACK;
    }else{
        current_player = WHITE;
    }
}

void Game::start() {
    // Pc* first_player = new Pc();
    Player* white_player = new Player();
    Player* black_player = new Player();
    Move movement_white;
    Move movement_black;
    sf::RenderWindow window(sf::VideoMode(Width, Height + Gap), "Chess Game");

    Piece* selectedPiece = nullptr;
    sf::Vector2i selectedPieceOriginalPos;
    bool isCheck_white = false;
    bool isCheck_black = false;
    bool valid;
    while(window.isOpen()){
        if (currentPlayer == WHITE) {
            isCheck_white = board.isCheck(WHITE);
            if(isCheck_white){
                if(board.isCheckmate(WHITE)){
                    cout << "WHITE lose!" << endl;
                    break;
                }                
            }
            valid = false;
            movement_white = white_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            // cout << "movement_white: " << movement_white.first.first << ", " << movement_white.first.second << ", " << movement_white.second.first << ", " << movement_white.second.second << endl;
            valid = board.movePiece(movement_white.startX, movement_white.startY, movement_white.endX, movement_white.endY);
            if(valid){
                Game::change_current_player(currentPlayer);
            }                
        }else{
            isCheck_black = board.isCheck(BLACK);
            if(isCheck_black){
                if(board.isCheckmate(BLACK)){
                    cout << "BLACK lose!" << endl;
                    break;
                }
            }
            valid = false;
            movement_black = black_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            // cout << "movement_white: " << movement_black.first.first << ", " << movement_black.first.second << ", " << movement_black.second.first << ", " << movement_black.second.second << endl;
            valid = board.movePiece(movement_black.startX, movement_black.startY, movement_black.endX, movement_black.endY);
            if(valid){
                Game::change_current_player(currentPlayer);
            }
        }
        
        if(isCheck_white == true && isCheck_black == false){
            Game::updateText("Check for white player");
        }
        if(isCheck_black == true && isCheck_white == false){
            Game::updateText("Check for black player");
        }
        if(isCheck_white == false && isCheck_black == false){
            Game::updateText("No check");
        }

        window.display();
        window.clear();
        board.display(window);
        window.draw(scoreText);
        window.draw(currentPlayerText);
        window.draw(fontStatus);
    }
}
