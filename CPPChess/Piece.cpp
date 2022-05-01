//
//  Piece.cpp
//  CPPChess
//
//  Created by Tyler Phalen on 4/8/22.
//

#include "chessGame.h"

chessPiece::chessPiece(){}
chessPiece::chessPiece(int Type, int color, coordinates xy){
    switch (Type) {
        case blank:
            Title = "blank";
            UCode = " ";
            pieceType = blank;
            pieceColor = null;
            XY = xy;
            break;
        case king:
            switch (color) {
                case white:
                    Title = "White King";
                    UCode = "\u2654";
                    pieceType = king;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black King";
                    UCode = "\u265A";
                    pieceType = king;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        case queen:
            switch (color) {
                case white:
                    Title = "White Queen";
                    UCode = "\u2655";
                    pieceType = queen;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black Queen";
                    UCode = "\u265B";
                    pieceType = queen;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        case bishop:
            switch (color) {
                case white:
                    Title = "White Bishop";
                    UCode = "\u2657";
                    pieceType = bishop;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black Bishop";
                    UCode = "\u265D";
                    pieceType = bishop;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        case knight:
            switch (color) {
                case white:
                    Title = "White Knight";
                    UCode = "\u2658";
                    pieceType = knight;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black Knight";
                    UCode = "\u265E";
                    pieceType = knight;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        case rook:
            switch (color) {
                case white:
                    Title = "White Rook";
                    UCode = "\u2656";
                    pieceType = rook;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black Rook";
                    UCode = "\u265C";
                    pieceType = rook;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        case pawn:
            switch (color) {
                case white:
                    Title = "White Pawn";
                    UCode = "\u2659";
                    pieceType = pawn;
                    pieceColor = white;
                    XY = xy;
                    break;
                case black:
                    Title = "Black Pawn";
                    UCode = "\u265F";
                    pieceType = pawn;
                    pieceColor = black;
                    XY = xy;
                    break;
                    
                default: cout << "Invalid Color" << endl;
                    break;
            }
            break;
        default: cout << "Invalid Piece Type." << endl;
            break;
    }
}
bool chessPiece::move(chessPiece* piece, chessPiece* destination, int moveCount){
    int x;
    int y;
    bool wasValid = false;
    switch (piece->pieceType) {
        case king:
            if (abs(piece->XY.x - destination->XY.x) <= 1 && abs(piece->XY.y - destination->XY.y) <= 1){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        case queen:
            x = abs(piece->XY.x - destination->XY.x);
            y = abs(piece->XY.y - destination->XY.y);
            if ((x == 0 && y <= 8) || (x <= 8 && y == 0) || (x == y)){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        case bishop:
            x = abs(piece->XY.x - destination->XY.x);
            y = abs(piece->XY.y - destination->XY.y);
            if ((x == y) && (x + y < 16)){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        case knight:
            x = abs(piece->XY.x - destination->XY.x);
            y = abs(piece->XY.y - destination->XY.y);
            
            if ((x == 2 && y == 1) || (x == 1 && y == 2)){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        case rook:
            x = abs(piece->XY.x - destination->XY.x);
            y = abs(piece->XY.y - destination->XY.y);
            
            if ((x > 1 && y == 0) || (x == 0 && y > 1)){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        case pawn:
            if (moveCount >= 1 && abs(piece->XY.x - destination->XY.x) <= 0 && abs(piece->XY.y - destination->XY.y) == 1){
                piece->XY = destination->XY;
                wasValid = true;
            } else if (moveCount < 1 && abs(piece->XY.x - destination->XY.x) <= 0 && abs(piece->XY.y - destination->XY.y) == 2){
                piece->XY = destination->XY;
                wasValid = true;
            } else if (((destination->pieceType != blank) && (destination->pieceColor != piece->pieceColor)) && abs(piece->XY.x - destination->XY.x) == 1 && abs(piece->XY.y - destination->XY.y) == 1){
                piece->XY = destination->XY;
                wasValid = true;
            } else if ((moveCount < 2) && (piece->pieceColor == black) && abs(piece->XY.x - destination->XY.x) <= 0 && abs(piece->XY.y - destination->XY.y) == 2){
                piece->XY = destination->XY;
                wasValid = true;
            } else {
                cout << "Invalid Move" << endl;
            }
            break;
        default: cout << "Invalid Piece Type" << endl;
            break;
    }
    return wasValid;
}
void chessPiece::displayPiece(){
    //a function for displaying an individual piece to the console.
    cout << UCode << " " << Title << endl;
}


