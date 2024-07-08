#include "pc.h"


Move Pc::move(const Board& board, window_class& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos) {
    sf::Event event;
    Move movement_Pc;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        movement_Pc.startX = 0;
        movement_Pc.startY = 6;
        movement_Pc.endX = 0;
        movement_Pc.endY = 4;
    }
    return movement_Pc;
}


