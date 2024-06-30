#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"

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