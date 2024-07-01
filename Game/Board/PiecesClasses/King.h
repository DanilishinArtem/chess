// King - король
#ifndef KING_H
#define KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(Color color) : Piece(color) {
        bool loaded = texture.loadFromFile(getTextureFile());
        if(!loaded) {
            cout << "Error loading texture" << endl;
        }
        cout << "Loaded for " << getName() << ", status: " << loaded << endl;
    }
    string getName() const override { return color == WHITE ? "white_king" : "black_king"; }

    string getTextureFile() const override { return color == WHITE ? "/home/adanilishin/chess/Game/Board/images/white_king.png" : "/home/adanilishin/chess/Game/Board/images/black_king.png"; }

    bool isValidMove(int startX, int startY, int endX, int endY) const override {
        int dx = abs(endX - startX);
        int dy = abs(endY - startY);
        return (dx <= 1 && dy <= 1);
    }
};

#endif