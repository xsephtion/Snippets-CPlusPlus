#include<stdio.h>
#include<stdlib.h>
# define zero 0
int main(){
	int strg, opt, cap= 5, j = 1; 
	int stall[6] = {zero,zero,zero,zero,zero};
	
	
	
	do{
		if(stall[j] == 0){
			printf("Seat %d : Available", j); printf("\n\n");
		}
		j++;
	}while(j<cap+1);
	do
	{ 
		
	
	
			printf("\n Enter Seat #(Press 0 to terminate or the assigned seat capacity): ");
			scanf("%d", &opt);
			system("cls");
			if(opt == 0){
				break;
			}
			else if(opt> 5){
				printf("OUT OF RANGE!!\n\n");
			}
			else if(stall[opt] == 1){
				printf("ALREADY RESERVED!!!\n\n");
			}
			else if(stall[opt] == 0){
				stall[opt]++;
			}
			j = 1;	
			
			
			do
			{	
			if(stall[j] == 0)	
			{
				printf("Seat %d : Available", j); printf("\n\n");
			} 
			else if(stall[j] == 1)
			{
				printf("Seat %d: Reserved", j); printf(" \n\n");
			}
			
			j = j+1;
		}while(j < cap+1);
			
	}while(opt != 0);
	getch();
}
