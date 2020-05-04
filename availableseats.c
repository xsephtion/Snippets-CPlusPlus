#include<stdio.h>

main(){
	int max=6;
	int j = 1;
	int in = 5;
	int stssmry[1000];
	stssmry[1] = 0;
	stssmry[2] = 0;
	stssmry[3] = 0;
	stssmry[4] = 0;
	stssmry[5] = 0;
	
	printf("\nSeats Summary: \n");
	while(in != 0)
	{
		while(j < max+1)
		{
		if(stssmry[j] == 0)
		{
			printf("Seat "); printf("%d", j); printf(": Available \n");
		} else if(stssmry[j] == 1)
		{
			printf("Seat "); printf("%d", j); printf(": Reserved \n");
		}
		j++;
			
	}
	
	printf("\nEnter Seat no(Press 0 to terminate or the assigned seat capacity): ");
	
			scanf("%d", &in);
			j = 0;	
			if(stssmry[in] == 1){
				printf("\nThe seat has already reserved.\n\n");
			}
			if(in >= max){
				printf("\nOUT OF RANGE!\n\n");
			}
			if(stssmry[in] == 0){	
				stssmry[in] = 1;
			}
			if(in == 0){
				return 0;
			}
	while(j < max+1)
	{
		
		if(stssmry[j] == 0)
		{
			printf("Seat "); printf("%d", j); printf(": Available \n");
		} 
		
		if(stssmry[j] == 1)
		{
			printf("Seat "); printf("%d", j); printf(": Reserved \n");
		}
		
		j++;
	}
	
	}
	
	
}
