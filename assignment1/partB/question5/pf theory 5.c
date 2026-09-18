/*
Author: Bazil Asif
Date: 9-17-2026
program: vehicle parking management system
*/
#include<stdio.h>
int main()
{
	char type, category, permit, emergency;
	int n, i=0, occupiedA = 0, occupiedB = 0, occupiedC = 0, accepted = 0, rejected = 0, carCount = 0, bikeCount = 0, vanCount = 0;
	
	printf("\nEnter number of vehicles: ");
    scanf("%d", &n);
	
	while (n > i)
	{
		i = i + 1;
		
		printf("\nVEHICLE NUMBER	 %d\n\n",i);
		
		int a = 0, b = 0, c = 0, d = 0;
		
		// Vehicle Type input 
		while(a == 0)
		{
			printf("Enter vehicle type (C for car, B for bike, or V for van): ");
			scanf(" %c",&type);
			
			if(type == 'c' || type == 'b' ||type == 'v' ||type == 'C' || type == 'B' || type == 'V')
			{
				a = 1;
			} // end if
			else {
				printf("Invalid vehicle type. Try again.\n");
			} // end else
		} // end while
		
		//Vehicle category input
		while(b == 0)
		{
			printf("Enter user category (F for faculty, S for student, or G for visitor/guest): ");
			scanf(" %c",&category);
		
			if(category == 'F' || category == 'G' || category == 'S' || category == 'f' || category == 's' || category == 'g')
			{
				b = 1;
			} // end if
			else
			{
				printf("Invalid category. Try again.\n");
			} // end else
		} // end while
	
		//Permit verification input
		while(c == 0)
		{
			printf("Enter whether the vehicle has a valid parking permit (Y or N):");
			scanf(" %c",&permit);
		
			if(permit == 'y' || permit == 'n' || permit == 'Y' || permit == 'N')
			{
				c = 1;
			} // end if
			else 
			{
				printf("Invalid permit value. Try again.\n");
			} // end else
		} // end while

 		if (permit == 'N' || permit == 'n')
 		{
 			while(d == 0)
 			{
				printf("Enter whether the vehicle is emergency vehicle (Y or N):");
				scanf(" %c",&emergency);

				if (emergency == 'Y' || emergency == 'y' || emergency == 'N' || emergency == 'n')
				{
					d = 1;
				} // end if
				else
				{
					printf("Invalid vehicle. Try again.\n");
				} // end else
 			} // end while
		} // end if

		//Fucality Category
		if(category == 'f' || category == 'F')
		{
			if(occupiedA < 20)
			{
				if(type == 'c' || type == 'C')
				{
					if(permit == 'y'|| permit == 'Y' || emergency == 'Y' || emergency == 'y')
					{
						occupiedA++;
						carCount++;
						accepted++;
					} // end if
				} // end if
				else if(type == 'b' || type == 'B')
				{
					if(permit == 'y'||permit == 'Y' || emergency == 'Y' || emergency == 'y')
					{
						occupiedA++;
						bikeCount++;
						accepted++;
					} // end if
				} // end else if
				else if(type == 'v' || type == 'V')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedC = occupiedC + 2;
						vanCount++;
						accepted++;
					} // end if
				} // end else if
			} // end if
			else 
			{
				rejected++;
			} // end else
		} // end if

			// Student Category
		else if(category == 's' || category == 'S')
		{
			if(occupiedB < 40)
			{
				if(type == 'c' || type == 'C')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedB++;
						carCount++;
						accepted++;
					} // end if
				} // end if
				else if(type == 'b' || type == 'B')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedB++;
						bikeCount++;
						accepted++;
					} // end if
				} // end else if
				else if(type == 'v' || type == 'V')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedC = occupiedC + 2;
						vanCount++;
						accepted++;
					} // end if
				} // end else if
			} // end if
			else 
			{
				rejected++;
			} // end else
		} // end else if

			//Guest Category
		else if(category == 'g' || category == 'G')
		{
			if(occupiedB < 15)
			{
				if(type == 'c' || type == 'C')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedC++;
						carCount++;
						accepted++;
					} // end if
				} // end if
				else if(type == 'b' || type == 'B')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedC++;
						bikeCount++;
						accepted++;
					} // end if
				} // end else if
				else if(type == 'v' || type == 'V')
				{
					if(permit == 'y'||permit == 'Y'||emergency == 'Y' || emergency == 'y')
					{
						occupiedC = occupiedC + 2;
						vanCount++;
						accepted++;
					} // end if
				} // end else if
			} // end if
			else 
			{
				rejected++;
			} // end else
		} // end else if
	} // end while

	printf("\nPARKING SUMMARY\n\n'n'");

    printf("Total vehicles processed: %d\n", n);
    printf("Total accepted vehicles: %d\n", accepted);
    printf("Total rejected vehicles: %d\n", rejected);

    printf("\nCars successfully parked: %d\n", carCount);
    printf("Bikes successfully parked: %d\n", bikeCount);
    printf("Vans successfully parked: %d\n", vanCount);

    printf("\nZone A - Occupied: %d, Remaining: %d\n",
           occupiedA, 20 - occupiedA);

    printf("Zone B - Occupied: %d, Remaining: %d\n",
           occupiedB, 40 - occupiedB);

    printf("Zone C - Occupied: %d, Remaining: %d\n",
           occupiedC, 15 - occupiedC);

    if (occupiedA >= occupiedB && occupiedA >= occupiedC)
        {
		printf("\nZone with highest occupancy: Zone A\n");
    	}// end if
	else if (occupiedB >= occupiedA && occupiedB >= occupiedC)
    {
	    printf("\nZone with highest occupancy: Zone B\n");
    }// end else if
	else
    {
	    printf("\nZone with highest occupancy: Zone C\n");
	}
    // end else

    if (occupiedA == 20 && occupiedB == 40 && occupiedC == 15)
    {
		printf("Entire campus parking facility is FULL.\n");
    }// end if
	else
    {
	    printf("Entire campus parking facility is NOT FULL.\n");
	}
    // end else

    return 0;
} // end main
```
