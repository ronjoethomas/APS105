#include <stdio.h>
#include <math.h>
#include <stdbool.h>

//intializing the functions used
bool validateInput(double left, double right, int n);
double evalFunc(double x);


int main(void)
{	
	//intialzing the variables
	double leftBound, rightBound,stepSize, leftSum, rightSum, midSum;
    int nPart;
	
	//Executing the main loop
	do{
		printf("Enter the Left boundary: a, Right boundary: b, and No. of rectangles to use.\n");
		printf("To exit enter 0 0 0\n");
		scanf("%lf %lf %d", &leftBound, &rightBound, &nPart);
		// if the input in not valid (or 0 0 0) executes this if statement
		if (validateInput(leftBound,rightBound,nPart)==false){
		     printf("Invalid inputs...\n\n");
			if ((leftBound==0)&&(rightBound==0)&&(nPart==0)){
		     printf("Terminating main!\n");
			 } 
		}
		//if valid input then execute these statements
		else 
	{
       	 
		stepSize=(rightBound-leftBound)/nPart;
		printf("With Step Size: %0.4lf\n",stepSize);
		printf("The approximate integral of the f(x) = 2(x^2)-7x-2\n");
		printf("Bound between %.2lf and %.2lf, using %d rectangles is as follows\n\n",leftBound,rightBound,nPart);
		
		//Midpoint Reimann Sum Calculation
		for(int i=0;i<nPart;i++)
		{
			double xValues= ((leftBound + i*stepSize)+(leftBound+ (i+1)*stepSize))/2;
			midSum= midSum+(evalFunc(xValues)*stepSize);
		}
		
		printf("Mid point evaluation approximate: %.4lf\n",midSum);
		
		//Left Reimann Sum Calculation
		for(int i=0;i<nPart;i++)
		{
			double xValues= leftBound + i*(stepSize);
			leftSum= leftSum+(evalFunc(xValues)*stepSize);
		}
		
		printf("Left point evaluation approximate: %.4lf\n",leftSum);
		
		//Right Reimann Sum Calculation
		for(int i=1;i<=nPart;i++)
		{
			double xValues= leftBound + i*(stepSize);
			rightSum= rightSum+(evalFunc(xValues)*stepSize);
		}
		
		printf("Right point evaluation approximate: %.4lf\n\n\n",rightSum);
		
		
		return 0;
	}
		

		
		
	} while ((leftBound!=0)||(rightBound!=0)||(nPart!=0)); //checks condition
	
	return 0;
}
//Validate Input Function
bool validateInput(double left, double right, int n){
	if ((left>=-10.0)&&(right<=10.0)&&(n>0)&&(left<right)){
		return true;
	}
	else{ 
		return false;
    }
}
//Function evaluation Function
double evalFunc(double x){
	
	double height= 2*pow(x,2)-7*x-2;
	return height;
	
}
