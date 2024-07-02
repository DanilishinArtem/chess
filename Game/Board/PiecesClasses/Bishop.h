// Bishop - слон

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(Color color) : Piece(color) {
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        // cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }

    string getName() const override { return color == WHITE ? "white_bishop" : "black_bishop"; }

    string getTextureFile() const override {
        return color == WHITE ? "/home/adanilishin/chess/Game/Board/PiecesClasses/images/white_bishop.png" : "/home/adanilishin/chess/Game/Board/PiecesClasses/images/black_bishop.png"; 
    }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        return abs(startX - endX) == abs(startY - endY);
    }

    bool eats(int startX, int startY, int endX, int endY) const override {
        return isValidMove(startX, startY, endX, endY);
    }
};

#endif