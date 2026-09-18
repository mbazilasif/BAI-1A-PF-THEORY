/*
Author: Bazil Asif
Date: 9-17-2026
program: Class Result Processing
*/

#include<stdio.h>
#include<math.h>
int main()
{
	int n, i = 0, j = 0, subject = 5, marks, obtained = 0,  deficiency = 0;
	float average;
	
	printf("Enter number of students: ");
	scanf("%d",&n);
	
	while (n > i)
	{
		i = i + 1;                     // incremnent i by 1
		
		printf("\nEnter student %d marks\n\n",i);
		
		while (subject > j)
		{
			j = j + 1;                          // increment j by i
			
			printf("Enter subject %d marks:",j);
			scanf("%d",&marks);
			
			obtained = obtained + marks;
			
			if (marks < 33)
			{
				deficiency = 1;
			}//end if
			
		}//end while
	average = obtained / 5.0;
		
	printf("\n Average of subjects is %2f",average);
		
	if (deficiency >= 1)
	{
		printf("\n\nFail %d Subject Deficiency",deficiency);
	}//end if
		
	else if (average >= 80)
    {
       printf("Distinction\n");
    }//end elseif
        
	else if (average >= 60)
    {
       printf("Pass\n");
    }//end elseif
	
	else
    {
        printf("Fail\n");
	}
	
	}//end else
return 0;
}

