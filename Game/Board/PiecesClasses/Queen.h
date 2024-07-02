// Queen - королева
#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen : public Piece {
public:
    Queen(Color color) : Piece(color) {
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        // cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }

    string getName() const override {return color == WHITE ? "white_queen" : "black_queen";}

    string getTextureFile() const override {return color == WHITE ? "/home/adanilishin/chess/Game/Board/PiecesClasses/images/white_queen.png" : "/home/adanilishin/chess/Game/Board/PiecesClasses/images/black_queen.png";}

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx == dy || startX == endX || startY == endY);
    }

    bool eats(int startX, int startY, int endX, int endY) const override {
        return isValidMove(startX, startY, endX, endY);
    }
};

#endif