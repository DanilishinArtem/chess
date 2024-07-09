#pragma once
#ifndef WINDOW_H
#define WINDOW_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Board/Board.h"

using namespace std;

struct coordinates {
    int x;
    int y;
};

class window_class {

public:
    sf::RenderWindow windowBoard;

    window_class (int WidthBoard, int HeightBoard, int WidthInfo);


    coordinates getPositionBoard() const;

    coordinates getPositionInfo() const;

    void displayBasicInfo(int scoreWhite, int scoreBlack, Color currentPlayer, bool check, bool checkMate);

    void displayLine();

    void displayBoard(const Board& board);

    void display(int scoreWhite, int scoreBlack, const Board& board, Color currentPlayer, bool check, bool checkMate);

    void clear();

    bool isOpen() const;

    bool pollEvent(sf::Event& event);

    void close();

private:
    int WidthBoard_;
    int HeightBoard_;
    int WidthInfo_;
    sf::Font font;
    sf::Text scoreText;
    sf::Text title;
    sf::Text currectPlayer;
    sf::Text checkMateStatus;
    sf::Text choosePiece;
};

#endif