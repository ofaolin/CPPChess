//
//  main.cpp
//  CPPChess
//
//  Created by Tyler Phalen on 2/21/22.
// 
//  build with clang: clang++ -std=c++11 main.cpp chessGame.cpp Piece.cpp -o chessGame


/* READ ME
 
 - This is my battle project but almost completely rewritten
 - There is now a seperate class for the chess game and one for the pieces
 - The chess game class contains the board and most of the game logic
 - the chess piece class contains all the information for each piece including their locations on the board, etc
 - the game is able to be saved and will ask if you would like to save the game upon quitting (9)
 - you can only have one save file at a time, so the game will automatically load the last saved game if you choose that option at start
 - All the pieces now move correctly and cannot jump each other if they are not a knight
 - if a piece is able to legally occupy a square occupied by the opposite team, then that piece will be deleted
 - the game checks for win conditions (ie one king remaining) each time a piece is moved
 - either white pieces or black pieces can be moved on any turn (the game does not yet enforce turns)
 
 */


#include "chessGame.h"

int main(){
    chessGame game;
    int select = -1;
    int keepGoing = -1;
    bool gameEnd = false;
    bool valid = false;
    char xin = 'o';
    char yin = 'o';
    coordinates XY;
    coordinates newXY;
    
    do{
        game.displayTitle();
        cout << "0. Quit." << endl;
        cout << "1. Load Save Game." << endl;
        cout << "2. Start New Game." << endl;
        cout << "Make a selection: ";
        cin >> select;
        switch (select) {
            case 0:
                keepGoing = 9;
                break;
            case 1: {
                queue<chessPiece> pieceQ;
                game.loadSave(pieceQ);
                game.displayBoard();
                break;
            }
            case 2: game.displayBoard();
                break;
            default: cout << "Please make a valid selection." << endl;
                break;
        }
    } while(select < 0 || select > 2);
    
    do{
        do{
            cout << "Input the coordinates of the piece you'd like to move. (9 to quit)" << endl;
            do{
                cout << "XY Coordinate (a-h)(1-8): ";
                cin >> xin;
                keepGoing = game.validateXInput(xin);
                XY.x = keepGoing;
            } while(keepGoing != 9 && !(keepGoing <= h && keepGoing >= a));
            if (keepGoing == 9){
                valid = false;
                break;
            }
            do{
                cin >> yin;
                keepGoing = game.validateYInput(yin);
                XY.y = keepGoing;
            } while (keepGoing != 9 && !(keepGoing >= eight && keepGoing <= one));
            valid = game.validateSelection(XY);
            if (valid == true){
                cout << "you selected: ";
                game.displayPiece(XY);
                cout << "Input the coordinates you'd like to move your piece to. (9 to quit)" << endl;
                do{
                    cout << "XY Coordinate (a-h)(1-8): ";
                    cin >> xin;
                    keepGoing = game.validateXInput(xin);
                    newXY.x = keepGoing;
                } while(keepGoing != 9 && !(keepGoing <= h && keepGoing >= a));
                if (keepGoing == 9)
                    break;
                do{
                    cin >> yin;
                    keepGoing = game.validateYInput(yin);
                    newXY.y = keepGoing;
                } while (keepGoing != 9 && !(keepGoing >= eight && keepGoing <= one));
                valid = game.validateMove(game.board[XY.x][XY.y],game.board[newXY.x][newXY.y]);
            }
        }while(valid == false);
        
        if (valid == true){
            game.move(XY, newXY);
            game.displayBoard();
            gameEnd = game.checkWin();
        }
    } while (valid == true && keepGoing != 9 && gameEnd == false);
    do {
        if (keepGoing == 9) {
            select = -1;
            cout << "would you like to save the game?" << endl;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "?: ";
            cin >> select;
            switch (select) {
                case 1:{
                    cout << "Saving..." << endl;
                    ofstream fout("chessSaveFile.txt", ios::out);
                    for (int y = 0; y <= 7; y++) {
                        for (int x = 0; x <= 7; x++){
                            fout << game.board[x][y];
                        }
                    }
                    cout << "Goodbye!";
                    break;
                }
                case 2:{
                    cout << "Goodbye!";
                    break;
                }
                default:
                    cout << "Please Make a valid selection.";
                    break;
            }
        }
    }while(select != 1 && select !=2);
    
}
