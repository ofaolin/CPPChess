# CPPChess
A command line chess game using ascii and unicode
 - There is now a seperate class for the chess game and one for the pieces
 - The chess game class contains the board and most of the game logic
 - the chess piece class contains all the information for each piece including their locations on the board, etc
 - the game is able to be saved and will ask if you would like to save the game upon quitting (9)
 - you can only have one save file at a time, so the game will automatically load the last saved game if you choose that option at start
 - All the pieces now move correctly and cannot jump each other if they are not a knight
 - if a piece is able to legally occupy a square occupied by the opposite team, then that piece will be deleted
 - the game checks for win conditions (ie one king remaining) each time a piece is moved
 - either white pieces or black pieces can be moved on any turn (the game does not yet enforce turns)
