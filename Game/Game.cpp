#include "Game.h"
#include <iostream>


Game::Game() : currentPlayer(WHITE), board(Board()) {
    font.loadFromFile("Game/fonts/ArialRegular.ttf");
    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setPosition(0, Height + Gap - 50);

    currentPlayerText.setFont(font);
    currentPlayerText.setCharacterSize(20);
    currentPlayerText.setFillColor(sf::Color::Black);
    currentPlayerText.setPosition(0, Height + Gap - 25);

    fontStatus.setFont(font);
    fontStatus.setCharacterSize(20);
    fontStatus.setFillColor(sf::Color::Black);
    fontStatus.setPosition(500, Height + Gap - 50);
}

void Game::updateText(string textStatus) {
    scoreText.setString("White: " + std::to_string(board.getScoreWhite()) + " - Black:" + std::to_string(board.getScoreBlack()));
    currentPlayerText.setString("Current player: " + static_cast<string>((currentPlayer == WHITE ? "White" : "Black")));
    fontStatus.setString(textStatus);
}

sf::Vector2i Game::toBoardCoordinates(sf::Vector2i pixelCoords){
    return sf::Vector2i(pixelCoords.x / 100, (pixelCoords.y - Gap) / 100);
}

void Game::change_current_player(Color& current_player){
    if(current_player == WHITE){
        current_player = BLACK;
    }else{
        current_player = WHITE;
    }
}

bool Game::isCheck(Color color) const {
    pair<int, int> KingPosition; 
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board.getPiece(i, j) != nullptr && board.getPiece(i, j)->getColor() == color && (board.getPiece(i, j)->getName() == "white_king" || board.getPiece(i, j)->getName() == "black_king")){
                KingPosition = {i, j};
                break;
            }
        }
    }

    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board.getPiece(i, j) != nullptr && board.getPiece(i, j)->getColor() != color){
                if(board.validTrace(i, j, KingPosition.first, KingPosition.second)){
                    cout << "Check makes " << board.getPiece(i, j)->getName() << " at position << " << i << ", " << j << " to the king at " << KingPosition.first << ", " << KingPosition.second << endl;
                    return true;
                }
            }
        }
    }
    return false;
}


vector<pair<Piece*, sf::Vector2i>> getAllPossibleMoves(Color color) {
    // TODO: realization of getAllPossibleMoves
    return vector<pair<Piece*, sf::Vector2i>>();
}

bool isCheckmate(Color color) {
    // TODO: realization of isCheckmate
    return false;
}

void Game::start() {
    // Pc* first_player = new Pc();
    Player* white_player = new Player();
    Player* black_player = new Player();
    pair<pair<int, int>, pair<int, int>> movement_white;
    pair<pair<int, int>, pair<int, int>> movement_black;
    sf::RenderWindow window(sf::VideoMode(Width, Height + Gap), "Chess Game");

    Piece* selectedPiece = nullptr;
    sf::Vector2i selectedPieceOriginalPos;
    bool isCheck_white = false;
    bool isCheck_black = false;
    bool valid;
    while(window.isOpen()){
        if (currentPlayer == WHITE) {
            isCheck_white = Game::isCheck(WHITE);
            // cout << "isCheck for WHITE: " << Game::isCheck(WHITE) << endl;
            // if(isCheckmate(WHITE)){
            //     cout << "WHITE lose!" << endl;
            //     break;
            // }
            valid = false;
            movement_white = white_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            // cout << "movement_white: " << movement_white.first.first << ", " << movement_white.first.second << ", " << movement_white.second.first << ", " << movement_white.second.second << endl;
            valid = board.movePiece(movement_white.first.first, movement_white.first.second, movement_white.second.first, movement_white.second.second);
            if(valid){
                Game::change_current_player(currentPlayer);
            }                
        }else{
            isCheck_black = Game::isCheck(BLACK);
            // cout << "isCheck for BLACK: " << Game::isCheck(BLACK) << endl;
            // if(isCheckmate(BLACK)){
            //     cout << "BLACK lose!" << endl;
            //     break;
            // }
            valid = false;
            movement_black = black_player->move(board, window, currentPlayer, selectedPiece, selectedPieceOriginalPos);
            // cout << "movement_white: " << movement_black.first.first << ", " << movement_black.first.second << ", " << movement_black.second.first << ", " << movement_black.second.second << endl;
            valid = board.movePiece(movement_black.first.first, movement_black.first.second, movement_black.second.first, movement_black.second.second);
            if(valid){
                Game::change_current_player(currentPlayer);
            }
        }


        
        if(isCheck_white == true && isCheck_black == false){
            Game::updateText("Check for white player");
        }
        if(isCheck_black == true && isCheck_white == false){
            Game::updateText("Check for black player");
        }
        if(isCheck_white == false && isCheck_black == false){
            Game::updateText("No check");
        }

        window.display();
        window.clear();
        board.display(window);
        window.draw(scoreText);
        window.draw(currentPlayerText);
        window.draw(fontStatus);
    }
}
