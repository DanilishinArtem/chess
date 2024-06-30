#ifndef PIECE_H
#define PIECE_H

#include <string>
using namespace std;

enum Color {WHITE, BLACK};

class Piece {
public:
    Piece(Color color) : color(color) {}

    virtual ~Piece() {}

    Color getColor() const { return color; }

    virtual string getName() const = 0;

    virtual bool isValidMove( int startX, int startY, int endX, int endY) const = 0;

protected:
    Color color;
};

#endif