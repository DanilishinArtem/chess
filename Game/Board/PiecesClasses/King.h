// King - король
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color color) : Piece(color) {}
    string getName() const override { return color == WHITE ? "WK" : "BK"; }
    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx <= 1 && dy <= 1);
    }
};

#endif