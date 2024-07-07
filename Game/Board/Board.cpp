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

void Board::display(sf::RenderWindow& window) const {
    const int cellSize = Width / 8;
    const int boardSize = 8;
    sf::RectangleShape mainCell(sf::Vector2f(Width, Height + Gap));
    mainCell.setFillColor(sf::Color::White);
    mainCell.setPosition(0, 0);
    window.draw(mainCell);
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));


    for(int y = 0; y < boardSize; y++){
        cout << string(2, ' ');
        for(int x = 0; x < boardSize; x++){
            // Draw the cell
            if((x + y) % 2 == 0){
                cell.setFillColor(sf::Color::Cyan);
            }else{
                cell.setFillColor(sf::Color::Blue);
            }
            cell.setPosition(x * cellSize, y * cellSize);
            window.draw(cell);
            // Draw the piece            
            Piece* piece = getPiece(x, y);
            if(piece){
                sf::Sprite sprite;
                sf::Texture texture = piece->getTexture();
                // Scaling:
                sf::Vector2u textureSize = texture.getSize();
                float scaleX = static_cast<float>(Width) / textureSize.x;
                float scaleY = static_cast<float>(Height) / textureSize.y;
                sprite.setScale(scaleX / 8.0f, scaleY / 8.0f);
                // End of scaling...
                sprite.setTexture(texture);
                sprite.setPosition(x * cellSize, y * cellSize);
                window.draw(sprite);
            }
        }
        cout << endl;
    }
}