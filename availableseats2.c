#include<stdio.h>
#include<stdlib.h>
main(){
	int opt = 1;
	int i;
	int sts[6] = {0,0,0,0,0};
	
		for(i = 0; i<5; i++){
			if(sts[i] == 0)	
			{
				printf("\n\nSeat %d : Available", i+1); 
			}
		}
		
		for(i = 0; opt!=0; i++){
			
			
		
			printf("\nEnter Seat #(Press 0 to terminate or the assigned seat capacity): ");
			scanf("%d", &opt);
			system("cls");
			if(opt == 0){
				break;
			}
			else if(opt > 6){
				printf("Please enter valid range! eg. 1-5");
			}	
			else if(sts[opt-1] == 1){
				printf("Please take another seat!\n\n");
			}
			else if(sts[opt-1] == 0){
				sts[opt-1]++;
			}
			
	
		for(i = 0; i<5; i++){
			if(sts[i] == 0)
			{
				printf("\n\nSeat %d : Available ", i+1);
			} 
		else if(sts[i] == 1)
			{
				printf("\n\nSeat %d : Reserved", i+1); 
			}
		}
		
		}
	getch();
}
