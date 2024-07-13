#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "Board/Board.h"
#include "Game.h"
#include "Move.h"
#include "window.h"

class Player {
public:
    Move move(const Board& board, window_class& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos);
    string makeChoice(window_class& window);
};

#endif