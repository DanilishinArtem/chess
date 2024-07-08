#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
    scoreWhite = 0;
    scoreBlack = 0;
    // initialize board
    for (int i = 0; i < 8; i++) {
        board[i][1] = new Pawn(WHITE);
        board[i][6] = new Pawn(BLACK);
    }

    board[1][0] = new Knight(WHITE);
    board[6][0] = new Knight(WHITE);
    board[1][7] = new Knight(BLACK);
    board[6][7] = new Knight(BLACK);

    board[0][0] = new Rook(WHITE);
    board[7][0] = new Rook(WHITE);
    board[0][7] = new Rook(BLACK);
    board[7][7] = new Rook(BLACK);

    board[2][0] = new Bishop(WHITE);
    board[5][0] = new Bishop(WHITE);
    board[2][7] = new Bishop(BLACK);
    board[5][7] = new Bishop(BLACK);

    board[3][0] = new King(WHITE);
    board[4][0] = new Queen(WHITE);
    board[3][7] = new King(BLACK);
    board[4][7] = new Queen(BLACK);
    
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

bool Board::isCheck(Color color) const {
    pair<int, int> KingPosition; 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(Board::getPiece(i, j) != nullptr && Board::getPiece(i, j)->getColor() == color && (Board::getPiece(i, j)->getName() == "white_king" || Board::getPiece(i, j)->getName() == "black_king")){
                KingPosition = {i, j};
                break;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(Board::getPiece(i, j) != nullptr && Board::getPiece(i, j)->getColor() != color){
                if(Board::validTrace(i, j, KingPosition.first, KingPosition.second)){
                    return true;
                }
            }
        }
    }
    return false;
}

vector<Move> Board::getAllPossibleMoves(Color color) const {
    vector<Move> moves;
    for(int startX = 0; startX < 8; startX++){
        for(int startY = 0; startY < 8; startY++){
            Piece* piece = Board::getPiece(startX, startY);
            if(piece && piece->getColor() == color){
                // check all possible terminate positions
                for(int endX = 0; endX < 8; endX++){
                    for(int endY = 0; endY < 8; endY++){
                        if(Board::validTrace(startX, startY, endX, endY)){
                            moves.push_back({startX, startY, endX, endY});
                        }
                    }
                }
            }
        }
    }
    return moves;
}

bool Board::isCheckmate(Color color) const {
    vector<Move> moves = Board::getAllPossibleMoves(color);
    for(const Move& move : moves){
        Board tempBoard = *this;
        if(tempBoard.movePiece(move.startX, move.startY, move.endX, move.endY)){
            if(!tempBoard.isCheck(color)){
                return false;
            }
        }
    }
    return true;
}

bool Board::validTrace(int startX, int startY, int endX, int endY) const {
    if(Board::getPiece(startX, startY)->getName() == "white_knight" || Board::getPiece(startX, startY)->getName() == "black_knight"){
        if(Board::getPiece(startX, startY)->isValidMove(startX, startY, endX, endY)){
            return true;
        }else{
            return false;
        }
    }
    int dx = SIGN(endX - startX);
    int dy = SIGN(endY - startY);
    int tempX = startX;
    int tempY = startY;
    if(Board::getPiece(startX, startY)->isValidMove(startX, startY, endX, endY) || Board::getPiece(startX, startY)->eats(startX, startY, endX, endY)){
        while((tempX != endX) || (tempY != endY)){
            if(tempX + dx == endX && tempY + dy == endY){
                return true;
            }
            if(!Board::getPiece(tempX + dx, tempY + dy)){
                tempX += dx;
                tempY += dy;
            }else{
                return false;
            }
        }
    }
    return false;
}

bool Board::movePiece(int startX, int startY, int endX, int endY){
    if(startX == endX && startY == endY){
        return false;
    }
    Piece* firstPiece = getPiece(startX, startY);
    Piece* secondPiece = getPiece(endX, endY);
    if(!secondPiece){
        if(firstPiece && Board::validTrace(startX, startY, endX, endY)){
            setPiece(startX, startY, nullptr);
            setPiece(endX, endY, firstPiece);
            return true;
        }else{
            return false;
        }
    }else{
        if(firstPiece && Board::validTrace(startX, startY, endX, endY) && (firstPiece->getColor() != secondPiece->getColor())){
            if(firstPiece->getColor() == WHITE){
                updateScoreWhite(*secondPiece);
            }else{
                updateScoreBlack(*secondPiece);
            }
            setPiece(startX, startY, nullptr);
            setPiece(endX, endY, firstPiece);
            return true;            
        }
    }
    return false;
}
