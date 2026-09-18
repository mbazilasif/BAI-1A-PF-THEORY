/*
Author: Bazil Asif
Date: 9-17-2026
program: Online Shopping Bill Calculator
*/


#include <stdio.h>
int main()
{
    int q;
    float p, d, t;
    float s, a, finalBill;

// taking input from user
    printf("Enter quantity of products: ");
    scanf("%d", &q);

    printf("Enter price per item: ");
    scanf("%f", &p);

    printf("Enter discount percentage: ");
    scanf("%f", &d);

    printf("Enter tax percentage: ");
    scanf("%f", &t);

    //Validation
    if (q <= 0)
    {
        printf("Error: Quantity must be greater than 0.\n");
        return 0;
    }// end if

    if (p < 0)
    {
        printf("Error: Price cannot be negative.\n");
        return 0;
    }// end if

    if (d < 0 || d > 100)
    {
        printf("Error: Discount must be between 0 and 100.\n");
        return 0;
    }// end if

    if (t < 0)
    {
        printf("Error: Tax cannot be negative.\n");
        return 0;
    }// end if

    /* Calculations */
    s = q * p;

    a = s - (s * d) / 100;

    finalBill = a + (a * t) / 100;

    /* Display Bill */
    printf("\n\n\t----- SHOPPING BILL -----\n");
    printf("\tQuantity: %d\n", q);
    printf("\tPrice per item: %.2f\n", p);
    printf("\tSubtotal: %.2f\n", s);
    printf("\tDiscount: %.2f%%\n", d);
    printf("\tDiscounted Amount: %.2f\n", a);
    printf("\tTax: %.2f%%\n", t);
    printf("\tFinal Bill: %.2f\n", finalBill);
    printf("\t-------------------------\n");

    return 0;
}// end main