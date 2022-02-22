//
//  Pieces.h
//  CPPChess
//
//  Created by Tyler Phalen on 2/21/22.
//

#ifndef Pieces_h
#define Pieces_h

#include <iostream>
#include<cmath>


using namespace std;

enum pieceTypes {null, king, queen, bishop, knight, rook, pawn};

class chessPiece{
public:
    int pieceType = null;
    string Title;
    int XPosition;
    int YPosition;
    string UCode;
    
    chessPiece(){}
    chessPiece(string title, int xPosition, int yPosition){
        Title = title;
        UCode = "0";
        XPosition = xPosition;
        YPosition = yPosition;
    }
    void place(chessPiece& piece, chessPiece board[8][8]){
        board[piece.XPosition][piece.YPosition] = piece;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        board[piece.XPosition][piece.YPosition] = blank;
        XPosition = newX;
        YPosition = newY;
        board[newX][newY] = piece;
        return 1;
    }
    void displayPiece(chessPiece& piece){
        cout << piece.UCode << " " << piece.Title<< endl;
    }
};

void displayBoard(chessPiece board[8][8]){
    int n = 8;
    cout << endl;
    cout << "   --- --- --- --- --- --- --- ---" << endl;
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++){
            if (j == 0){
                cout << n;
                n--;
            }
            cout << " | " << board[j][i].UCode;
            if (j == 7){
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


class kingWh: public chessPiece{
public:
    kingWh(){}
    kingWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2654";
        pieceType = king;
        }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        if (abs(piece.XPosition - newX) <= 1 && abs(piece.YPosition - newY) <= 1){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class kingBl: public chessPiece{
public:
    kingBl(){}
    kingBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265A";
        pieceType = king;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        if (abs(piece.XPosition - newX) <= 1 && abs(piece.YPosition - newY) <= 1){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class queenWh: public chessPiece{
public:
    queenWh(){}
    queenWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2655";
        pieceType = queen;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        if ((x == 0 && y <= 8) || (x <= 8 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 4) || (x == 5 && y == 5) || (x == 6 && y == 6) || (x == 7 && y == 7) || (x == 8 && y == 8)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class queenBl: public chessPiece{
public:
    queenBl(){}
    queenBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265B";
        pieceType = queen;
    
    
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        if ((x == 0 && y <= 8) || (x <= 8 && y == 0) || (x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 4) || (x == 5 && y == 5) || (x == 6 && y == 6) || (x == 7 && y == 7) || (x == 8 && y == 8)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class bishopWh: public chessPiece{
public:
    bishopWh(){}
    bishopWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2657";
        pieceType = bishop;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        if ((x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 4) || (x == 5 && y == 5) || (x == 6 && y == 6) || (x == 7 && y == 7) || (x == 8 && y == 8)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class bishopBl: public chessPiece{
public:
    bishopBl(){}
    bishopBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265D";
        pieceType = bishop;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        if ((x == 1 && y == 1) || (x == 2 && y == 2) || (x == 3 && y == 3) || (x == 4 && y == 4) || (x == 5 && y == 5) || (x == 6 && y == 6) || (x == 7 && y == 7) || (x == 8 && y == 8)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class knightWh: public chessPiece{
public:
    knightWh(){}
    knightWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2658";
        pieceType = knight;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        
        if ((x == 2 && y == 1) || (x == 1 && y == 2)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class knightBl: public chessPiece{
public:
    knightBl(){}
    knightBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265E";
        pieceType = knight;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        
        if ((x == 2 && y == 1) || (x == 1 && y == 2)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class rookWh: public chessPiece{
public:
    rookWh(){}
    rookWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2656";
        pieceType = rook;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        
        if ((x > 1 && y == 0) || (x == 0 && y > 1)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class rookBl: public chessPiece{
public:
    rookBl(){}
    rookBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265C";
        pieceType = rook;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        int x = abs(piece.XPosition - newX);
        int y = abs(piece.YPosition - newY);
        
        if ((x > 1 && y == 0) || (x == 0 && y > 1)){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class pawnWh: public chessPiece{
public:
    pawnWh(){}
    pawnWh(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u2659";
        pieceType = pawn;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        if (moveCount >= 1 && abs(piece.XPosition - newX) <= 0 && abs(piece.YPosition - newY) <= 1){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else if (moveCount < 1 && abs(piece.XPosition - newX) <= 0 && abs(piece.YPosition - newY) <= 2){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class pawnBl: public chessPiece{
public:
    pawnBl(){}
    pawnBl(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        UCode = "\u265F";
        pieceType = pawn;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
    int move(chessPiece& piece, int newX, int newY, chessPiece board[8][8], chessPiece& blank, int moveCount){
        if (moveCount >= 1 && abs(piece.XPosition - newX) <= 0 && abs(piece.YPosition - newY) <= 1){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else if (moveCount < 1 && abs(piece.XPosition - newX) <= 0 && abs(piece.YPosition - newY) <= 2){
            board[piece.XPosition][piece.YPosition] = blank;
            XPosition = newX;
            YPosition = newY;
            board[newX][newY] = piece;
            displayBoard(board);
            return 1;
        } else {
            cout << "Invalid Move" << endl;
            return 0;
        }
    }
};
class blankSpace: public chessPiece{
public:
    blankSpace(){}
    blankSpace(string title, int xPosition, int yPosition):chessPiece(title, xPosition, yPosition){
        Title = "blank";
        UCode = " ";
        pieceType = null;
        XPosition = 0;
        YPosition = 0;
    }
    chessPiece& operator=(const chessPiece& otherPiece){
        XPosition = otherPiece.XPosition;
        YPosition = otherPiece.YPosition;
        UCode = otherPiece.UCode;
        Title = otherPiece.Title;
        pieceType = otherPiece.pieceType;
        return *this;
    }
};

void initBoard(chessPiece board[8][8], chessPiece& blank){
    string blanks = " ";
    for (int i = 0; i <= 7; i++) {
        for (int j = 0; j <= 7; j++){
            board[j][i] = blank;
        }
    }
}




#endif /* Pieces_h */
