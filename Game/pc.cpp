#include "pc.h"

pair<pair<int, int>, pair<int, int>> Pc::Move(const Board& board) {
    // TODO: implement move logic
    pair<pair<int, int>, pair<int, int>> move;
    // move.first.first = startX;
    // move.first.second = startY;
    // move.second.first = endX;
    // move.second.second = endY;
    move.first.first = 0;
    move.first.second = 6;
    move.second.first = 0;
    move.second.second = 4;
    return move;
}


