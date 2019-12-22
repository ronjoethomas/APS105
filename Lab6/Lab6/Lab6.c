#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//declaration of functions used in game
void printBoard(int board[], int playerA, int playerB);
int requestValidInput(int board[], int playerA, int playerB);
int checkForWinner(int board[], int playerA, int playerB);


int main(void)
{
    //initializes the game board and all the variables used
    int board[9]={1,2,3,4,5,6,7,8,9};
    
	//initializing all the variables used
    bool playerATurn=true;
    bool playerBTurn;
    bool gameOver=false;
    int playerA=65;
    int playerB=66;
    int totalTurns=0;
    int input=0;
    int winner=0;
    
    //shows intial state of the game board
    printf("The current state of the Tic-tac-toe Board:\n\n");
    printBoard(board,playerA,playerB);
    
    //main loop that continues as no winners and total turns is less or equal to 9.
    while (!gameOver&&(totalTurns<=8)){
        
        //when it is player A's turn go to this loop
        while(playerATurn&&!gameOver&&totalTurns<=8){
			//gets input from player A and increases total turns
            printf("\nIt is Player A's turn.\n");
            input=requestValidInput(board,playerA,playerB);
            board[input-1]=playerA;
            totalTurns++;
            
			//checks if player A won
			winner= checkForWinner(board,playerA,playerB);
            
            if (winner==playerA){
                gameOver=true;
				printf("Player A wins!\n\n");
				printBoard(board,playerA,playerB);

				return 0;
                
            }
			//checks if all 9 positions have been played and  player A did not win
			if((totalTurns>8)&&(winner!=playerA)){
				printf("It's a draw!\n\n");
				printBoard(board,playerA,playerB);
				return 0; 
			}
			
			printf("The current state of the Tic-tac-toe Board:\n\n");
            printBoard(board,playerA,playerB);
			//ends player A's turn and starts player B's turn
            playerBTurn=true;
            playerATurn=false;


            
        }
		//player B's turn
        while(playerBTurn&&!gameOver&&(totalTurns<=8)){
			//gets valid input for player Bb
            printf("\nIt is Player B's turn.\n");
            input=requestValidInput(board,playerA,playerB);
            board[input-1]=playerB;
            totalTurns++;
            
			//checks for winner or tie (at which case game ends)
			winner= checkForWinner(board,playerA,playerB);
            if (winner==playerB){
                gameOver=true;
				printf("Player B wins!\n\n");
				printBoard(board,playerA,playerB);
				return 0;

            }
			if((totalTurns>8)&&(winner!=playerB)){
				printBoard(board,playerA,playerB);
				printf("It's a draw!\n\n");
				return 0;
			}
			printf("The current state of the Tic-tac-toe Board:\n\n");
            printBoard(board,playerA,playerB);
            //sets player B turn to be false and starts player A turn
			playerATurn=true;
            playerBTurn=false;

            
        }
        
        
		}
    
printBoard(board,playerA,playerB);    
return 0;
}

void printBoard(int board[], int playerA, int playerB){
    
    for (int i=0; i<9; i++){
        //if the value in the location of the board is either value assigned for player A or B, display there corresponding letters
		if(board[i]==playerA){
            printf(" A");
        }
        else if(board[i]==playerB){
            printf(" B");
        }
        else{
            printf(" %d",board[i]);
            
        }
		//going to next row
        if(i==2||i==5||i==8){
            printf("\n");
        }
    }
}

int requestValidInput(int board[], int playerA, int playerB){
    printf("Please enter a valid position to play.\n");
    int input=0;
    
    do{
		//check if location is within board
        scanf("%d",&input);
        if((input>9)||(input<1)){
            printf("Invalid input, please try again.\n");
            
        }
		//check if the position has already been played
        if((board[input-1]==playerA)||(board[input-1]==playerB)){
            printf("That position has already been played, please try again.\n");
        }
        
     //continue loop until valid position played   
    }while((input>9)||(input<1)||(board[input-1]==playerA)||(board[input-1]==playerB));
    
    return input;
}

int checkForWinner(int board[], int playerA, int playerB){
    //horizonal  checks
    for(int i=0;i<9;i=i+3){
        if((board[0+i]==board[1+i])&&(board[2+i]==board[1+i])){
            return board[0+i];//returns the value
        }
    //vertical checks
    }
    for(int i=0; i<3;i++){
        if((board[0+i]==board[3+i])&&(board[6+i]==board[3+i])){
            return board[0+i];//retuns the value.
    }
    
    }
    // diagonal checks
    for (int i=0;i<3;i=i+2){
        if((board[0+i]==board[4])&&(board[8-i]==board[4])){
            return board[0+i];//returns the value
        }
    }
    
    return 0;
    
}
