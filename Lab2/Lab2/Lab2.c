#include <stdio.h>
#include <math.h>

int main(void)
{
	//declare variables
	double purchasePrice,irYearlyPercent,irMonthlyDecimal,monthlyPayment,totalCost;
	int totalMonths;
	
	//prompt user to input purchase price
	printf("Enter the purchase price of the item: ");
	scanf("%lf",&purchasePrice);
	
	//prompt user to input the yearly interest rate
	printf("Enter the interest rate per year as a percentage: ");
	scanf("%lf",&irYearlyPercent);
	
	//prompt user to input the number of months for repayment
	printf("Enter the number of months for repayment: ");
	scanf("%d",&totalMonths);
	
	//convert the yearly rate into monthly rate and divide it by 100 to convert it to number
	irMonthlyDecimal=(irYearlyPercent/12)/100;
	
	//do the monntly payment and total cost calculations
	monthlyPayment=purchasePrice*((irMonthlyDecimal)/(1-pow(1+irMonthlyDecimal,-1*totalMonths)));
	totalCost=(monthlyPayment*totalMonths);
	
	//output the monthly payment and the total cost
	printf("The monthly payment is: %.2lf\n",monthlyPayment);
	printf("The total cost of the purchase is: %.2lf\n",totalCost);
	
 
	return 0;
}