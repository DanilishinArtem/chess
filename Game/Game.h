#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void start();

private:
    Board board;
    Color currentPlayer;
    bool isCheckmate(Color color) const;
};

#endif