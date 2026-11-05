
#include <stdio.h>

int main(){
	int rows, seats, count;
	int i = 0,  //i is a helping variable used in for loop
		j = 0;  //j is also helping vaiable used in for loop
		
	
//taking input the number of rows and the number of seats per row.
	printf("Enter number of Rows: ");
	scanf("%d", &rows);
	
	printf("Enter Number of Seats per row: ");
	scanf("%d", &seats);
	
	//checking wheather the input for rows and seats per row is correct
	if (rows <= 0 || seats <= 0){
		printf("Invalid input of Number of rows or Seats per row. \n");
    	return 0;
	}
	
	int hall[rows][seats];
	
//input the current seating status of every seat, where 0 indicates an available seat
//and 1 indicates a booked seat

	for (i = 0; i < rows; i++){
		
		printf("\n");
		
		for (j = 0; j < seats; j++){
			printf("Enter Seating status for row %d seat %d: ", i, j);
			scanf("%d", &hall[i][j]);
		}
		//end inner for	
	}
	//end outer for
	
//Displaying the complete seating plan, 
//showing _ for available seats and X for booked seats.

	printf("\n       ");    // printing on new line with white spaces to allign the output opf the terminal
	
	for (j = 0; j < seats; j++){
		printf("%3d   ", j);
		}
		//end for
	
	for (i = 0; i < rows; i++){
		
		printf("\n R%2d: |", i);
		
		for (j = 0; j < seats; j++){
			if (hall[i][j] == 0){
				printf("  _  |");
			}
			//end if
			
			else if (hall[i][j] == 1){
				printf("  X  |");
			}
			//end else if
		}
		//end inner for
	}
	//end outer for

//Seat Availability Report: Display the number of available seats in each row and
//calculate the total number of available seats in the entire hall.


	for (i = 0; i < rows; i++){
		for (j = 0; j < seats; j++){
			if (hall[i][j] == 0){
				count ++;
			}
			//end if
			
			else if (hall[i][j] == 1){
				
			}
			//end else if
		}
		//end inner for
	}
	//end outer for
	
	
}
//end main












