#include <stdio.h>

//intialize the functions used
void inputDate(int *day, int *month, int *year);
void calculateDay(int day, int month, int year);

/*
int main(void)
{
    int day;
    int month;
    int year;
   
    inputDate(&day,&month,&year);
    calculateDay(day,month,year);
    return 0;
    
}
*/

//function scans and stores values of day month and year
void inputDate(int *day, int *month, int *year){
    printf("Please enter a date: ");
    scanf("%d/%d/%d",day,month,year);
    return;
   
    }

        
//function calculates the week day of the date provided        
void calculateDay(int day, int month, int year){
    int A,B,C,D;
    int yearC;
    
    //if month is January and February, Calculates the corresponding A C and D values
    if (month<3){
        A=10+month;
        yearC=year-1;
        C=yearC%100;
        D=yearC/100;
        
    }
    //if month is from march to december, calculates the corresponding A C and  D values
    else{
    
    A=month-2;
    C=year%100;
    D=year/100;
    

    
    }
    
    B=day;
    
    //performs the calculation required for the algorithm
    int W = (13*A-1)/5;
    int X = C/4;
    int Y = D/4;
    int Z = W+X+Y+B+C-2*D;
    int R=Z%7;
    
	//if R is negative
	if (R<0){
		R=R+7;
	}
    
    //finds the corresponding day of the week relative to R
    if (R==0){
        printf("The day %d/%d/%d is a Sunday.\n",day,month,year);
    
    }
    
    if (R==1){
       printf("The day %d/%d/%d is a Monday.\n",day,month,year);
    
    }
    
    if (R==2){
       printf("The day %d/%d/%d is a Tuesday.\n",day,month,year);
    
    }
    
    if (R==3){
        printf("The day %d/%d/%d is a Wednesday.\n",day,month,year);
    
    }
    
    if (R==4){
       printf("The day %d/%d/%d is a Thursday.\n",day,month,year);
    
    }
    if (R==5){
       printf("The day %d/%d/%d is a Friday.\n",day,month,year);
    
    }
    if (R==6){
        printf("The day %d/%d/%d is a Saturday.\n",day,month,year);
    
    }

    
    

return;
}
