// Bishop - слон

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color color) : Piece(color) {}

    string getName() const override { return color == WHITE ? "WB" : "BB"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        return abs(startX - endX) == abs(startY - endY);
    }
};

#endif