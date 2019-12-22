#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

//intialize the functions used
int rollDice(void);
bool playGame(void);
void winLoss(void);

/*
int main(void)
{
    winLoss();  
    return 0;
}
*/

//generates and returns a sum of 2 random numbers from 0 to 6
int rollDice(void){
   int sum=(rand()%6+1)+(rand()%6+1);

   return sum;
    
}

//play one game
bool playGame(void){
    
    int sum;
    
    //gets a random value from 0 to 12
    sum=rollDice();
    
    printf("You rolled: %d\n", sum);
    
    //if sum is 7 or 11 wins game
    if (sum==7||sum==11){
        return true;
            
        
    }
    //if sum is 2 3 or 12 losses game
    else if (sum==2||sum==3||sum==12){
           return false;
    }
    
    //if sum is not 2 3 12 11 or 7 stores it as a point
    else {
        
        printf("Your point is: %d\n",sum);
        int point=sum;
        
        //continues generating random numbers untill it equals 7(lose) or point(win)
        do{
            sum=rollDice();
            printf("You rolled: %d\n", sum);
        }while(sum!=7&&sum!=point);
        
        if (sum==point){
     
            return true;
       
        
        }
        
        if (sum==7){
         return false;
       }
       
    }
    return 0;
    }


void winLoss(void){
    
    int wins=0;
    int losses=0;
    char continuePlay;
    
    //keeps playing games until the user enters something other than y or Y when asked to play again.
    do{
        
        //if playGame() == true (wins game) then increases wins and prints you win.
        if (playGame()){
            wins++;
            printf("You win!\n");
            
        }
        
        //if playGame()==false (loses game) then increases losses and prints you lose.
        else{
            losses++;
            printf("You lose!\n");
        }
        
        printf("Play again? ");
        //scans to see if user wants to play again
        scanf(" %c",&continuePlay);
        
        
    }while(continuePlay=='y'||continuePlay=='Y');
    
    
    //prints total wins and losses after end of game
    printf("\nWins: %d\n",wins);
    printf("Losses: %d\n",losses);
}
