// Knight - Конь

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color color) : Piece(color) {}

    string getName() const override { return color == WHITE ? "♘" : "♞"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }
};

#endif