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

using namespace std;

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

// this function converts letter number coordinates to x,y.
void makeMove(string letter, int number){
    int x;
    int y = number;
    int asciiVal = letter[0];
    if(asciiVal > 96) {
        x = asciiVal - 97;
    } else {
        x = asciiVal - 65;
    }
    if(redPlayerTurn) {
        placePiece(red, x, y);
    } else {
        placePiece(blue, x, y);
    }
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

// turnGenerator returns true if player1 is the red player.
bool turnGenerator(){
	srand((unsigned int)time(NULL));
	int random = rand() % 2;
	return random == 1;
}

int main()
{
	string name1;
	string name2;
	
	clearBoard();
    printBoard();
	bool hasLoser = false;
	
	printf("Hows it going diggity dogs.\n");
	printf("Welcome to the PENTE.\n");
	printf("Player 1 please enter your name.");
	cin >> name1;
	printf("Player 2 please enter your name.");
	cin >> name2;

    bool player1IsRed = turnGenerator();	
	cout << "Hello " << name1 << ", you are red.\n";
	cout << "Hello " << name2 << ", you are blue.\n";
    string whosTurn;

    string letterCoordinate;
    int numberCoordinate;

	while(!hasLoser) {
	    if(redPlayerTurn) {
	        whosTurn = "red";
	    } else {
	        whosTurn = "blue";
	        
	    }
	    printBoard();
	    cout << "player "<< whosTurn <<"enter your letter coordinate.";
	    while (!(cin >> letterCoordinate) && 
	    (letterCoordinate[0] >= 6 && letterCoordinate[0] <= 84) ||
	    (letterCoordinate[0] >= 97 && letterCoordinate[0] <= 116))
    	{
    		cin.clear();
    		cin.ignore(1000, '\n');
    		cout << "Invalid input. Please enter a valid letter between A and T." << endl;
    	}
		cout << "player "<< whosTurn <<"enter your number coordinate.";
		while (!(cin >> numberCoordinate) && numberCoordinate > 0 && numberCoordinate < 21)
    	{
    		cin.clear();
    		cin.ignore(1000, '\n');
    		cout << "Invalid input. Please enter a number between 1 and 20." << endl;
    	}
		
		makeMove(letterCoordinate, numberCoordinate - 1);
		
		hasLoser = true;
	}

    return 0;
}