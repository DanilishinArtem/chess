// Pawn - пешка

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color) : Piece(color) {}

    string getName() const override { return color == WHITE ? "♙" : "♟"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        if(color == WHITE){
            return (endX == startX && endY == startY + 1) || (startY == 1 && endY == startY + 2 && endX == startX);
        }else{
            return (endX == startX && endY == startY - 1) || (startY == 6 && endY == startY - 2 && endX == startX);
        }
    }
};

#endif