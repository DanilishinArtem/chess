// Rook - ладья
#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(Color color) : Piece(color) {
        Value = 5;
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }

    string getName() const override { return color == WHITE ? "white_rook" : "black_rook"; }

    string getTextureFile() const override { return color == WHITE ? "Game/Board/PiecesClasses/images/white_rook.png" : "Game/Board/PiecesClasses/images/black_rook.png"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        return (startX == endX || startY == endY);
    }

    bool eats(int startX, int startY, int endX, int endY) const override {
        return isValidMove(startX, startY, endX, endY);
    }

    int getValue() const override { return Value; }

};

#endif