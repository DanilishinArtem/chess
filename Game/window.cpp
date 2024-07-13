#include "window.h"

window_class::window_class(int WidthBoard, int HeightBoard, int WidthInfo) : WidthBoard_(WidthBoard), HeightBoard_(HeightBoard), WidthInfo_(WidthInfo) {
    windowBoard.create(sf::VideoMode(WidthBoard_ + WidthInfo_, HeightBoard_), "Chess Game");
}

coordinates window_class::getPositionBoard() const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(windowBoard);
    if(mousePos.x < WidthBoard_ && mousePos.y < HeightBoard_) {
        return coordinates{mousePos.x, mousePos.y};
    }
    return coordinates{-1, -1};
}

coordinates window_class::getPositionInfo() const {
    sf::Vector2i mousePos = sf::Mouse::getPosition(windowBoard);
    if(mousePos.x > WidthBoard_ && mousePos.y < HeightBoard_) {
        return coordinates{mousePos.x - WidthBoard_, mousePos.y};
    }
    return coordinates{-1, -1};
}

void window_class::displayBasicInfo(int scoreWhite, int scoreBlack, Color currentPlayer, bool check, bool checkMate) {
    font.loadFromFile("Game/fonts/ArialRegular.ttf");
    title.setFont(font);
    title.setCharacterSize(20);
    title.setFillColor(sf::Color::White);
    title.setPosition(WidthBoard_ + 10, 0);
    title.setString("Current score:");

    scoreText.setFont(font);
    scoreText.setCharacterSize(20);
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(WidthBoard_ + 10, 30);
    scoreText.setString("White: " + std::to_string(scoreWhite) + " - Black:" + std::to_string(scoreBlack));

    currectPlayer.setFont(font);
    currectPlayer.setCharacterSize(20);
    currectPlayer.setFillColor(sf::Color::White);
    currectPlayer.setPosition(WidthBoard_ + 10, 60);
    currectPlayer.setString("Current player: " + static_cast<string>((currentPlayer == WHITE ? "White" : "Black")));

    checkMateStatus.setFont(font);
    checkMateStatus.setCharacterSize(20);
    checkMateStatus.setFillColor(sf::Color::White);
    checkMateStatus.setPosition(WidthBoard_ + 10, 90);
    string temp = "";
    if(currentPlayer == WHITE){
        if(check){
            temp = "Check for White player";
        }
        if(checkMate){
            temp = "White player lost";
        }
    }else{
        if(check){
            temp = "Check for Black player";
        }
        if(checkMate){
            temp = "Black player lost";
        }
    }
    checkMateStatus.setString(temp);

    windowBoard.draw(scoreText);
    windowBoard.draw(title);
    windowBoard.draw(currectPlayer);
    windowBoard.draw(checkMateStatus);
}

void window_class::displayLine() {
    sf::VertexArray line(sf::Lines, 2);
    line[0].position = sf::Vector2f(WidthBoard_, 0);
    line[1].position = sf::Vector2f(WidthBoard_, HeightBoard_);
    line[0].color = sf::Color::Blue;
    line[1].color = sf::Color::Blue;
    windowBoard.draw(line);
}

void window_class::displayBoard(const Board& board) {
    const int cellSize = WidthBoard_ / 8;
    const int boardSize = 8;
    sf::RectangleShape mainCell(sf::Vector2f(WidthBoard_, HeightBoard_));
    mainCell.setFillColor(sf::Color::White);
    mainCell.setPosition(0, 0);
    windowBoard.draw(mainCell);
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    for(int y = 0; y < boardSize; y++){
        for(int x = 0; x < boardSize; x++){
            // Draw the cell
            if((x + y) % 2 == 0){
                cell.setFillColor(sf::Color::Cyan);
            }else{
                cell.setFillColor(sf::Color::Blue);
            }
            cell.setPosition(x * cellSize, y * cellSize);
            windowBoard.draw(cell);
            // Draw the piece            
            Piece* piece = board.getPiece(x, y);
            if(piece){
                sf::Sprite sprite;
                sf::Texture texture = piece->getTexture();
                // Scaling:
                sf::Vector2u textureSize = texture.getSize();
                float scaleX = static_cast<float>(WidthBoard_) / textureSize.x;
                float scaleY = static_cast<float>(HeightBoard_) / textureSize.y;
                sprite.setScale(scaleX / 8.0f, scaleY / 8.0f);
                // End of scaling...
                sprite.setTexture(texture);
                sprite.setPosition(x * cellSize, y * cellSize);
                windowBoard.draw(sprite);
            }
        }
    }
}

string window_class::get_choosePiece(int x, int y) const {
    const int cellSize = WidthInfo_ / 4;
    if(x > 0 * cellSize && x < 1 * cellSize && y > HeightBoard_ / 2 && y < HeightBoard_ / 2 + cellSize){
        return "Knight";
    }else if(x > 1 * cellSize && x < 2 * cellSize && y > HeightBoard_ / 2 && y < HeightBoard_ / 2 + cellSize){
        return "Rook";
    }else if(x > 2 * cellSize && x < 3 * cellSize && y > HeightBoard_ / 2 && y < HeightBoard_ / 2 + cellSize){
        return "Bishop";
    }else if(x > 3 * cellSize && x < 4 * cellSize && y > HeightBoard_ / 2 && y < HeightBoard_ / 2 + cellSize){
        return "Queen";
    }
    return "";
}

void window_class::displayChoosePiece(const Board& board, Color currentPlayer){
    font.loadFromFile("Game/fonts/ArialRegular.ttf");
    choosePiece.setFont(font);
    choosePiece.setCharacterSize(20);
    choosePiece.setFillColor(sf::Color::White);
    choosePiece.setPosition(WidthBoard_ + 10, HeightBoard_ / 2 - 30);
    // can choose any piece beside pawn and king
    const int cellSize = WidthInfo_ / 4;
    sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
    cell.setFillColor(sf::Color::Black);
    for(int x = 0; x < 4; x++){
        cell.setPosition(WidthBoard_ + x * cellSize, HeightBoard_ / 2);
        windowBoard.draw(cell);
    }

    string color = (currentPlayer == WHITE ? "white" : "black");
    sf::Texture Knight, Rook, Bishop, Queen;
    Knight.loadFromFile("Game/Board/PiecesClasses/images/" + color + "_knight.png");
    Rook.loadFromFile("Game/Board/PiecesClasses/images/" + color + "_rook.png");
    Bishop.loadFromFile("Game/Board/PiecesClasses/images/" + color + "_bishop.png");
    Queen.loadFromFile("Game/Board/PiecesClasses/images/" + color + "_queen.png");
    sf::Sprite spriteKnight, spriteRook, spriteBishop, spriteQueen;
    spriteKnight.setTexture(Knight);
    spriteRook.setTexture(Rook);
    spriteBishop.setTexture(Bishop);
    spriteQueen.setTexture(Queen);
    spriteKnight.setPosition(WidthBoard_ + 0 * cellSize, HeightBoard_ / 2);
    spriteRook.setPosition(WidthBoard_ + 1 * cellSize, HeightBoard_ / 2);
    spriteBishop.setPosition(WidthBoard_ + 2 * cellSize, HeightBoard_ / 2);
    spriteQueen.setPosition(WidthBoard_ + 3 * cellSize, HeightBoard_ / 2);

    string temp = "";
    if(currentPlayer == WHITE){
        temp = "Choose piece for White Pawn";
    }else{
        temp = "Choose piece for Black Pawn";
    }
    choosePiece.setString(temp);
    windowBoard.draw(choosePiece);
    windowBoard.draw(spriteKnight);
    windowBoard.draw(spriteRook);
    windowBoard.draw(spriteBishop);
    windowBoard.draw(spriteQueen);
    windowBoard.display();
}

void window_class::display(int scoreWhite, int scoreBlack, const Board& board, Color currentPlayer, bool check, bool checkMate) {
    displayBasicInfo(scoreWhite, scoreBlack, currentPlayer, check, checkMate);
    displayLine();
    displayBoard(board);
    windowBoard.display();
}

void window_class::clear() {
    windowBoard.clear();
}

bool window_class::isOpen() const {
    return windowBoard.isOpen();
}

bool window_class::pollEvent(sf::Event& event) {
    return windowBoard.pollEvent(event);
}

void window_class::close() {
    windowBoard.close();
}