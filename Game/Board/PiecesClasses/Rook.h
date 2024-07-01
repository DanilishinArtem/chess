// Rook - ладья
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color color) : Piece(color) {}

    string getName() const override { return color == WHITE ? "♖" : "♜"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        return (startX == endX || startY == endY);
    }
};

#endif