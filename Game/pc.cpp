#include "pc.h"

pair<pair<int, int>, pair<int, int>> Pc::move(const Board& board, sf::RenderWindow& window) {
    sf::Event event;
    pair<pair<int, int>, pair<int, int>> movement_Pc;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        movement_Pc.first.first = 0;
        movement_Pc.first.second = 6;
        movement_Pc.second.first = 0;
        movement_Pc.second.second = 4;
    }
    return movement_Pc;
}


