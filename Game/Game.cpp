#include "Game.h"
#include <iostream>

Game::Game() : currentPlayer(WHITE) {}

void Game::start() {
    while(true){
        board.display();
        cout << "Player " << (currentPlayer == WHITE ? "WHITE" : "BLACK") << "'s turn." << endl;

        int startX, startY, endX, endY;
        cout << "Enter move (startX startY endX endY): ";
        cin >> startX >> startY >> endX >> endY;

        if(board.movePiece(startX, startY, endX, endY)){
            currentPlayer = (currentPlayer == WHITE ? BLACK : WHITE);
        }else{
            cout << "Invalid move, try again." << endl;
        }
    }
}