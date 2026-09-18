 /*
Author: Bazil Asif
Date: 9-17-2026
program: Elevator simulator
*/
 #include <stdio.h>
int main()
{
    int N, request, currentFloor = 0, i = 0;               //n stands for number of request, i is for loop execution

    printf("\nEnter number of requests: ");    
    scanf("%d", &N);

    while (N > i)
    {
        printf("\nEnter requested floor: ");
        scanf("%d", &request);

        if (request > currentFloor)
        {
            printf("\nMoving Up\n");
        }// end if
        else if (request < currentFloor)
        {
            printf("\nMoving Down\n");
        }// end elseif
        else
        {
            printf("\nDoors Opening\n");
        }// end else

        currentFloor = request;
        i = i + 1;                                   //increment i by 1
    }// end while

    return 0;
}// end main