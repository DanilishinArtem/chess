#include <iostream>
#include <map>
using namespace std;

enum class PieceValue {
    KING = 999,
    QUEEN = 9,
    ROOK = 5,
    BISHOP = 3,
    KNIGHT = 3,
    PAWN = 1
};



map<string, int> ScorePiece = {
    {"black_bishop" , 3},
    {"white_bishop" , 3},
    {"white_king" , 1000},
    {"black_king" , 1000},
    {"white_knight" , 3},
    {"black_knight" , 3},
    {"black_pawn" , 1},
    {"white_pawn" , 1},
    {"white_queen" , 9},
    {"black_queen" , 9},
    {"white_rook" , 5},
    {"black_rook", 5}
};


int main() {
    cout << ScorePiece["black_bishop"] << endl;
    return 0;
}


// g++ test.cpp -o sfmlTest -lsfml-graphics -lsfml-window -lsfml-system
// sudo apt-get install libsfml-dev