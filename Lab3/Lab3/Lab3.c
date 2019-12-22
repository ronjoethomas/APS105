#include <stdio.h>

int main(int argc, char **argv)
{   //variable declarations
	double coffeePrice,totalBudget,budgetBalance,averageSpent;
	int fullPriceCoffee,totalFreeCoffee=0,remainderCoupons,totalCoffee,couponsFromCoffee,couponsPerCoffee,freeCouponCoffees,remainderTotalCoupons;
	
	
	//code to prompt the user to state how much a coffee costs and checking if it is a valid input
	printf("How much does a coffee cost?\n");
	scanf("%lf",&coffeePrice);
	
	if (coffeePrice<0.01){
		printf("Invalid Input.\n");
		return 0;
	}
	
	//code to prompt the user to state how many coupons it requires to get a free coffee hecking if it is a valid input

	printf("How many coupons does it take to get a free coffee?\n");
	scanf("%d",&couponsPerCoffee);
	
	if(couponsPerCoffee<=1){
		printf("Invalid Input.\n");
		return 0;
	}
		
	//code to prompt the user to state how much money they have to spend in the month for coffee and checking if it is a valid input
	printf("How much money do you have to spend on coffee this month?\n");
	scanf("%lf",&totalBudget);
	
	if(totalBudget<0){
		printf("Invalid Input.\n");
		return 0;
	}
	
	//Calculates the amount of coffee you can purchase for full price with the given budget. 
	//Then since you get 1 coupon per coffee purchased, coupons received from coffee is equal to the amount of coffee purchased
	fullPriceCoffee=(int)(totalBudget/coffeePrice);
	couponsFromCoffee=fullPriceCoffee;
	
	//outputs the amount of coffee you can purchase for full price
	printf("This month, you can purchase %d coffees at $%.2lf each.\n",fullPriceCoffee,coffeePrice);
	
	//if the user recieved enough coupons for get atleast one free coffee, executes the whole loop inside
	if (couponsFromCoffee>=couponsPerCoffee){
		
		
		while(couponsFromCoffee>=couponsPerCoffee){   //checks if you have enough coupons to get atleast one free coffee
			freeCouponCoffees=(int)couponsFromCoffee/couponsPerCoffee;  //Checks how many free coffees (and coupons along with it can you get)
			totalFreeCoffee=totalFreeCoffee+freeCouponCoffees; 
			remainderCoupons=couponsFromCoffee%couponsPerCoffee;  //Checks how many coupons you will have left after using it for get more free coffees
			couponsFromCoffee=freeCouponCoffees+remainderCoupons;
			
		}
		printf("You will be able to redeem an additional %d coffee(s) from coupons.\n",totalFreeCoffee);
	}
	
	else{
		printf("You will not be able to redeem any additional coffees from coupons this month.\n"); 
		}
		
	//calculations to determine the average money spent on coffee	
	totalCoffee=totalFreeCoffee+fullPriceCoffee; 
	budgetBalance=totalBudget-(coffeePrice*fullPriceCoffee);
	averageSpent=(totalBudget-budgetBalance)/totalCoffee;
	
	//Checks how many coupons are left. 
	//This works because everytime you purchase a coffee it implies you recived one coupon. Total coffee recieved is total coupons recieved.
	remainderTotalCoupons=totalCoffee%couponsPerCoffee;
	
	printf("At the end of the month, you will have $%.2lf and %d coupon(s) remaining.\n",budgetBalance,remainderTotalCoupons);
	printf("On average, you spent $%.2lf on each cup of coffee this month.\n",averageSpent);
	

	
	return 0;
}
