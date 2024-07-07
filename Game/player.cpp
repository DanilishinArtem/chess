#include "player.h"

pair<pair<int, int>, pair<int, int>> Player::move(const Board& board, sf::RenderWindow& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos) {
    sf::Event event;
    pair<pair<int, int>, pair<int, int>> movement_Player = {{0, 0}, {0, 0}};
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
        }
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if(mousePos.x < Width && mousePos.y < Height){
                    selectedPiece = board.getPiece(mousePos.x / (Width / 8), mousePos.y / (Height / 8));
                    if(selectedPiece && selectedPiece->getColor() == currentPlayer){
                        selectedPieceOriginalPos = sf::Vector2i(mousePos.x / (Width / 8), mousePos.y / (Height / 8));
                    }else{
                        selectedPiece = nullptr;
                    }
                }
            }
        }
        if(event.type == sf::Event::MouseButtonReleased){
            if(event.mouseButton.button == sf::Mouse::Left){
                if(selectedPiece){
                    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                    movement_Player = make_pair(make_pair(selectedPieceOriginalPos.x, selectedPieceOriginalPos.y), make_pair(mousePos.x / (Width / 8), mousePos.y / (Height / 8)));
                }
            }
        }
    }
    return movement_Player;    
}


