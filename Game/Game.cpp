#include "Game.h"
#include <iostream>


Game::Game() : currentPlayer(WHITE), board(Board()) {}

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
    window_class window(Width, Height, Gap);

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
            valid = board.movePiece(movement_black.startX, movement_black.startY, movement_black.endX, movement_black.endY);
            if(valid){
                Game::change_current_player(currentPlayer);
            }
        }
        
        // if(isCheck_white == true && isCheck_black == false){
        //     Game::updateText("Check for white player");
        // }
        // if(isCheck_black == true && isCheck_white == false){
        //     Game::updateText("Check for black player");
        // }
        // if(isCheck_white == false && isCheck_black == false){
        //     Game::updateText("No check");
        // }
        window.clear();
        window.display(board.getScoreWhite(), board.getScoreBlack(), board, currentPlayer);
    }
}
