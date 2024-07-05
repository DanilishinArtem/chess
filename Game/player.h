#ifndef PLAYER_H
#define PLAYER_H
#include "Board/Board.h"


class Player {
public:
    pair<pair<int, int>, pair<int, int>> move(const Board& board, sf::RenderWindow& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos);
};

#endif