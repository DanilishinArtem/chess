// Queen - королева
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color color) : Piece(color) {}

    string getName() const override {return color == WHITE ? "WQ" : "BQ";}

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == dy || startX == endX || startY == endY);
    }
};

#endif