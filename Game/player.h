#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Board/Board.h"
#include "Game.h"
#include "Move.h"

class Player {
public:
    Move move(const Board& board, sf::RenderWindow& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos);
};

#endif