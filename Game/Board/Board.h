#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "PiecesClasses/Piece.h"
#include "PiecesClasses/King.h"
#include "PiecesClasses/Queen.h"
#include "PiecesClasses/Rook.h"
#include "PiecesClasses/Bishop.h"
#include "PiecesClasses/Knight.h"
#include "PiecesClasses/Pawn.h"
#include "../Move.h"

#define SIGN(x) ((x) > 0 ? 1 : ((x) < 0 ? -1 : 0))

const int Width = 800;
const int Height = 800;
const int Gap = 300;


class Board {
public:
    Board();
    Piece* getPiece(int x, int y) const;
    void setPiece(int x, int y, Piece* piece);
    bool movePiece(int startX, int startY, int endX, int endY);
    int getScoreWhite() const { return scoreWhite; }
    void updateScoreWhite(const Piece& piece) { scoreWhite += piece.getValue(); }
    int getScoreBlack() const { return scoreBlack; }
    void updateScoreBlack(const Piece& piece) { scoreBlack += piece.getValue(); }
    bool validTrace(int startX, int startY, int endX, int endY) const;
    bool isCheck(Color color) const;
    bool isCheckmate(Color color) const;
    bool castling(Piece* firstPiece, int startX, int startY, int endX, int endY);
    bool capturing(Piece* firstPiece, int startX, int startY, int endX, int endY);

private:
    vector<vector<Piece*>> board;
    int scoreWhite;
    int scoreBlack;
    vector<Move> getAllPossibleMoves(Color color) const;
};

#endif