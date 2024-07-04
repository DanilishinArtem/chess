// Pawn - пешка

#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"

class Pawn : public Piece {
public:
    Pawn(Color color) : Piece(color) {
        Value = 1;
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        // cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }

    string getName() const override { return color == WHITE ? "white_pawn" : "black_pawn"; }

    string getTextureFile() const override { return color == WHITE ? "Game/Board/PiecesClasses/images/white_pawn.png" : "Game/Board/PiecesClasses/images/black_pawn.png"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        if(color == WHITE){
            return (endX == startX && endY == startY + 1) || (startY == 1 && endY == startY + 2 && endX == startX);
        }else{
            return (endX == startX && endY == startY - 1) || (startY == 6 && endY == startY - 2 && endX == startX);
        }
    }

    bool eats(int startX, int startY, int endX, int endY) const override {
        if(color == WHITE){
            return (endX == startX + 1 && endY == startY + 1) || (endX == startX - 1 && endY == startY + 1);
        }else{
            return (endX == startX + 1 && endY == startY - 1) || (endX == startX - 1 && endY == startY - 1);
        }
    }

    int getValue() const override { return Value; }
};

#endif