//
//  main.cpp
//  CPPChess
//
//  Created by Tyler Phalen on 2/21/22.
//

#include <iostream>
#include "Pieces.h"

using namespace std;

enum xVal {eight, seven, six, five, four, three, two, one};
enum yVal {a, b, c, d, e, f, g, h};

int validateXInput(char xin){
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

int validateYInput(char yin){
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

bool validateSelection(int x, int y, chessPiece board[8][8], chessPiece& blank){
    bool valid = false;
    if (board[x][y].UCode == blank.UCode){
        valid = false;
        cout << "Please select a valid piece." << endl;
    }
    else
        valid = true;
    return valid;
}
bool validateMove(int x, int y, chessPiece board[8][8], chessPiece& blank){
    bool valid = false;
    if (board[x][y].UCode == blank.UCode){
        valid = true;
    }
    else{
        valid = false;
        cout << "Please select a blank space." << endl;
    }
    return valid;
}
int typeConvert(chessPiece selectedPiece){
    int pieceType = null;
    
    return pieceType;
}

int main(){
    chessPiece board[8][8];
    blankSpace blank("blank", 0, 0);
    initBoard(board,blank);
    
    //intitialize and place all white pieces on the board
    kingWh whiteKing("King", e,one);
    whiteKing.place(whiteKing, board);
    queenWh whiteQueen("Queen", d,one);
    whiteQueen.place(whiteQueen, board);
    bishopWh whiteBishop1("Queen's Bishop", c, one);
    whiteBishop1.place(whiteBishop1, board);
    bishopWh whiteBishop2("King's Bishop", f, one);
    whiteBishop2.place(whiteBishop2, board);
    knightWh whiteKnight1("Queen's Knight", b, one);
    whiteKnight1.place(whiteKnight1, board);
    knightWh whiteKnight2("King's Knight", g,one);
    whiteKnight2.place(whiteKnight2, board);
    rookWh whiteRook1("Queen's Rook", a,one);
    whiteRook1.place(whiteRook1, board);
    rookWh whiteRook2("King's Rook", h,one);
    whiteRook2.place(whiteRook2, board);
    pawnWh whitePawn1("Pawn 1", a, two);
    whitePawn1.place(whitePawn1, board);
    pawnWh whitePawn2("Pawn 2", b, two);
    whitePawn2.place(whitePawn2, board);
    pawnWh whitePawn3("Pawn 3", c, two);
    whitePawn3.place(whitePawn3, board);
    pawnWh whitePawn4("Pawn 4", d, two);
    whitePawn4.place(whitePawn4, board);
    pawnWh whitePawn5("Pawn 5", e, two);
    whitePawn5.place(whitePawn5, board);
    pawnWh whitePawn6("Pawn 6", f, two);
    whitePawn6.place(whitePawn6, board);
    pawnWh whitePawn7("Pawn 7", g, two);
    whitePawn7.place(whitePawn7, board);
    pawnWh whitePawn8("Pawn 8", h, two);
    whitePawn8.place(whitePawn8, board);

    //initialize and place all black pieces on the board

    kingBl BlackKing("BlackKing", e, eight);
    BlackKing.place(BlackKing, board);
    queenBl BlackQueen("BlackQueen", d, eight);
    BlackQueen.place(BlackQueen, board);
    bishopBl BlackBishop1("BlackBishop1", c, eight);
    BlackBishop1.place(BlackBishop1, board);
    bishopBl BlackBishop2("BlackBishop2", f, eight);
    BlackBishop2.place(BlackBishop2, board);
    knightBl BlackKnight1("BlackKnight1", b, eight);
    BlackKnight1.place(BlackKnight1, board);
    knightBl BlackKnight2("BlackKnight2", g, eight);
    BlackKnight2.place(BlackKnight2, board);
    rookBl BlackRook1("BlackRook1", a, eight);
    BlackRook1.place(BlackRook1, board);
    rookBl BlackRook2("BlackRook2", h, eight);
    BlackRook2.place(BlackRook2, board);
    pawnBl BlackPawn1("BlackPawn1", a, seven);
    BlackPawn1.place(BlackPawn1, board);
    pawnBl BlackPawn2("BlackPawn2", b, seven);
    BlackPawn2.place(BlackPawn2, board);
    pawnBl BlackPawn3("BlackPawn3", c, seven);
    BlackPawn3.place(BlackPawn3, board);
    pawnBl BlackPawn4("BlackPawn4", d, seven);
    BlackPawn4.place(BlackPawn4, board);
    pawnBl BlackPawn5("BlackPawn5", e, seven);
    BlackPawn5.place(BlackPawn5, board);
    pawnBl BlackPawn6("BlackPawn6", f, seven);
    BlackPawn6.place(BlackPawn6, board);
    pawnBl BlackPawn7("BlackPawn7", g, seven);
    BlackPawn7.place(BlackPawn7, board);
    pawnBl BlackPawn8("BlackPawn8", h, seven);
    BlackPawn8.place(BlackPawn8, board);
    
    displayBoard(board);
    
    //whiteKing.move(whiteKing, f, four, board);
    
    //displayBoard(board);
    
    int keepGoing = -1;
    bool valid = false;
    char xin = 'o';
    char yin = 'o';
    int x = -1;
    int y = -1;
    int w = -1;
    int z = -1;
    int moveCount = 0;
    chessPiece selectedPiece;
    kingWh kingPiece;
    queenWh queenPiece;
    bishopWh bishopPiece;
    knightWh knightPiece;
    rookWh rookPiece;
    pawnWh pawnPiece;
    
    
    
    do{
        do{
            cout << "Input the coordinates of the piece you'd like to move. (9 to quit)" << endl;
            do{
                cout << "x Coordinate (a-h): ";
                cin >> xin;
                keepGoing = validateXInput(xin);
                x = keepGoing;
            } while(keepGoing != 9 && !(keepGoing <= h && keepGoing >= a));
            if (keepGoing == 9){
                valid = false;
                break;
            }
            do{
                cout << "y Coordinate (1-8): ";
                cin >> yin;
                keepGoing = validateYInput(yin);
                y = keepGoing;
            } while (keepGoing != 9 && !(keepGoing >= eight && keepGoing <= one));
            valid = validateSelection(x, y, board, blank);
        }while(valid == false);
        
        
        
        if (valid == true){
            cout << "you selected: ";
            board[x][y].displayPiece(board[x][y]);
            do{
                cout << "Input the coordinates you'd like to move your piece to. (9 to quit)" << endl;
                do{
                    cout << "x Coordinate (a-h): ";
                    cin >> xin;
                    keepGoing = validateXInput(xin);
                    w = keepGoing;
                } while(keepGoing != 9 && !(keepGoing <= h && keepGoing >= a));
                if (keepGoing == 9)
                    break;
                do{
                    cout << "y Coordinate (1-8): ";
                    cin >> yin;
                    keepGoing = validateYInput(yin);
                    z = keepGoing;
                } while (keepGoing != 9 && !(keepGoing >= eight && keepGoing <= one));
                
                valid = validateMove(w, z, board, blank);
            }while(valid == false);
        } else break;
        
        if (valid == true){
            switch (board[x][y].pieceType) {
                case king:
                    kingPiece = board[x][y];
                    moveCount += kingPiece.move(kingPiece, w, z, board, blank, moveCount);
                    break;
                case queen:
                    queenPiece = board[x][y];
                    moveCount += queenPiece.move(queenPiece, w, z, board, blank, moveCount);
                    break;
                case bishop:
                    bishopPiece = board[x][y];
                    moveCount += bishopPiece.move(bishopPiece, w, z, board, blank, moveCount);
                    break;
                case knight:
                    knightPiece = board[x][y];
                    moveCount += knightPiece.move(knightPiece, w, z, board, blank, moveCount);
                    break;
                case rook:
                    rookPiece = board[x][y];
                    moveCount += rookPiece.move(rookPiece, w, z, board, blank, moveCount);
                    break;
                case pawn:
                    pawnPiece = board[x][y];
                    moveCount += pawnPiece.move(pawnPiece, w, z, board, blank, moveCount);
                    break;
                    
                default:
                    break;
            }
        } else break;
        
        
        
    } while (valid == true && keepGoing != 9);
 
    
}
