//
//  chessGame.cpp
//  CPPChess
//
//  Created by Tyler Phalen on 4/8/22.
//

#include "chessGame.h"


chessGame::chessGame(){
    //initialize board and place all of the pieces in their initial positions
    coordinates XY;
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++){
            XY.x = x;
            XY.y = y;
            switch (y) {
                case eight:
                    switch (x) {
                        case a:
                            board[x][y] = chessPiece(rook, black, XY);
                            break;
                        case b:
                            board[x][y] = chessPiece(knight, black, XY);
                            break;
                        case c:
                            board[x][y] = chessPiece(bishop, black, XY);
                            break;
                        case d:
                            board[x][y] = chessPiece(queen, black, XY);
                            break;
                        case e:
                            board[x][y] = chessPiece(king, black, XY);
                            break;
                        case f:
                            board[x][y] = chessPiece(bishop, black, XY);
                            break;
                        case g:
                            board[x][y] = chessPiece(knight, black, XY);
                            break;
                        case h:
                            board[x][y] = chessPiece(rook, black, XY);
                            break;
                        default:
                            break;
                    }
                    break;
                case seven:
                    board[x][y] = chessPiece(pawn, black, XY);
                    break;
                case six:
                    board[x][y] = chessPiece(blank, null, XY);
                    break;
                case five:
                    board[x][y] = chessPiece(blank, null, XY);
                    break;
                case four:
                    board[x][y] = chessPiece(blank, null, XY);
                    break;
                case three:
                    board[x][y] = chessPiece(blank, null, XY);
                    break;
                case two:
                    board[x][y] = chessPiece(pawn, white, XY);
                    break;
                case one:
                    switch (x) {
                        case a:
                            board[x][y] = chessPiece(rook, white, XY);
                            break;
                        case b:
                            board[x][y] = chessPiece(knight, white, XY);
                            break;
                        case c:
                            board[x][y] = chessPiece(bishop, white, XY);
                            break;
                        case d:
                            board[x][y] = chessPiece(queen, white, XY);
                            break;
                        case e:
                            board[x][y] = chessPiece(king, white, XY);
                            break;
                        case f:
                            board[x][y] = chessPiece(bishop, white, XY);
                            break;
                        case g:
                            board[x][y] = chessPiece(knight, white, XY);
                            break;
                        case h:
                            board[x][y] = chessPiece(rook, white, XY);
                            break;
                        default:
                            break;
                    }
                    break;
                    
                default:
                    break;
            }
        }
    }
}
void chessGame::move(coordinates XY, coordinates newXY){
    //moves the selected piece to the desired square only if the move is valid, according to rules for each piece in the piece::move()
    chessPiece* piece = &board[XY.x][XY.y];
    chessPiece* destination = &board[newXY.x][newXY.y];
    bool valid = piece->move(piece, destination, moveCount);
    if (valid == true){
        moveCount++;
        board[piece->XY.x][piece->XY.y] = *piece;
        //if the move was valid (checked above), then the XY coordinates of the piece have already been changed so now this set the board location of those coords to the new piece.
        board[XY.x][XY.y] = chessPiece(blank, null, XY);
        //sets the just vacated space to a new blank piece (place holder)
    }
}
void chessGame::loadSave(queue<chessPiece> pieceQ){
    string type;
    string color;
    string x;
    string y;
    string alive;
    chessPiece temp;
    saveFile.open("chessSaveFile.txt");
    if (saveFile.is_open()) {
        while(!saveFile.eof()){
            getline(saveFile, temp.UCode, ',');
            getline(saveFile, type, ',');
            temp.pieceType = stoi(type);
            getline(saveFile, color, ',');
            temp.pieceColor = stoi(color);
            getline(saveFile, x, ',');
            temp.XY.x = stoi(x);
            getline(saveFile, y, ',');
            temp.XY.y = stoi(y);
            getline(saveFile, temp.Title, '\n');
            pieceQ.push(temp);
        }
        saveFile.close();
        for (int y = 0; y <= 7; y++) {
            for (int x = 0; x <= 7; x++){
                board[x][y] = pieceQ.front();
                pieceQ.pop();
            }
        }
    } else {
        cout << "No save file found. Continuing with new game..." << endl;
    }
}
void chessGame::displayBoard(){
    //displays the board and all the pieces in their current locations
    int n = 8;
    cout << endl;
    cout << "   --- --- --- --- --- --- --- ---" << endl;
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++){
            if (x == 0){
                cout << n;
                n--;
            }
            cout << " | ";
            if (board[x][y].alive == true)
                cout << board[x][y].UCode;
            if (x == 7){
                cout << " |";
                cout << endl;
                cout << "   --- --- --- --- --- --- --- ---" << endl;
            }
        }
    }
    cout << "    a   b   c   d   e   f   g   h";
    cout << endl;
    cout << endl;
}
void chessGame::displayTitle(){
    //outputs the title display
    cout << endl;
    cout <<"  ██████╗██╗  ██╗███████╗███████╗███████╗" << endl;
    cout <<" ██╔════╝██║  ██║██╔════╝██╔════╝██╔════╝" << endl;
    cout <<" ██║     ███████║█████╗  ███████╗███████╗" << endl;
    cout <<" ██║     ██╔══██║██╔══╝  ╚════██║╚════██║" << endl;
    cout <<" ╚██████╗██║  ██║███████╗███████║███████║" << endl;
    cout <<"  ╚═════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝" << endl;
    cout << "                      By: O'Faolin" << endl;
    cout << endl;
}
void chessGame::displayPiece(coordinates XY){
    board[XY.x][XY.y].displayPiece();
}
int chessGame::validateYInput(char yin){
    //converts the input char y value into a number and reverses it's value to match the 3d array using the yVal enum values.
    int y = -1;
    bool valid = true;
    switch (yin) {
        case '1': y = one;
            break;
        case '2': y = two;
            break;
        case '3': y = three;
            break;
        case '4': y = four;
            break;
        case '5': y = five;
            break;
        case '6': y = six;
            break;
        case '7': y = seven;
            break;
        case '8': y = eight;
            break;
        case '9': return y = 9;
        default: cout << "Please provide a valid input for y." << endl;
            valid = false;
            break;
    }
    return y;
}
int chessGame::validateXInput(char xin){
    //converts the input char x value into a number and reverses it's value to match the 3d array using the xVal enum values.
    int x = -1;
    bool valid = true;
    switch (xin) {
        case 'a': x = a;
            break;
        case 'b': x = b;
            break;
        case 'c': x = c;
            break;
        case 'd': x = d;
            break;
        case 'e': x = e;
            break;
        case 'f': x = f;
            break;
        case 'g': x = g;
            break;
        case 'h': x = h;
            break;
        case '9': return x = 9;
        default: cout << "Please provide a valid input for x." << endl;
            valid = false;
            break;
    }
    return x;
}
bool chessGame::validateSelection(coordinates XY){
    //to ensure that the piece you are trying to move is not a blank square
    bool valid = false;
    if (board[XY.x][XY.y].UCode == Blank.UCode){
        valid = false;
        cout << "Please select a valid piece." << endl;
    }
    else
        valid = true;
    return valid;
}
bool chessGame::validateMove(chessPiece selectedPiece, chessPiece destPiece){
    bool valid = false;
    //to ensure that the path is clear for non knight pieces
    if (selectedPiece.pieceType != knight && (selectedPiece.XY.x > destPiece.XY.x) && (selectedPiece.XY.y > destPiece.XY.y)) {
        int x = selectedPiece.XY.x;
        int y = selectedPiece.XY.y;
        do {
            if (board[x][y].pieceType != blank && board[x][y].pieceType != selectedPiece.pieceType){
                cout << "Path not clear!" << endl;
                return valid;
            }
            x--;
            y--;
        } while ((x >= destPiece.XY.x) && (y >= destPiece.XY.y));
    }
    if (selectedPiece.pieceType != knight && (selectedPiece.XY.x > destPiece.XY.x) && (selectedPiece.XY.y < destPiece.XY.y)) {
        int x = selectedPiece.XY.x;
        int y = selectedPiece.XY.y;
        do {
            if (board[x][y].pieceType != blank && board[x][y].pieceType != selectedPiece.pieceType){
                cout << "Path not clear!" << endl;
                return valid;
            }
            x--;
            y++;
        } while ((x >= destPiece.XY.x) && (y <= destPiece.XY.y));
    }
    if (selectedPiece.pieceType != knight && (selectedPiece.XY.x < destPiece.XY.x) && (selectedPiece.XY.y > destPiece.XY.y)) {
        int x = selectedPiece.XY.x;
        int y = selectedPiece.XY.y;
        do {
            if (board[x][y].pieceType != blank && board[x][y].pieceType != selectedPiece.pieceType){
                cout << "Path not clear!" << endl;
                return valid;
            }
            x++;
            y--;
        } while ((x <= destPiece.XY.x) && (y >= destPiece.XY.y));
    }
    if (selectedPiece.pieceType != knight && (selectedPiece.XY.x < destPiece.XY.x) && (selectedPiece.XY.y < destPiece.XY.y)) {
        int x = selectedPiece.XY.x;
        int y = selectedPiece.XY.y;
        do {
            if (board[x][y].pieceType != blank && board[x][y].pieceType != selectedPiece.pieceType){
                cout << "Path not clear!" << endl;
                return valid;
            }
            x++;
            y++;
        } while ((x <= destPiece.XY.x) && (y <= destPiece.XY.y));
    }
    
    //to ensure that the square you are going to is not occupied by a piece on your own team
    
    if (selectedPiece.pieceColor != destPiece.pieceColor){
        valid = true;
    }
    else{
        valid = false;
        cout << "Square is occupied by your team." << endl;
    }
    return valid;
}
bool chessGame::checkWin(){
    bool won = false;
    int winnerColor = null;
    int kingCount = 0;
    for (int y = 0; y <= 7; y++) {
        for (int x = 0; x <= 7; x++){
            if (board[x][y].pieceType == king) {
                kingCount+=1;
            }
        }
    }
    if (kingCount < 2) {
        for (int y = 0; y <= 7; y++) {
            for (int x = 0; x <= 7; x++){
                if (board[x][y].pieceType == king) {
                    winnerColor = board[x][y].pieceColor;
                }
            }
        }
        won = true;
        switch (winnerColor) {
            case white: cout << "White Wins!!" << endl;
                break;
            case black: cout << "Black Wins!!" << endl;
            default:
                break;
        }
    }
    return won;
}
