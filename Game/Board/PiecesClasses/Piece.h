#ifndef PIECE_H
#define PIECE_H

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

enum Color {WHITE, BLACK};

class Piece {
public:

    Piece(Color color) : color(color) {} // , currentPath(CURRENT_SOURCE_DIR)

    virtual ~Piece() {}

    Color getColor() const { return color; }

    virtual string getName() const = 0;

    virtual string getTextureFile() const = 0;

    virtual bool isValidMove( int startX, int startY, int endX, int endY) = 0;

    virtual bool eats( int startX, int startY, int endX, int endY) = 0;

    sf::Texture getTexture() const { return texture; }

    virtual int getValue() const { return Value; }

    bool isFirstMove = true;

    bool twoSteps = false;

protected:
    Color color;
    sf::Texture texture;
    int Value;
};

#endif