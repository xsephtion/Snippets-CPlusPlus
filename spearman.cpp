#include<iostream>
#include<stdlib.h>
#include <iomanip>

using namespace std;

int main() {
	int gradeCount = 9;
	float gradeA[10], gradeB[10];
	double rankA[10], rankB[10];
	double prankA[10], prankB[10];
	double rankTempA[10], rankTempB[10];
	int diff[10];
	int diffSquared[10];

	//Get Grade A
	cout << "Input Grades A" << endl;
	for(int i = 0; i < gradeCount; i++) {
		cout << "Grade " << i + 1 << " : ";
		cin >> gradeA[i];
	}

	//Get Grade B
	cout << endl <<  "\nInput Grades B" << endl;
	for(int i = 0; i < gradeCount; i++) {
		cout << "Grade " << i + 1 << " : ";
		cin >> gradeB[i];
	}

	//Get Rank A
	for(int i = 0; i < gradeCount; i++) {
		int ctr = 1;
		for(int j = 0; j < gradeCount; j++) {
			if(gradeA[i] > gradeA[j]) {
				ctr++;
			}
		}
		rankA[i] = ctr;
		prankA[i] = ctr;
		rankTempA[i] = rankA[i];
	}

	//Get Rank B
	for(int i = 0; i < gradeCount; i++) {
		int ctr = 1;
		for(int j = 0; j < gradeCount; j++) {
			if(gradeB[i] > gradeB[j]) {
				ctr++;
			}
		}
		rankB[i] = ctr;
		prankB[i] = ctr;
		rankTempB[i] = rankB[i];
	}

	//Adjust Rank A
	for(int i = 0; i < gradeCount; i++) {
		int itr = 0;
		int ctr = 0;
		int sum = 0;
		for(int j = 0; j < gradeCount; j++) {
			if(rankA[i] == rankA[j]) {
				sum += (rankA[i] + 1) - itr++;
				ctr++;
			}
		}
		rankTempA[i] = ((float)sum / ctr - 1);
	}

	//Adjust Rank B
	for(int i = 0; i < gradeCount; i++) {
		int itr = 0;
		int ctr = 0;
		int sum = 0;
		for(int j = 0; j < gradeCount; j++) {
			if(rankB[i] == rankB[j]) {
				sum += (rankB[i]) + 1 - itr++;
				ctr++;
			}
		}
		rankTempB[i] = ((float)sum / ctr - 1)  ;
	}
	


	for(int i = 0; i < gradeCount; i++) {
		rankA[i] = rankTempA[i];
		rankB[i] = rankTempB[i];
	}


	//Difference
	//Difference Square
	//Sum of Difference Square
	int sum = 0;
	for(int i = 0; i < gradeCount; i++) {
		diff[i] = abs(rankA[i] - rankB[i]);
		diffSquared[i] = diff[i] * diff[i];
		sum += diffSquared[i];
 	}

	//Correlation
	double correlation = (1.00 - (6.00 * sum)/(gradeCount*((gradeCount * gradeCount) - 1.00)));

	cout << endl  << setw(5) << "VALUES A" << setw(15) << "RANK A" << setw(15) << "ADJUST TABLEA"<< setw(15)<<"VALUES B" << setw(15) << "RANK B"  << setw(15) << " ADJUSTED TABLE B" <<setw(15) << "DIFFERENCE" << setw(15)  << "DIFFERENCE ^ 2" << endl << endl;
	for(int i = 0; i < gradeCount; i++) {
		cout << setw(5) << gradeA[i] << setw(15) << setprecision(2) << prankA[i] << setw(15) << setprecision(2)<<setw(15) << rankTempA[i] << setprecision(2) << setw(15) << gradeB[i] << setprecision(2) <<setw(15)<< prankB[i] << setprecision(2) << setw(15)<< rankTempB[i]<< setprecision(2)<<setw(15)  << diff[i] << setw(15) << setprecision(2) << diffSquared[i] << endl;
	}

	cout << endl <<  "CORRELATION: " << setprecision(2) << correlation;
}
