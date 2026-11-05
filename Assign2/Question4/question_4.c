//Author Bazil Asif

#include <stdio.h>

float dailyAverage[7];
int highestOrder[7];

int getValidDays(){
    int days;
    printf("Enter the number of days for the festival: ");
    scanf("%d",&days);
    while (days <1 || days >7){
        printf("Festival can only between 1-7 days. Enter again: ");
        scanf("%d",&days);
    }
    return days;
}

float CalculateDailySales (int dayNumber){
    int orders = 0, total = 0, day = 0;
    float avg = 0;
    int amount[100];
    
    printf("Enter the number of orders: ");
    scanf("%d",&orders);
    
    while (orders <1){
        printf("Order number should be more than zero. Enter again: ");
        scanf("%d",&orders);
    }
    for (int i=0; i<orders;i++){
        printf("Enter the amount for Order %d: ",i+1);
        scanf("%d",&amount[i]);
        while (amount[i] <1){
            printf("Amount should be more than 0.Enter again: ");
            scanf("%d",&amount[i]);
        }
        total = total + amount[i];
    }
    avg = (float)total /orders;
    int highest = amount[0];
    for (int i=0;i<orders;i++){
        if (amount[i] >highest){
            highest=amount[i];
        }
    }
    dailyAverage[dayNumber - 1] = avg;
    highestOrder[dayNumber - 1] = highest;
    printf("Day %d - Total sales: %d Average order amount: %.2f Highest order amount: %d \n",dayNumber,total,avg,highest);
    return total;
}

int FindHighestSalesDay (float DailySales[7],int NumberOfDays){
    float highest = DailySales[0];
    int day = 1;
    for (int i=0;i<NumberOfDays;i++){
        if (DailySales[i] >highest){
            highest = DailySales[i];
            day = i+1;
        }
    }
    return day;
}

void DisplayBarChart (float DailySales[7],int NumberOfDays){
    int aesterisk = 0;
    
    for (int i=0;i<NumberOfDays;i++){
        aesterisk = DailySales[i] / 100;
        printf("Day %d: ", i + 1);
        if (aesterisk < 1){
            printf("None");
        }
        else {
            for (int j=0;j<aesterisk;j++){
                printf("*");
            }
        }
        printf("\n");
    }
}

void displayDailySummary(float dailySales[], int numberOfDays) {
    printf("\nDAILY SALES SUMMARY\n");

    for (int i = 0; i < numberOfDays; i++) {
        printf("Day %d\n", i + 1);

        printf("Total sales: Rs. %.2f\n", dailySales[i]);
        printf("Average order: Rs. %.2f\n", dailyAverage[i]);
        printf("Highest order: Rs. %d\n\n", highestOrder[i]);
    }
}

int main () {
    int days;
    float DailyTotal[7];
    int highestSaleDay = 0;
    float festivalTotal = 0;

    days = getValidDays();

    for (int i=0; i<days;i++){
        DailyTotal[i] = CalculateDailySales(i+1);
    }


    for (int i = 0; i < days; i++) {
    festivalTotal += DailyTotal[i];
    }

    highestSaleDay = FindHighestSalesDay(DailyTotal,days);
    displayDailySummary(DailyTotal, days);

    printf("\n----FESTIVAL SUMMARY----\n");
    printf("Total festival sales: Rs. %.2f\n", festivalTotal);
    printf("Day with highest sales: Day %d\n", highestSaleDay);
    printf("Highest daily sales: Rs. %.2f\n", DailyTotal[highestSaleDay - 1]);
    printf("Daily Sales Bar Chart \n");
    DisplayBarChart(DailyTotal,days);


}