#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"
#include "pc.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include "Move.h"

class Game {
public:
    Game();
    void start();
    sf::Vector2i toBoardCoordinates(sf::Vector2i pixelCoords);
    void change_current_player(Color& color);
    void updateText(string textStatus);

private:
    Board board;
    Color currentPlayer;
    bool isCheckmate(Color color) const;
    bool isCheck(Color color) const;
    vector<pair<Piece*, sf::Vector2i>> getAllPossibleMoves(Color color) const;
    sf::Font font;
    sf::Text scoreText;
    sf::Text fontStatus;
    sf::Text currentPlayerText;
};

#endif