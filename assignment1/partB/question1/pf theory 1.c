/*
Author: Bazil Asif
Date: 9-17-2026
program: hotel booking system
*/
# include<stdio.h>
#include<math.h>

int main()
{
// declare variables as integers
	int N,season, room, nights, X, rate, price, discount, total_price, previous;  //n is the number of guest, where as x is serial number guest

	printf("HOTEL BOOKING SYSTEM \n\n\n");
	
	
	printf("Enter number of guest:");
	scanf("%d",&N);
	
	previous = 0;
	X = 0;
	while (N>X)
		{
		discount = 0;
		X = X+1;
		
		printf("\n Input for guest %d:\n",X);                      //taking input from user
		
		printf("\n\nEnter season (Peak=1 or Off-Peak=2):");
		scanf("%d",&season);
		
		printf("Enter room type (Standard = 1, Deluxe = 2, or Suite = 3):");
		scanf("%d",&room);
		
		printf("Enter number of nights stayed:");
		scanf("%d",&nights);
		
		//Peak season rates: Standard = Rs. 5,000/night, Deluxe = Rs. 8,000/night, Suite = Rs.12,000/night.
		//• Off-Peak rates: Standard = Rs. 3,000/night, Deluxe = Rs. 5,000/night, Suite = Rs. 8,000/night.
		
		switch(season) 
		{ 
			case 1:
				switch(room)
				{
					case 1:
						rate = 5000;
						break;
					case 2:
						rate = 8000;
						break;
					case 3:
						rate = 12000;
						break;
				}//end switch
				break;
			case 2:
				switch(room)
				{
					case 1:
						rate = 3000;
						break;
					case 2:
						rate = 5000;
						break;
					case 3:
						rate = 8000;
						break;
				}//end switch
				break;
			}// end switch 
		//CALCULATION
		
		price = rate * nights;
		
		if (nights > 7)
			discount = price*0.15;
		
		total_price = (rate * nights)-discount;
		
		printf("\nGuest %d total is %d\n\n\n",X , total_price);        //guest's total
		
		total_price = total_price + previous;
		previous = total_price;
	}// nend while
	printf("\nHotel Total Revenue is %d:\n",total_price);
return0;
}//end main

