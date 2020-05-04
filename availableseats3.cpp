#include<stdio.h>

int main(){
	int capacity,loop = 1, option = 5;
	int seats[16];
	printf("Number of seats: ");
	scanf("%d", &capacity);
	if(capacity> 15){
	while(capacity > 15){
		scanf("%d", &capacity);
	}
	}
	
	printf("\n Seat Summary: \n");
	while(option != 0){
		while(loop < capacity+1){
		seats[loop] = 0;
		if(seats[loop] == 0){
			printf("Seat "); printf("%d", loop); printf(": Available \n");
		} else if(seats[loop] == 1){
			printf("Seat "); printf("%d", loop); printf(": Reserved \n");
		}
		loop++;
			
	}
	printf("\n Enter Seat no.(Press 0 to terminate or the assigned seat capacity): ");
			scanf("%d", &option);
			loop = 0;	
	seats[option] = 1;
	while(loop < capacity+1){
		
		if(seats[loop] == 0){
			printf("Seat "); printf("%d", loop); printf(": Available \n");
		} else if(seats[loop] == 1){
			printf("Seat "); printf("%d", loop); printf(": Reserved \n");
		}
		loop++;
	}
	}
	
	
}
