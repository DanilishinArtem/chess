#include "Board.h"
#include <iostream>

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
    // initialize board
    for (int i = 0; i < 8; i++) {
        board[1][i] = new Pawn(WHITE);
        board[6][i] = new Pawn(BLACK);
    }

    board[0][1] = new Knight(WHITE);
    board[0][6] = new Knight(WHITE);
    board[7][1] = new Knight(BLACK);
    board[7][6] = new Knight(BLACK);

    board[0][0] = new Rook(WHITE);
    board[0][7] = new Rook(WHITE);
    board[7][0] = new Rook(BLACK);
    board[7][7] = new Rook(BLACK);

    board[0][2] = new Bishop(WHITE);
    board[0][5] = new Bishop(WHITE);
    board[7][2] = new Bishop(BLACK);
    board[7][5] = new Bishop(BLACK);

    board[0][3] = new Queen(WHITE);
    board[0][4] = new King(WHITE);
    board[7][3] = new Queen(BLACK);
    board[7][4] = new King(BLACK);
    
}

Piece* Board::getPiece(int x, int y) const {
    if(x >= 0 && x < 8 && y >= 0 && y < 8){
        return board[x][y];
    }
    return nullptr;
}

void Board::setPiece(int x, int y, Piece* piece){
    if(x >= 0 && x < 8 && y >= 0 && y < 8){
        board[x][y] = piece;
    }
}

bool Board::movePiece(int startX, int startY, int endX, int endY){
    Piece* piece = getPiece(startX, startY);
    if(piece && piece->isValidMove(startX, startY, endX, endY)){
        setPiece(endX, endY, piece);
        setPiece(startX, startY, nullptr);
        return true;
    }
    return false;
}

void Board::display() const {
    for(int y = 7; y >= 0; y--){
        for(int x = 0; x < 8; x++){
            Piece* piece = getPiece(x, y);
            if(piece){
                cout << piece->getName() << " ";
            }else{
                cout << " . ";
            }
        }
        cout << endl;
    }
}