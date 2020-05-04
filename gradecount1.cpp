#include <stdio.h>
#include <conio.h>
int main(){
	int studcnt,count=1,stdtemp, ave, sum =0;
	int a=0,bplus=0,b=0,cplus=0,c=0,dplus=0,d=0,f=0;
	float grade[100];
	printf("Input number of students: ");
	scanf("%d", &studcnt);
	printf("\n");
	if(studcnt > 40){
		while(studcnt > 40){
    printf("Invalid input: ");
    printf("%d", studcnt);
    printf("\n");
    printf("Input again: ");             
			scanf("%d", &studcnt);
			}
		}
	if(studcnt < 1) {
		while(studcnt < 1){
    printf("Invalid input: ");
    printf("%d", studcnt);
    printf("\n");
    printf("Input again: ");
			scanf("%d", &studcnt);
			}
		}
	stdtemp = studcnt;
 ave = stdtemp;
	while(studcnt+1 > 1){
		printf("Student ");
		printf("%d", count);
		printf(" Grade: ");
		scanf("%f", &grade[count]);
		count++;
		studcnt--;
	}
	
	count = 1;
	
	while(stdtemp+1 > studcnt){
		sum += grade[count];
		if(grade[count] >= 94.5 && grade[count] <= 100){
			a++;
		}
		if(grade[count] >=88.5 && grade[count] <= 94.4){
			bplus++;
		}
		if(grade[count] >=82.5 && grade[count] <= 88.4){
			b++;
		}
		if(grade[count] >=76.5 && grade[count] <= 82.4){
			cplus++;
		}
		if(grade[count] >=70.5 && grade[count] <= 76.4){
			c++;
		}
		if(grade[count] >=64.5 && grade[count] <= 70.4){
			dplus++;
		}
		if(grade[count] >=64.4 && grade[count] <= 59.5){
			d++;
		}
		if(grade[count] >= 0 && grade[count] <= 59.4){
			f++;
		}
		count++;
		stdtemp--;
	}
	ave = sum/ave;
	printf("Sum of A: ");
	printf("\t");
	printf("%d",a);
	printf("\n");
	printf("Sum of B+: ");
	printf("\t");
	printf("%d", bplus);
	printf("\n");
	printf("Sum of B: ");
	printf("\t");
	printf("%d",b);
	printf("\n");
	printf("Sum of C+: ");
	printf("\t");
	printf("%d", cplus);
	printf("\n");
	printf("Sum of C: ");
	printf("\t");
	printf("%d",c);
	printf("\n");
	printf("Sum of D+: ");
	printf("\t");
	printf("%d", dplus);
	printf("\n");
	printf("Sum of D: ");
	printf("\t");
	printf("%d",d);
	printf("\n");
	printf("Sum of F: ");
	printf("\t");
	printf("%d", f);
 printf("\n");
 printf("Average: ");
 printf("%d", ave);
	getch();
}
