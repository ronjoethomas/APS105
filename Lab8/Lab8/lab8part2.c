#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

//declaring the functions used
void printBoard(char board[][26], int n);
bool positionInBounds(int n, int row, int col);
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol, bool flipMode);
bool validMoves(char board[][26],char color,int dimensions);
bool validChoice(char board[][26], int n, int row, int col, char colour);
void flipBoard(char board[][26],int dimension,int choseRowInt,int choseColInt,char choseColor, int *score,bool bestMoveCheck);
void convertTestBoardToRealBoard(char board[][26],char testboard[][26],int dimension);
bool topRow(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor);
bool rightCol(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor);
bool leftCol(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor);
bool bottomRow(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor);

int main()

{

//Declaring the board and setting needed variables
char board[26][26];
char testboard[26][26];

bool gameOver=false,blackTurn=true,whiteTurn=false,bestMoveCheck,whiteInvalid=false,blackInvalid=false;
int dimension,turn=1,currentTurnColor,otherColor,*score,totalFlippables=0,computerRow,computerCol,largestFlip=0,smallestFlip=676,oldI=0,oldJ=0,rowAI=0,colAI=0;
char color=0,row,col,choseColor,choseRow,choseCol,computerColor;

//Get the dimensions of the board from the users
printf("Enter the board dimension: ");
scanf("%d",&dimension);

//assign diagonals
board[dimension/2-1][dimension/2-1]='W';
board[(dimension/2)+1-1][(dimension/2)+1-1]='W';
board[(dimension/2)+1-1][dimension/2-1]='B';
board[dimension/2-1][(dimension/2)+1-1]='B';


//Assign Color to computer and outputs starting baord
printf("Computer plays (B/W): ");
scanf(" %c",&computerColor);
printBoard(board,dimension);

score=&totalFlippables;

//main game loop
while(!gameOver){
    //check if gameOver
    if(!validMoves(board,'W',dimension) && !validMoves(board,'B',dimension)){
        gameOver=true;
        
    }
    //
    if(!gameOver){
        
        
        if (turn%2==1){
            currentTurnColor='B';
            otherColor='W';
        }  
        if(turn%2==0){
            currentTurnColor='W';
            otherColor='B';
        }
        
        if(!validMoves(board,currentTurnColor,dimension)){
		    printf("%c player has no valid move.\n",currentTurnColor);
	    }
        
        if(validMoves(board,currentTurnColor,dimension)){
                
        if(currentTurnColor==computerColor){
            smallestFlip=676;
            convertTestBoardToRealBoard(board,testboard,dimension);
            bestMoveCheck=true;
            largestFlip=0;
			int computerMoveBlockRow=50,computerMoveBlockCol=50;
            
            //always take most getting corner move when available
            if(validChoice(board,dimension,0,0,currentTurnColor)||validChoice(board,dimension,dimension-1,dimension-1,currentTurnColor)||validChoice(board,dimension,0,dimension-1,currentTurnColor)||validChoice(board,dimension,dimension-1,0,currentTurnColor)){
                largestFlip=0;
                int row=0,col=0;
                for(int k=0;k<=3;k++) {  
                    if(k==0){row=0;col=0;}
                    if(k==1){row=dimension-1;col=dimension-1;}
                    if(k==2){row=0;col=dimension-1;}
                    if(k==3){row=dimension-1;col=0;}
                    
                    if(validChoice(board,dimension,row,col,currentTurnColor)){
		                *score=0;
		                flipBoard(board,dimension,row,col,currentTurnColor,score,bestMoveCheck);
		                if(*score>largestFlip){
		                    largestFlip=*score;
		                    computerRow=row;
		                    computerCol=col;
		                }
		            }
                }
                smallestFlip=600;
            }
            
            else if(rightCol(dimension,board,testboard,currentTurnColor,otherColor)||leftCol(dimension,board,testboard,currentTurnColor,otherColor)||topRow(dimension,board,testboard,currentTurnColor,otherColor)||bottomRow(dimension,board,testboard,currentTurnColor,otherColor)){
                convertTestBoardToRealBoard(board,testboard,dimension);
                
                if(topRow(dimension, board,testboard,currentTurnColor,otherColor)){
                    for(int j=0;j<dimension;j++){
                        if(validChoice(board,dimension,0,j,currentTurnColor)){
                            convertTestBoardToRealBoard(board,testboard,dimension);
                            flipBoard(testboard,dimension,0,j,currentTurnColor,score,false);
                            if(!(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor))){
                              computerMoveBlockRow=0;
                              computerMoveBlockCol=j;
                              smallestFlip=600;
                                
                            }
        
                        }
        
                    }
                    
                }
                else if(bottomRow(dimension, board,testboard,currentTurnColor,otherColor)){
                    for(int j=0;j<dimension;j++){
                        if(validChoice(board,dimension,dimension-1,j,currentTurnColor)){
                            convertTestBoardToRealBoard(board,testboard,dimension);
                            flipBoard(testboard,dimension,dimension-1,j,currentTurnColor,score,false);
                            if(!(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor))){
                              computerMoveBlockRow=dimension-1;
                              computerMoveBlockCol=j;
                              smallestFlip=600;
                                
                            }
        
                        }
        
                    }
                    
                }
                else if(leftCol(dimension, board,testboard,currentTurnColor,otherColor)){
                    for(int j=0;j<dimension;j++){
                        if(validChoice(board,dimension,j,0,currentTurnColor)){
                            convertTestBoardToRealBoard(board,testboard,dimension);
                            flipBoard(testboard,dimension,j,0,currentTurnColor,score,false);
                            if(!(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor))){
                              computerMoveBlockRow=j;
                              computerMoveBlockCol=0;
                              smallestFlip=600;
                                
                            }
        
                        }
        
                    }
                    
                }
                else if(rightCol(dimension, board,testboard,currentTurnColor,otherColor)){
                    for(int j=0;j<dimension;j++){
                        if(validChoice(board,dimension,j,dimension-1,currentTurnColor)){
                            convertTestBoardToRealBoard(board,testboard,dimension);
                            flipBoard(testboard,dimension,j,dimension-1,currentTurnColor,score,false);
                            if(!(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor))){
                              computerMoveBlockRow=j;
                              computerMoveBlockCol=dimension-1;
                              smallestFlip=600;
                                
                            }
        
                        }
        
                    }
                    
                }
                
                
                
                
            }
         
            
            
            
            
            
            //get the move that allows the opponent to flip the smallest amount of pieces next turn
            if(smallestFlip==676){
				smallestFlip=676;
				//going through to find available moves for computer
                for(int i=0;i<dimension;i++){
		            for(int j=0;j<dimension;j++){
						//checks available moves found
		                
						if(validChoice(board,dimension,i,j,currentTurnColor)){
		                    *score=0;
		                    convertTestBoardToRealBoard(board,testboard,dimension);
		                    flipBoard(testboard,dimension,i,j,currentTurnColor,score,false);
		                    //ensure opponent gets  no corner moves
		                    if(!(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor))){
		                        largestFlip=0;
								int opponentMoveTotal=0;
								//checks all possible moves for this position
		                      for(int k=0;k<dimension;k++){
		                          for(int m=0;m<dimension;m++){
									  if(validChoice(testboard,dimension,k,m,otherColor)){
										opponentMoveTotal++;
		                                *score=0;
		                                 flipBoard(testboard,dimension,k,m,otherColor,score,bestMoveCheck);
		                                if(*score>largestFlip){
		                                largestFlip=*score;
		                                }

		                            }
	                           }
        
                            }
							//if they largestFlip available for the opponent for this computer move is larger than the or equal the existing max (from eg previous move check)
                            if((largestFlip<smallestFlip)&&(opponentMoveTotal!=0)){
                                smallestFlip=largestFlip;
                                computerRow=i;
                                computerCol=j;
                            }
                            //if both locations have the same maximum smallestFlip for opponent then check how many flips I get for each spot
                            if(largestFlip=smallestFlip&&(opponentMoveTotal!=0)){
                                int oldPosScore=0,newPosScore=0;
                                
                                oldI=computerRow;
                                oldJ=computerCol;
		                        flipBoard(board,dimension,oldI,oldJ,currentTurnColor,&oldPosScore,bestMoveCheck);
        		                flipBoard(board,dimension,i,j,currentTurnColor,&newPosScore,bestMoveCheck);
        		                if(oldPosScore<=newPosScore){computerRow=i;computerCol=j;}
        		                if(oldPosScore>=newPosScore){computerRow=oldI;computerCol=oldJ;}

                            }
							if(opponentMoveTotal==0){
								computerMoveBlockRow=i;
								computerMoveBlockCol=j;
                                smallestFlip=0;
							}

		                        
		                   }
		                    
		                    
		                }
	                }
        
                }
            }
            //if all else fails go for the higher flips I get highest flipping move.
            if(smallestFlip==676){

            //going through to find available moves for computer
                for(int i=0;i<dimension;i++){
		            for(int j=0;j<dimension;j++){
						//checks available moves found
		                
						if(validChoice(board,dimension,i,j,currentTurnColor)){
		                    *score=0;
		                    convertTestBoardToRealBoard(board,testboard,dimension);
		                    flipBoard(testboard,dimension,i,j,currentTurnColor,score,false);
		                    //ensure opponent gets  no corner moves
		                    if(true){
		                        largestFlip=0;
								int opponentMoveTotal=0;
								//checks all possible moves for this position
		                      for(int k=0;k<dimension;k++){
		                          for(int m=0;m<dimension;m++){
									  if(validChoice(testboard,dimension,k,m,otherColor)){
										opponentMoveTotal++;
		                                *score=0;
		                                 flipBoard(testboard,dimension,k,m,otherColor,score,bestMoveCheck);
		                                if(*score>largestFlip){
		                                largestFlip=*score;
		                                }

		                            }
	                           }
        
                            }
							//if they largestFlip available for the opponent for this computer move is larger than the or equal the existing max (from eg previous move check)
                            if((largestFlip<smallestFlip)&&(opponentMoveTotal!=0)){
                                smallestFlip=largestFlip;
                                computerRow=i;
                                computerCol=j;
                            }
                            //if both locations have the same maximum smallestFlip for opponent then check how many flips I get for each spot
                            if(largestFlip=smallestFlip&&(opponentMoveTotal!=0)){
                                int oldPosScore=0,newPosScore=0;
                                
                                oldI=computerRow;
                                oldJ=computerCol;
		                        flipBoard(board,dimension,oldI,oldJ,currentTurnColor,&oldPosScore,bestMoveCheck);
        		                flipBoard(board,dimension,i,j,currentTurnColor,&newPosScore,bestMoveCheck);
        		                if(oldPosScore<=newPosScore){computerRow=i;computerCol=j;}
        		                if(oldPosScore>=newPosScore){computerRow=oldI;computerCol=oldJ;}

                            }
							if(opponentMoveTotal==0){
								computerMoveBlockRow=i;
								computerMoveBlockCol=j;
                                smallestFlip=0;
							}

		                        
		                   }
		                    
		                    
		                }
	                }
        
                }
            }
            //flipBoard based on best computer move
			if((computerMoveBlockRow!=50)&&(computerMoveBlockCol!=50)){
            printf("Computer places %c at %c%c.\n",currentTurnColor,computerMoveBlockRow+97,computerMoveBlockCol+97);
            flipBoard(board,dimension,computerMoveBlockRow,computerMoveBlockCol,currentTurnColor,score,false);
            }
			else{
			printf("Computer places %c at %c%c.\n",currentTurnColor,computerRow+97,computerCol+97);
            flipBoard(board,dimension,computerRow,computerCol,currentTurnColor,score,false);
			}
            
        }
        if(currentTurnColor!=computerColor){
            bestMoveCheck=false;
            printf("Enter move for colour %c (RowCol): ",currentTurnColor);
                scanf(" %c%c",&choseRow,&choseCol);
                int choseRowInt=choseRow-97;
                int choseColInt=choseCol-97;
                if(validChoice(board,dimension,choseRowInt,choseColInt,currentTurnColor)){
                    flipBoard(board,dimension,choseRowInt,choseColInt,currentTurnColor,score,false);

                }
                else if(!validChoice(board,dimension,choseRowInt,choseColInt,currentTurnColor)){
                    printf("Invalid move.\n");
					if(currentTurnColor=='W'){whiteInvalid=true;}
					else if(currentTurnColor=='B'){blackInvalid=true;}
                    gameOver=true;
					break;
                }
            
          
        
        }
		
	printBoard(board,dimension);	
        
    }
        

        turn++;    
}
}
//checking results of the game
int blackCounter=0,whiteCounter=0;

	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
			if(board[i][j]=='W'){
				whiteCounter++;
			}
			if(board[i][j]=='B'){
				blackCounter++;
			}
			
		}
	}
	if(whiteInvalid){printf("B player wins.\n");}
	else if(blackInvalid){printf("W player wins.\n");}
	else if(whiteCounter<blackCounter){printf("B player wins.\n");}
	else if(whiteCounter>blackCounter){printf("W player wins.\n");}
	else if(whiteCounter==blackCounter){printf("Draw!");}


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
			
			//If the location has either a W or B print that
            if(board[i-1][j-1]=='W'||board[i-1][j-1]=='B'){
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
bool checkLegalInDirection(char board[][26], int n, int row, int col, char colour, int deltaRow, int deltaCol,bool flipMode){

//while position inbound do this loop
while(positionInBounds(n,row+deltaRow,col+deltaCol)){
	
	//if the position already picked return false
    if((board[row][col]=='W'||board[row][col]=='B')&&!flipMode){
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


//function that checks if any valid moves are present
bool validMoves(char board[][26],char color,int dimension){
	for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
		if(validChoice(board,dimension,i,j,color)){
		   return true;
		}
	}

}
return false;
}

//Checks all 8 directions and if there is a valid move in any of them, return true that a valid move exists
bool validChoice(char board[][26], int dimensions, int row, int col, char color){
    if(checkLegalInDirection(board,dimensions,row,col,color,0,1,false)||checkLegalInDirection(board,dimensions,row,col,color,0,-1,false)
	||checkLegalInDirection(board,dimensions,row,col,color,1,0,false)||checkLegalInDirection(board,dimensions,row,col,color,-1,0,false)||
	checkLegalInDirection(board,dimensions,row,col,color,1,1,false)||checkLegalInDirection(board,dimensions,row,col,color,-1,-1,false)||
	checkLegalInDirection(board,dimensions,row,col,color,1,-1,false)||checkLegalInDirection(board,dimensions,row,col,color,-1,1,false)){
    return true;
}
    return false;
    
}

void flipBoard(char board[][26],int dimension,int choseRowInt,int choseColInt,char choseColor, int *score, bool checkBestMove){
int flips=0;
if(validChoice(board,dimension,choseRowInt,choseColInt,choseColor)){
    
    if(!checkBestMove){board[choseRowInt][choseColInt]=choseColor;}
   
	//Check all 8 directions and if a valid move in any of these directions, goes through direction and flips the color to the chosen color while the color in the row is not the chosen color.
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,0,1,true)){
        int i=1;
        while(board[choseRowInt][choseColInt+i]!=choseColor){
            
            if(!checkBestMove){board[choseRowInt][choseColInt+i]=choseColor;}
            i++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,0,-1,true)){
        int i=1;
        while(board[choseRowInt][choseColInt-i]!=choseColor){
            if(!checkBestMove){board[choseRowInt][choseColInt-i]=choseColor;}
            i++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,0,true)){
        int j=1;
        while(board[choseRowInt+j][choseColInt]!=choseColor){
            if(!checkBestMove){board[choseRowInt+j][choseColInt]=choseColor;}
            j++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,0,true)){
        int j=1;
        while(board[choseRowInt-j][choseColInt]!=choseColor){            
            if(!checkBestMove){board[choseRowInt-j][choseColInt]=choseColor;}
            j++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,1,true)){
        int i=1;
        int j=1;
        while(board[choseRowInt+j][choseColInt+i]!=choseColor){
            if(!checkBestMove){board[choseRowInt+j][choseColInt+i]=choseColor;}
            i++;
            j++;
           flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,-1,true)){
         int i=1;
         int j=1;
         while(board[choseRowInt-j][choseColInt-i]!=choseColor){
            if(!checkBestMove){board[choseRowInt-j][choseColInt-i]=choseColor;}
            i++;
            j++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,-1,1,true)){
        int i=1;
        int j=1;
        while(board[choseRowInt-j][choseColInt+i]!=choseColor){
            if(!checkBestMove){board[choseRowInt-j][choseColInt+i]=choseColor;}
            i++;
            j++;
            flips++;
        }
    }
    if(checkLegalInDirection(board,dimension,choseRowInt,choseColInt,choseColor,1,-1,true)){
        int i=1;
        int j=1;
        while(board[choseRowInt+j][choseColInt-i]!=choseColor){
            if(!checkBestMove){board[choseRowInt+j][choseColInt-i]=choseColor;}
            i++;
            j++;
            flips++;
        }
    }
}
*score=flips;

return;
}

//
void convertTestBoardToRealBoard(char board[][26],char testboard[][26],int dimension){
    for(int i=0;i<dimension;i++){
		for(int j=0;j<dimension;j++){
		    testboard[i][j]=board[i][j];
		
			}
    }
    
}


bool topRow(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor){
    int score=0;
    for(int j=0;j<dimension;j++){
        if(validChoice(board,dimension,0,j,currentTurnColor)){
            convertTestBoardToRealBoard(board,testboard,dimension);
            flipBoard(testboard,dimension,0,j,currentTurnColor,&score,false);
            if(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor)){
                return false;
            }
            return true;
        }
        
    }
    return false;
    
}

bool bottomRow(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor){
    int score=0;
    for(int j=0;j<dimension;j++){
        if(validChoice(board,dimension,dimension-1,j,currentTurnColor)){
            convertTestBoardToRealBoard(board,testboard,dimension);
            flipBoard(testboard,dimension,dimension-1,j,currentTurnColor,&score,false);
            if(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor)){
                return false;
            }
            return true;
        }
        
    }
    return false;
    
}

bool leftCol(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor){
    int score=0;
    for(int j=0;j<dimension;j++){
        if(validChoice(board,dimension,j,0,currentTurnColor)){
            convertTestBoardToRealBoard(board,testboard,dimension);
            flipBoard(testboard,dimension,j,0,currentTurnColor,&score,false);
            if(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor)){
                return false;
            }
            return true;
            
        }
        
    }
    return false;
    
}
bool rightCol(int dimension, char board[][26],char testboard[][26],int currentTurnColor,int otherColor){
    int score=0;
    for(int j=0;j<dimension;j++){
        if(validChoice(board,dimension,j,dimension-1,currentTurnColor)){
            convertTestBoardToRealBoard(board,testboard,dimension);
            flipBoard(testboard,dimension,j,dimension-1,currentTurnColor,&score,false);
            if(validChoice(testboard,dimension,0,0,otherColor)||validChoice(testboard,dimension,dimension-1,dimension-1,otherColor)||validChoice(testboard,dimension,0,dimension-1,otherColor)||validChoice(testboard,dimension,dimension-1,0,otherColor)){
                return false;
            }
            return true;
            
        }
        
    }
    return false;
    
}


