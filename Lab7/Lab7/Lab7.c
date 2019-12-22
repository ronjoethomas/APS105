#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//declaring the functions used
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol);
void validMoves(char board[][26],char color,int dimensions);
bool validChoice(char board[][26], int n, int row, int col, char colour);

int main()

{

//Declaring the board
char board[26][26];
int dimension;
char color=0,row,col,choseColor,choseRow,choseCol;

//Get the dimensions of the board from the users
printf("Enter the board dimension: ");
scanf("%d",&dimension);
printBoard(board,dimension);

//Assign user inputed configuration to board
printf("Enter board configuration: \n");
do{
	scanf(" %c%c%c",&color,&row,&col);
	if(color!='!'&&row!='!'&&col!='!'){
		board[row-97][col-97]=color;
	}
}while(color!='!'&&row!='!'&&col!='!');
printBoard(board,dimension);

//gets valid moves from the board configurations for each player then ask to enter a new move
validMoves(board,'W',dimension);
validMoves(board,'B',dimension);
printf("Enter a move:\n");
scanf(" %c%c%c",&choseColor,&choseRow,&choseCol);

//convert chosen Row in alphabets to interger equivilant on the baord.
int choseRowInt=choseRow-97;
int choseColInt=choseCol-97;

//If user inputed a valid choice, go through this if statement
if(validChoice(board,dimension,choseRowInt,choseColInt,choseColor)){
    printf("Valid move.\n");
	
	//Check all 8 directions and if a valid move in any of these directions, goes through direction and flips the color to the chosen color while the color in the row is not the chosen color.
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,0,1)){
        int i=choseColInt;
        while(board[choseRowInt][i]!=choseColor){
            board[choseRowInt][i]=choseColor;
            i++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,0,-1)){
        int i=choseColInt;
        while(board[choseRowInt][i]!=choseColor){
            board[choseRowInt][i]=choseColor;
            i--;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,0)){
        int j=choseRowInt;
        while(board[j][choseColInt]!=choseColor){
            board[j][choseColInt]=choseColor;
            j++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,0)){
        int j=choseRowInt;
        while(board[j][choseColInt]!=choseColor){            
            board[j][choseColInt]=choseColor;
            j--;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,1)){
        int i=choseColInt;
        int j=choseRowInt;
        while(board[j][i]!=choseColor){
            board[j][i]=choseColor;
            i++;
            j++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,-1)){
             int i=choseColInt;
         int j=choseRowInt;
         while(board[j][i]!=choseColor){
            board[j][i]=choseColor;
            i--;
            j--;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,1)){
        int i=choseColInt;
        int j=choseRowInt;
        while(board[j][i]!=choseColor){
            board[j][i]=choseColor;
            i++;
            j--;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,-1)){
        int i=choseColInt;
        int j=choseRowInt;
        while(board[j][i]!=choseColor){
            board[j][i]=choseColor;
            i--;
            j++;
        }
    }
}
//if invalid move print invalid.
else{
     printf("Invalid move.\n");
}
	printBoard(board,dimension);

    return 0;
}

//function  that prints board
void printBoard(char board[][26], int n){
    printf("  ");
	//prints top alpabetic row
    for (int i=0;i<n;i++){
        printf("%c",'a'+i);
    }
    printf("\n");
	
	//prints the board configuration,goes through row
    for (int i=1; i<=n;i++){
        printf("%c ",'a'+(i-1));
        //
        for(int j=1;j<=n;j++){
			
			//for the diagonals intializing them for white
            if(((n/2==i)&&(n/2==j)) || ((((n/2)+1==i))&&((n/2)+1)==j) && board[i-1][j-1]!='B'){
				board[i-1][j-1]='W';
				printf("%c",board[i-1][j-1]);
            }
			//intializing the diagonals for Black
            else if(((n/2==i)&&((n/2)+1==j))||((((n/2)+1)==i)&&(n/2==j))&&board[i-1][j-1]!='W'){
                board[i-1][j-1]='B';
                printf("%c",board[i-1][j-1]);
            }
			//If the location has either a W or B print that
            else if(board[i-1][j-1]=='W'||board[i-1][j-1]=='B'){
                printf("%c",board[i-1][j-1]);

            }
			//if no W or B print U
            else{
                board[i-1][j-1]='U';
                printf("%c",board[i-1][j-1]);
            }
        } 
        printf("\n");
    }
}

//check if position is inbound
bool positionInBounds(int n, int row, int col){
	int endBoundary=n-1;
	if(row>=0&&row<=endBoundary&&col>=0&&col<=endBoundary){
		return true;
	}
return false;
}

//Function checks if the direction given the the parameter is legal
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol){

//while position inbound do this loop
while(positionInBounds(n,row+deltaRow,col+deltaCol)){
	
	//if the position already picked return false
    if(board[row][col]=='W'||board[row][col]=='B'){
        return false;
    }
	//if the next position in that direction is U return false
	if(board[row+deltaRow][col+deltaCol]=='U'||board[row+deltaRow][col+deltaCol]==colour){
		return false;
	}
	//if next position is not the current colour and its not a U, then go through this loop
	else if(board[row+deltaRow][col+deltaCol]!=colour&&board[row+deltaRow][col+deltaCol]!='U'){
		
		while(positionInBounds(n,row+deltaRow,col+deltaCol)){
			
			//when it reaches the current colour again (after success fully going through the given direction) return true as a valid move
			if(board[row+deltaRow][col+deltaCol]==colour){
				return true;
			}
			//ensures it is a continous line of of opposite color
			if(board[row+deltaRow][col+deltaCol]=='U'&&board[row+deltaRow][col+deltaCol]!=colour){
				return false;
			}
			
			//goes through the current direction indicated in the parameters of the function
			if(deltaRow==0&&deltaCol>=1){
				deltaCol++;
			}	
			if(deltaRow==0&&deltaCol<=-1){
				deltaCol--;
			}
			if(deltaRow>=1&&deltaCol==0){
				deltaRow++;
			}
			if(deltaRow<=-1&&deltaCol==0){
				deltaRow--;

			}
			if(deltaRow>=1&&deltaCol>=1){
				deltaCol++;
				deltaRow++;
			}
			if(deltaRow<=-1&&deltaCol<=-1){
				deltaCol--;
				deltaRow--;
			}
			if(deltaRow>=1&&deltaCol<=-1){
				deltaCol--;
				deltaRow++;
			}
			if(deltaRow<=-1&&deltaCol>=1){
				deltaCol++;
				deltaRow--;
			}
		}
	return false;
	}
	}
return false;
}


//function that prints all the valid moves for this function
void validMoves(char board[][26],char color,int dimension){
printf("Available moves for %c: \n",color);
	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
		if(validChoice(board,dimension,i,j,color)){
		printf("%c%c\n",i+97,j+97);
		}
	}

}
return;
}

//Checks all 8 directions and if there is a valid move in any of them, return true that a valid move exists
bool validChoice(char board[][26], int dimensions, int row, int col, char color){
    if(checkLegalInDirection(board,dimensions,row,col,color,0,1)||checkLegalInDirection(board,dimensions,row,col,color,0,-1)
	||checkLegalInDirection(board,dimensions,row,col,color,1,0)||checkLegalInDirection(board,dimensions,row,col,color,-1,0)||
	checkLegalInDirection(board,dimensions,row,col,color,1,1)||checkLegalInDirection(board,dimensions,row,col,color,-1,-1)||
	checkLegalInDirection(board,dimensions,row,col,color,1,-1)||checkLegalInDirection(board,dimensions,row,col,color,-1,1)){
    return true;
}
    return false;
    
}
