/******************************************************************************

The board consists of a 20x20 grid
It is a 2 player game (R && B)

If a piece becomes surrounded by 2 opposing pieces on opposite sides
the piece is considered captured and is removed from the board.

Oposing piece may only be caputured on their turn.

Objective
Capture 5 pieces
having 5 active pieces in a row (diagnally, horizontally or vertically)

*******************************************************************************/
#include <stdio.h>

int boardWidth = 20;
int boardHeight = 20;
enum Piece {red, blue, blank};
bool redPlayerTurn = false;
Piece board[boardHeight][boardWidth];
int redScore = 0;
int blueScore = 0;

void clearBoard() {
    for(int i = 0; i < boardHeight; i++) {
        for(int j = 0; j < boardHeight; j++) {
            board[i][j] = blank;
        }    
    }    
}

void placePice(Piece p, int x, int y) {
    board[x][y] = p;
}

void printBoard() {
    for(int i = 0; i < boardHeight; i++){
        for(int j = 0; j < boardHeight; j++){
            
        }
    }
}

int main()
{
    printf("Hello World");

    return 0;
}