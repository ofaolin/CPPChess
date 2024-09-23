//
//  chessgame.h
//  CPPChess
//
//  Created by Tyler Phalen on 2/21/22.
//

#ifndef chessGame_h
#define chessGame_h

#include <iostream>
#include <ostream>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>

using namespace::std;

enum pieceTypes {blank, king, queen, bishop, knight, rook, pawn};
//enum for human readable piece types
enum pieceColors {null, white, black};
//enum for human readable piece colors
enum xVal {eight, seven, six, five, four, three, two, one};
//enum for values of x on the chess board because the x values of the 3d array are opposite what a chess board should be
enum yVal {a, b, c, d, e, f, g, h};
//enum for values of y on the chess board because the x values of a a chess board should be letters

struct coordinates{
    //struct for board coordinates (x and y values)
    int x = NULL;
    int y = NULL;
    coordinates& operator=(const coordinates& otherXy){
        x = otherXy.x;
        y = otherXy.y;
        return *this;
    }
};
class chessPiece{
    //a class that holds all info of each piece
public:
    string Title;
    string UCode;
    int pieceType;
    int pieceColor;
    coordinates XY;
    bool alive = true;
    chessPiece();
    chessPiece(int Type, int color, coordinates xy);
    bool move(chessPiece* piece, chessPiece* destination, int moveCount);
    void displayPiece();
    chessPiece& operator=(const chessPiece& otherPiece){
        Title = otherPiece.Title;
        UCode = otherPiece.UCode;
        pieceType = otherPiece.pieceType;
        pieceColor = otherPiece.pieceColor;
        XY = otherPiece.XY;
        alive = otherPiece.alive;
        return *this;
    }
    friend ostream& operator<< (ostream &out,const chessPiece &piece){
        out << piece.UCode << "," << piece.pieceType << "," << piece.pieceColor << "," << piece.XY.x  << "," << piece.XY.y << "," << piece.Title << "\n";
        return out;
    }
};
class chessGame{
    //the main class of the chess game, hold the chess board and all game mechanics
private:
    int moveCount = 0;
    chessPiece Blank;
    ifstream saveFile;
public:
    chessPiece board[8][8];
    chessGame();
    void move(coordinates XY, coordinates newXY);
    void loadSave(queue<chessPiece> pieceQ);
    void displayBoard();
    void displayTitle();
    void displayPiece(coordinates XY);
    int validateYInput(char yin);
    int validateXInput(char xin);
    bool validateSelection(coordinates XY);
    bool validateMove(chessPiece selectedPiece, chessPiece destPiece);
    bool checkWin();
};

#endif /* chessGame_h */
