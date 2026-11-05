//Author Bazil Asif

#include <stdio.h>
void inputReadings (int readings[100][100],int sensor_num, int Hreading){
    for (int i = 0;i < sensor_num; i++){
        for (int j = 0; j < Hreading; j++){
            printf("Enter temperature for sensor %d - hour %d: ",i+1,j);
            scanf("%d",&readings[i][j]);

        }
    }
}
void sensorAnalyis(int reading[100][100], int sensor_num, int Hreading){
    float average = 0;
    int highest, lowest, critical = 0, warning = 0, currentstreak = 0, longeststreak = 0;
    
    for (int i = 0; i < sensor_num; i++){
        int totalreading = 0;
        
        highest = reading [i][0];
        lowest = reading [i][0];
        critical = 0;
        warning = 0;
        currentstreak = 0;
        longeststreak =0;
        
        for (int j = 0 ; j < Hreading; j++){
            totalreading = totalreading + reading[i][j];
            if (reading[i][j] > highest){
                highest = reading [i][j];
            }

            if (reading[i][j] < lowest){
                lowest = reading [i][j];
            }

            if (reading[i][j] >= 40){
                critical++;
            }
            else if (reading [i][j]>=35 && reading [i][j] <40){
                warning++;
            }

            if (reading[i][j] >=35){
                currentstreak++;
            }
            else {
                currentstreak =0;
            }

            if (currentstreak > longeststreak){
                longeststreak = currentstreak;
            }

        }//end inner for
        average = (float)totalreading/Hreading;
        printf("Sensor %d: Total - %d Avg - %.2f Max - %d Min - %d\n",i+1, totalreading, average, highest, lowest);

        printf("Critical: %d Warning: %d Longest hot streak: %d\n",critical, warning, longeststreak);
    }//end outer for
}

int highestAverageSensor(int reading[100][100],int sensor_num, int Hreading) {

    float highestAverage = 0;
    int highestSensor = 0;

    for (int i = 0; i < sensor_num; i++) {
        int total = 0;

        for (int j = 0; j < Hreading; j++) {
            total = total + reading[i][j];
        }

        float average = (float)total / Hreading;

        if (average > highestAverage) {
            highestAverage = average;
            highestSensor = i+1;
        }
    }

    return highestSensor;
}

int main () {
    int temperature[100][100];
    int sensor_num = 0, Hreading = 0;
    
    
    printf("Enter the number of the sensors: ");
    scanf("%d",&sensor_num);
    printf("Enter the number of hourly reading: ");
    scanf("%d",&Hreading);
    inputReadings(temperature,sensor_num,Hreading);

    for (int i = 0; i < sensor_num; i++) {
    printf("Sensor %d:", i + 1);

    	for (int j = 0; j < Hreading; j++) {
        	printf(" %d", temperature[i][j]);
    	}//end inner for
    
    printf("\n");
    }   //end outer for

    sensorAnalyis(temperature, sensor_num,Hreading);
    int bestSensor = highestAverageSensor(temperature, sensor_num, Hreading);
    printf("Highest average: Sensor %d\n", bestSensor);
    
}
// end main