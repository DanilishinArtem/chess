#pragma once
#ifndef GAME_H
#define GAME_H

#include "Board/Board.h"
#include "pc.h"
#include "player.h"
#include <SFML/Graphics.hpp>
#include "Move.h"
#include "window.h"

class Game {
public:
    Game();
    void start();
    void change_current_player(Color& color);

private:
    Board board;
    Color currentPlayer;
    sf::Font font;
    sf::Text scoreText;
    sf::Text fontStatus;
    sf::Text currentPlayerText;
};

#endif