#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "PiecesClasses/Piece.h"
#include "PiecesClasses/King.h"
#include "PiecesClasses/Queen.h"
#include "PiecesClasses/Rook.h"
#include "PiecesClasses/Bishop.h"
#include "PiecesClasses/Knight.h"
#include "PiecesClasses/Pawn.h"

const int Width = 800;
const int Height = 800;

class Board {
public:
    Board();
    Piece* getPiece(int x, int y) const;
    void setPiece(int x, int y, Piece* piece);
    bool movePiece(int startX, int startY, int endX, int endY);
    void display(sf::RenderWindow& window) const;

private:
    vector<vector<Piece*>> board;
};

#endif