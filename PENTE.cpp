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
#include <iostream>
#include <string>

int boardWidth = 20;
int boardHeight = 20;
enum Piece {
	red, 
	blue, 
	blank
};
bool redPlayerTurn = false;
Piece board[20][20];
int redScore = 0;
int blueScore = 0;

void clearBoard() {
    for(int i = 0; i < boardHeight; i++) {
        for(int j = 0; j < boardHeight; j++) {
            board[i][j] = blank;
        }    
    }    
}

void placePiece(Piece p, int x, int y) {
    board[x][y] = p;
}

void printBoard() {
	printf("   A B C D E F G H I J K L M N O P Q R S T\n");
    for(int i = 0; i < boardHeight; i++){
		if(i + 1 > 9){
			printf("%d ", i + 1);
		} else {
			printf(" %d ", i + 1);
		}
        for(int j = 0; j < boardWidth; j++){
			if(board[i][j] == red) {
				printf("%c ", 'R');	
			} else if (board[i][j] == blue){
				printf("%c ", 'B');
			} else {
				printf("%c ", '+');	
			}
        }
		printf("\n");
    }
}

bool turnGenerator(){
	
}

int main()
{
	string name1;
	string name2;
	
	clearBoard();
    printBoard();
	bool hasLoser = false;
	while(!hasLoser){
		printf("Hows it going diggity dogs.\n");
		printf("Welcome to the PENTE.\n");
		printf("Player 1 please enter your name.");
		cin >> name1
		printf("Player 2 please enter your name.");
		cin >> name2
		
		
	}

    return 0;
}