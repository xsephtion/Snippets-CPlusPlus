#include<stdio.h>
int main()
{
	int ctr;
	int ctr1 = 0;
	int ctr2 = 0;
	int ctr3 = 0;
	int var = 1;
	
	int coms[99999];
	printf("Number Salesman:  ");
	scanf("%d", &ctr);
	
	if(ctr > 50)
	{do{
				printf("\n Input error \n Enter: ");
				scanf("%d", &ctr);}while(ctr>50);
	}do
	{
		printf("Enter Salesman ");
		printf("%d", var);
		printf(" sales: ");
		scanf("%d", &coms[var]);
		var++;
	}while(var < ctr+1);var=1;
	
	do{
		if(coms[var]>20000){
			printf("Salesman ");
			printf("%d", var);
			printf(" sales: ");
			printf("%d", coms[var]);
			printf(" commission is 20%% \n");ctr2++;
		}else if(coms[var]>=15000&&coms[var]<20000){
			printf("Salesman ");
			printf("%d", var);
			printf(" sales: ");
			printf("%d", coms[var]);
			printf(" commission is 15%%\n");ctr1++;
		}else if(coms[var] <= 15000)
		{	printf("Salesman ");
			printf("%d", var);
			printf(" sales: ");
			printf("%d", coms[var]);
			printf(" commission is 13%% \n");ctr3++;}var++;
	}while(var<ctr+1);
	printf("Total Commission of 20%%: ");
	printf("%d", ctr2);
	printf("\tTotal Commission of 15%%: ");
	printf("%d", ctr1);
	printf("\tTotal Commission of 13%%: ");
	printf("%d", ctr3);
	
	return 0;
}
