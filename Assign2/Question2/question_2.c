// author Bazil asif
#include <stdio.h>

int SumProperDivisors(int num){
    int sum = 0;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            sum = sum + i;
        }
    }
    return sum;
}

int main(){
    int n, count = 0;   // initialize n annd count
    
    //taking input from user
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    for (int i = 2; i <= n; i++){
        int j = SumProperDivisors(i);

        if (j > i && j <= n){
            if (SumProperDivisors(j) == i) {
                printf("(%d, %d)\n", i, j);
                count++;
            }//end inner if
        }//end outher if
    }//end for 

    if (count == 0){
        printf("No amicable pairs found.\n");
    }
	else{
        printf("Total amicable pairs found: %d\n", count);
    }
    //end if eslse
    return 0;
}//end main
