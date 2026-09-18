/*
Author: Bazil Asif
Date:9-18-2026
Program: Smart EV Charging and Parking Management System
*/

#include <stdio.h>
int main()
{
    char type, member, disabled, station;
    int battery, required, duration, time;
    int chargingNeeded;
    float chargingCost, parkingCost, discount, finalAmount;

// take input from the user
    printf("Enter vehicle type (E = Electric, H = Hybrid): ");
    scanf(" %c", &type);

    printf("Enter current battery percentage: ");
    scanf("%d", &battery);

    printf("Enter required charging percentage: ");
    scanf("%d", &required);

    printf("Enter expected parking duration in hours: ");
    scanf("%d", &duration);

    printf("Enter current time (0-23): ");
    scanf("%d", &time);

    printf("Do you have membership? (Y/N): ");
    scanf(" %c", &member);

    printf("Do you have disabled-person priority? (Y/N): ");
    scanf(" %c", &disabled);

    printf("Is charging station available? (Y/N): ");
    scanf(" %c", &station);

    chargingCost = 0;
    parkingCost = 0;
    discount = 0;

    // Checking charging station 
    if (station == 'N' || station == 'n')
    {
        if (type == 'H' || type == 'h')
        {
            printf("\nCharging unavailable - Parking only.\n");
        }//end if
        else
        {
            printf("\nNo charging slot available.\n");
        }//end else
    }//end if
    else
    {
        // Checking vehicle eligibility 
        if (type == 'H' || type == 'h')
        {
            if (battery >= 40)
            {
                printf("\nVehicle does not qualify for EV charging.\n");
            }//end if
            else
            {
                printf("\nVehicle qualifies for charging.\n");
            }//end else
        }// end if
        else if (type == 'E' || type == 'e')
        {
            printf("\nVehicle qualifies for charging.\n");
        }// end else if

        // Charging calculation 
        chargingNeeded = required - battery;

        if (required <= battery)
        {
            printf("No charging required.\n");
    	}// end if
        else
        {
            // Priority 
            if (battery <= 15 && required >= 80)
            {
                printf("Charging Priority: Emergency Charging Priority\n");

                if (time < 17 || time > 22)
                {
                    printf("Charging Time: Off-Peak\n");
                    chargingCost = chargingNeeded * 35;
                }//end if
                else
                {
                    printf("Charging Time: Peak\n");
                    chargingCost = chargingNeeded * 50;
                }//end else
            }//end iif
            else if (disabled == 'Y' || disabled == 'y' || member == 'Y' || member == 'y') && battery <= 30)
            {
                printf("Charging Priority: Priority Charging\n");

                if (time < 17 || time > 22)
                {
                    printf("Charging Time: Off-Peak\n");
                    chargingCost = chargingNeeded * 35;

                    if (member == 'Y' || member == 'y')
                    {
                        discount = chargingCost * 0.20;
                        chargingCost = chargingCost - discount;
                    }//end if
                }//end if
                else
                {
                    printf("Charging Time: Peak\n");
                    chargingCost = chargingNeeded * 50;
                    discount = chargingCost * 0.10;
                    chargingCost = chargingCost - discount;
                }//end else
            }//end else if
            else
            {
                printf("Charging Priority: Normal Charging\n");

                if (time < 17 || time > 22)
                {
                    printf("Charging Time: Off-Peak\n");
                    chargingCost = chargingNeeded * 35;

                    if (member == 'Y' || member == 'y')
                    {
                        discount = chargingCost * 0.20;
                        chargingCost = chargingCost - discount;
                    }//end if
                }//end if
                else
                {
                    printf("Charging Time: Peak\n");
                    chargingCost = chargingNeeded * 50;
                    discount = chargingCost * 0.10;
                    chargingCost = chargingCost - discount;
                }//end else
            }//end else
        }//end else
    }//  end else

    // Parking charges 
    if (duration <= 2)
    {
        parkingCost = 200;
    }//  end if
    else if (duration <= 5)
    {
        parkingCost = 400;
    }// end else if
    else
    {
        parkingCost = 700;
    }//end else

    // Parking discount 
    if (disabled == 'Y' || disabled == 'y')
    {
        parkingCost = 0;
    }//end if
    else if (member == 'Y' || member == 'y')
    {
        parkingCost = parkingCost - (parkingCost * 0.20);
    }//end else if

    // Final amount
    finalAmount = chargingCost + parkingCost;

    // Long stay warning 
    if (duration > 8)
    {
        printf("\nLong-stay warning: Please relocate your vehicle after charging.\n");
    }//end if
    else
    {
        printf("\nStandard parking duration.\n");
    }// end else

    // Display result 
    printf("\n--------- FINAL DETAILS ---------\n");
    printf("Vehicle Type: %c\n", type);
    printf("Current Battery: %d%%\n", battery);
    printf("Required Charging Level: %d%%\n", required);
    printf("Charging Cost: Rs. %.2f\n", chargingCost);
    printf("Parking Cost: Rs. %.2f\n", parkingCost);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmount);

    return 0;
}//  end main