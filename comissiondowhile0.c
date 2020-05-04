#include<stdio.h>





int main()
{
	int input,cmssn15 = 0, cmssn20 = 0, cmssnby13 = 0, incrementby = 1;
	int cmssn[50000];
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
		printf("%d", incrementby);
		printf(" sales: ");
		scanf("%d", &cmssn[incrementby]);
		incrementby++;
	}while(incrementby < input+1);incrementby=1;
	do{
		if(cmssn[incrementby]>20000){
			printf("Salesman ");
			printf("%d", incrementby);
			printf(" sales: ");
			printf("%d", cmssn[incrementby]);
			printf(" commission is 20%% \n");cmssn20++;
		}else if(cmssn[incrementby]>=15000&&cmssn[incrementby]<=20000){
			printf("Salesman ");
			printf("%d", incrementby);
			printf(" sales: ");
			printf("%d", cmssn[incrementby]);
			printf(" commission is 15%%\n");cmssn15++;
		}else if(cmssn[incrementby] <= 15000)
		{	printf("Salesman ");
			printf("%d", incrementby);
			printf(" sales: ");
			printf("%d", cmssn[incrementby]);
			printf(" commission is 13%% \n");cmssnby13++;}incrementby++;
	}while(incrementby<input+1);
		
		
	printf("\tTotal Commision 20%%: ");		printf("%d", cmssn20);
	printf("\tTotal Commission 15%%: ");	printf("%d", cmssn15);
	printf("\tTotal Commission 13%%: ");	printf("%d", cmssnby13);
	
	return 0;
}
