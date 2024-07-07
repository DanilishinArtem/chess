#pragma once
#ifndef PC_H
#define PC_H
#include "Board/Board.h"
#include "Game.h"
#include "Move.h"

class Pc {
public:
    Move move(const Board& board, sf::RenderWindow& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos);
};

#endif