#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game();
    void start();
    sf::Vector2i toBoardCoordinates(sf::Vector2i pixelCoords);
    void updateScoreText();

private:
    Board board;
    Color currentPlayer;
    bool isCheckmate(Color color) const;
    sf::Font font;
    sf::Text scoreText;
};

#endif