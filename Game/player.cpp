#include "player.h"

Move Player::move(const Board& board, window_class& window, const Color& currentPlayer, Piece*& selectedPiece, sf::Vector2i& selectedPieceOriginalPos) {
    sf::Event event;
    Move movement_Player = {0, 0, 0, 0};
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
            exit;
        }
        if(event.type == sf::Event::MouseButtonPressed){
            if(event.mouseButton.button == sf::Mouse::Left){
                coordinates mousePos = window.getPositionBoard();
                if(mousePos.x != -1 && mousePos.y != -1){
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
                    coordinates mousePos = window.getPositionBoard();
                    movement_Player = {selectedPieceOriginalPos.x, selectedPieceOriginalPos.y, mousePos.x / (Width / 8), mousePos.y / (Height / 8)};
                }
            }
        }
    }
    return movement_Player;    
}

string Player::makeChoice(window_class& window){
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            window.close();
            exit;
        }
    }
    if(event.type == sf::Event::MouseButtonPressed){
        if(event.mouseButton.button == sf::Mouse::Left){
            coordinates mousePos = window.getPositionInfo();
            if(mousePos.x != -1 && mousePos.y != -1){
                string new_Piece = window.get_choosePiece(mousePos.x, mousePos.y);
                if(new_Piece != ""){
                    return new_Piece;
                }
            }
        }
    }
    return "";
}


