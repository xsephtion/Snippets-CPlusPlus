#include<stdio.h>
#include<conio.h>
int main()
{
	int input,z = 0, x = 0, y = 0, plus = 1;
	int coms[50000];
	printf("Input the count of Salesman:  ");
	scanf("%d", &input);
	
	if(input > 50)
	{
			
			do{
				printf("\n Error \n Enter: ");
				scanf("%d", &input);}while(input>50);
	}do
	{
		printf("Enter Salesman ");
		printf("%d", plus);
		printf(" sales: ");
		scanf("%d", &coms[plus]);
		plus++;
	}while(plus < input+1);plus=1;
	do{
		if(coms[plus]>20000){
			printf("Salesman ");
			printf("%d", plus);
			printf(" sales: ");
			printf("%d", coms[plus]);
			printf(" commission is 20%% \n");x++;
		}else if(coms[plus]>=15000&&coms[plus]<=20000){
			printf("Salesman ");
			printf("%d", plus);
			printf(" sales: ");
			printf("%d", coms[plus]);
			printf(" commission is 15%%\n");z++;
		}else if(coms[plus] <= 15000)
		{	printf("Salesman ");
			printf("%d", plus);
			printf(" sales: ");
			printf("%d", coms[plus]);
			printf(" commission is 13%% \n");y++;}plus++;
	}while(plus<input+1);
		
		
	printf("Total Commision 20%%: ");		printf("%d", x);
	printf("\tTotal Commission 15%%: ");	printf("%d", z);
	printf("\tTotal Commission 13%%: ");	printf("%d", y);
	
	return 0;
}
