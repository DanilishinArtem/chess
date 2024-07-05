#ifndef PC_H
#define PC_H
#include "Board/Board.h"

class Pc {
public:
    pair<pair<int, int>, pair<int, int>> move(const Board& board, sf::RenderWindow& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos);
};

#endif