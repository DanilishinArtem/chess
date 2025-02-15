// Knight - Конь

#ifndef KNIGHT_H
#define KNIGHT_H

#include "Piece.h"

class Knight : public Piece {
public:
    Knight(Color color) : Piece(color) {
        Value = 3;
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        // cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }

    string getName() const override { return color == WHITE ? "white_knight" : "black_knight"; }

    string getTextureFile() const override { return color == WHITE ? "Game/Board/PiecesClasses/images/white_knight.png" : "Game/Board/PiecesClasses/images/black_knight.png"; }

    bool isValidMove(int startX, int startY, int endX, int endY) override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == 2 && dy == 1) || (dx == 1 && dy == 2);
    }

    bool eats(int startX, int startY, int endX, int endY) override {
        return isValidMove(startX, startY, endX, endY);
    }

    int getValue() const override { return Value; }
};

#endif