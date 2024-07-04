#ifndef PC_H
#define PC_H
#include "Board/Board.h"

class Pc {
public:
    pair<pair<int, int>, pair<int, int>> Move(const Board& board);
};

#endif