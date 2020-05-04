#include<stdio.h>

int main(){
	int salesmancount, salesmansales;
	int enter[999];
	int bool1flagrec = 0, bool2flagrec = 0, bool3flagrec = 0;
	
	printf("Enter how many salesman: ");
	scanf("%d", &salesmancount);

	if(salesmancount > 50){
		for(salesmansales = 0; salesmansales < salesmancount; salesmansales++){
			printf("Error in input!! Reinput: ");
			scanf("%d", &salesmancount);
			if(salesmancount < 50){
				break;
			}
		}
	}
	
	
	
	for(salesmansales =1; salesmansales<salesmancount+1; salesmansales++){
		printf("Enter Salesman ");
		printf("%d", salesmansales);
		printf(" sales: ");scanf("%d", &enter[salesmansales]);
	}
	for(salesmansales=1; salesmansales<salesmancount+1; salesmansales++){
		if(enter[salesmansales] > 19999)
		{
			printf("Salesman  ");printf("%d", salesmansales);
			printf(" sales: ");printf("%d", enter[salesmansales]);
			printf(" commision 20%% \n");
			bool2flagrec++;
		}else if(enter[salesmansales] > 15000 && enter[salesmansales] < 19999)
		{
			printf("Salesman");	printf("%d", salesmansales);
			printf(" sales : ");printf("%d", enter[salesmansales]);
			printf(" commision 15%%\n");
			bool1flagrec++;
		}else if(enter[salesmansales] < 15000)
		{
			printf("Salesman ");printf("%d", salesmansales);
			printf(" sales: ");printf("%d", enter[salesmansales]);
			printf(" commision 13%% \n");
			bool3flagrec++;
		}
	}	
	
	printf("Total Commission 20%%:  \t \t \t ");
	printf("%d", bool2flagrec);
	printf("\nTotal Commission 15%%: \t \t \t ");
	printf("%d", bool1flagrec);
	printf("\nTotal Commission 13%%: \t \t \t ");
	printf("%d", bool3flagrec);
	
	return 0;
}
