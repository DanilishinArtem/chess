#include "Board.h"
#include <iostream>
#include <iomanip>

Board::Board() : board(8, std::vector<Piece*>(8, nullptr)) {
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

    board[3][0] = new Queen(WHITE);
    board[4][0] = new King(WHITE);
    board[3][7] = new Queen(BLACK);
    board[4][7] = new King(BLACK);
    
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
    // cout << static_cast<string>(piece->getName()) << " " << startX << " " << startY << " " << endX << " " << endY << endl;
    // cout << "isValidMove: " << piece->isValidMove(startX, startY, endX, endY) << endl;
    if(piece && piece->isValidMove(startX, startY, endX, endY)){
        setPiece(endX, endY, piece);
        setPiece(startX, startY, nullptr);
        return true;
    }
    return false;
}

void Board::display(sf::RenderWindow& window) const {
    const int cellSize = 100;
    const int boardSize = 8;

    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));

    for(int y = boardSize; y >= 0; y--){
        cout << string(2, ' ');
        for(int x = 0; x < boardSize; x++){
            // Draw the cell
            // if((x + y) % 2 == 0){
            //     cell.setFillColor(sf::Color::Cyan);
            // }else{
            //     cell.setFillColor(sf::Color::Blue);
            // }
            // cell.setPosition(x * cellSize, y * cellSize);
            // window.draw(cell);
            // Draw the piece            
            Piece* piece = getPiece(x, y);
            if(piece){
                // cout << piece->getName() << " " << endl;
                sf::Sprite sprite;
                sprite.setTexture(piece->getTexture());
                sprite.setPosition(x * cellSize, y * cellSize);
                window.draw(sprite);
            }
        }
        cout << endl;
    }
}