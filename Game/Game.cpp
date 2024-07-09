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
    bool isCheckmateWhite = false;
    bool isCheckmateBlack = false;
    bool valid;
    while(window.isOpen()){

        if (currentPlayer == WHITE) {
            isCheck_white = board.isCheck(WHITE);
            if(isCheck_white){
                isCheckmateWhite = board.isCheckmate(WHITE);
            }
            if(!isCheckmateWhite && !isCheckmateBlack){
                valid = false;
                movement_white = white_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
                valid = board.movePiece(movement_white.startX, movement_white.startY, movement_white.endX, movement_white.endY);
                if(valid){
                    Game::change_current_player(currentPlayer);
                }                
            }
        }else{
            isCheck_black = board.isCheck(BLACK);
            if(isCheck_black){
                isCheckmateBlack = board.isCheckmate(BLACK);
            }
            if(!isCheckmateWhite && !isCheckmateBlack){
                valid = false;
                movement_black = black_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
                valid = board.movePiece(movement_black.startX, movement_black.startY, movement_black.endX, movement_black.endY);
                if(valid){
                    Game::change_current_player(currentPlayer);
                }
            }
        }
        window.clear();
        if(currentPlayer == WHITE){
            window.display(board.getScoreWhite(), board.getScoreBlack(), board, currentPlayer, isCheck_white, isCheckmateWhite);
        }else{
            window.display(board.getScoreWhite(), board.getScoreBlack(), board, currentPlayer, isCheck_black, isCheckmateBlack);
        }

        if(isCheckmateWhite || isCheckmateBlack){
            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type == sf::Event::Closed){
                    window.close();
                }
            }
        }
    }
}



// TODO: relalize choice of pieces when pown reachs the end of the board
// TODO: implement capturing on the pass
// TODO: implement castling