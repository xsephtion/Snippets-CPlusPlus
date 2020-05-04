#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;


struct Person {
	int empnum;
	string name;
	string address;
	string cnum;
	string department;
	string position;
	string date;
	float rpd;
	float rph;
	float over;
	double  tdw, toh, tdwf, tohf, sum, sss, pagibig, itax, totalded, np;
};


void displayMenu() {
	cout << "1) Add Employee \n";
	cout << "2) Update Employee \n";
	cout << "3) Search Employee \n";
	cout << "4) Compute Salary\n";
	cout << "5) Display Payroll Report\n";
	cout << "6) Exit\n";
	cout << "Choice: ";
}

void sysexit(int entry, Person person[]){
	double sum;
	ofstream file;
	file.open("employee.txt");
	file<< setw(20) << "Employee Number"<< setw(20) << "Position"<< setw(20) << "Department" << setw(20)<< "Payroll Date" << setw(20) << "Net Pay\n";
	for(int i = 0; i <entry; i++){
		file << setw(20) << person[i].empnum << setw(20)<< person[i].position << setw(20) << person[i].department << setw(20) << person[i].date << setw(20) << person[i].np << "\n";
	}
	for(int i = 0; i<entry; i++){
		sum = person[i].np;
	}
	file << "Total Netpay: " << sum;
	file.close();
}
void displayPayroll(int entry, Person person[]){
	double sum;
	cout << setw(20) << "Employee Number"<< setw(20) << "Position"<< setw(20) << "Department" << setw(20)<< "Payroll Date" << setw(20) << "Net Pay\n";
	for(int i = 0; i <entry; i++){
		cout << setw(20) << person[i].empnum << setw(20)<< person[i].position << setw(20) << person[i].department << setw(20) << person[i].date << setw(20) << person[i].np << "\n";
	}
	for(int i = 0; i<entry; i++){
		sum = person[i].np;
	}
	cout<< setw(10) << "Total Netpay: " << sum;
	
}

void updateEmployee(int entry, Person person[]){
	cout << "\n\nEmployee Number: ";
	cout << person[entry].empnum;
	cout << "\n";

	cout << "Name: ";
	cout << person[entry].name;
	cout << "\n";

	cout << "Address: ";
	cout << person[entry].address;
	cout << "\n";

	cout << "Contact Number: ";
	cout << person[entry].cnum;
	cout << "\n";

	cout << "Department: ";
	cout << person[entry].department;
	cout << "\n";

	cout << "Position: ";
	cout << person[entry].position;
	cout << "\n";

	cout << "Date Started: ";
	cout << person[entry].date;
	cout << "\n";
	cout << "Rate Per Day: ";
	cin >> person[entry].rpd;
	cout << "\n";
	person[entry].rph = person[entry].rpd / 8;
	person[entry].over = person[entry].rph * 1.5;
	cout << "Rate Per Hour: ";
	cout << person[entry].rph;
	cout << "\n";
	cout << "Overtime Rate:";
	cout << person[entry].over;
	cout << "\n";	
}

void computeSalary(int entry, Person person[]) {
	double rph, rpd, over;
	double tdw, toh, tdwf, tohf, sum, sss, pagibig, itax, totalded, np;
	cout << "\n\nEmployee Number: ";
	cout << person[entry].empnum;
	cout << "\n";

	cout << "Name: ";
	cout << person[entry].name;
	cout << "\n";

	cout << "Address: ";
	cout << person[entry].address;
	cout << "\n";

	cout << "Contact Number: ";
	cout << person[entry].cnum;
	cout << "\n";

	cout << "Department: ";
	cout << person[entry].department;
	cout << "\n";

	cout << "Position: ";
	cout << person[entry].position;
	cout << "\n";

	cout << "Date Started: ";
	cout << person[entry].date;
	cout << "\n";
	cout << "Rate Per Day: ";
	cout << person[entry].rpd;
	cout << "\n";
	cout << "Rate Per Hour: ";
	cout << person[entry].rph;
	cout << "\n";
	cout << "Overtime Rate: ";
	cout << person[entry].over;
	cout << "\n";
	cout << "\n\n\n\n";
	cout << "Earnings: ";
	cout << "\n";
	cout << "Total Days Worked: ";
	cin >> person[entry].tdw;
	cout << "\n";
	cout << "Total Overtime hours: ";
	cin >> person[entry].toh;


	person[entry].tdwf = person[entry].tdw * person[entry].rpd;
	person[entry].tohf = person[entry].over * person[entry].toh;
	person[entry].sum = person[entry].tdwf + person[entry].tohf;
	cout << "\nGross Salary: ";
	cout << person[entry].sum;
	cout << "\n";
	person[entry].sss = person[entry].sum * 0.15;
	person[entry].pagibig = person[entry].sum * 0.02;
	person[entry].itax = person[entry].sum * 0.20;
	person[entry].totalded = person[entry].sss + person[entry].pagibig + person[entry].itax;
	
	cout << "\nSSS(15%): ";
	cout << person[entry].sss;
	cout << "\nPag-Ibig(2%): ";
	cout << person[entry].pagibig;
	cout << "\nIncome Tax(20%): ";
	cout << person[entry].itax;
	cout << "\nTotal Deductions: ";
	cout << person[entry].totalded;
	cout << "\n\n\n";
	person[entry].np = person[entry].sum - person[entry].totalded;
	cout << "Net Pay: ";
	cout << person[entry].np;
	cout << "\n";

}

void searchEmployee(int entry, Person person[]) {
	cout << "\n\nEmployee Number: ";
	cout << person[entry].empnum;
	cout << "\n";

	cout << "Name: ";
	cout << person[entry].name;
	cout << "\n";

	cout << "Address: ";
	cout << person[entry].address;
	cout << "\n";

	cout << "Contact Number: ";
	cout << person[entry].cnum;
	cout << "\n";

	cout << "Department: ";
	cout << person[entry].department;
	cout << "\n";

	cout << "Position: ";
	cout << person[entry].position;
	cout << "\n";

	cout << "Date Started: ";
	cout << person[entry].date;
	cout << "\n";
	cout << "Rate Per Day: ";
	cout << person[entry].rpd;
	cout << "\n";
	cout << "Rate Per Hour: ";
	cout << person[entry].rph;
	cout << "\n";
	cout << "Overtime Rate:";
	cout << person[entry].over;
	cout << "\n";
}



int main() {
	Person* person = new Person[100];
	int choice;
	int searchEntry = 0;
	int entry = 0;
	double rphour, rpday, overtime;
	double netpay;
	string answ;
	do {
		displayMenu();
		cin >> choice;
		switch (choice) {
			case 1:
				// add
				do {
					cout << "Employee Number: E";
					person[entry].empnum = entry + 1000;
					cout << person[entry].empnum;
					getchar();
					cout << "\nName: ";
					getline(cin, person[entry].name);
					cout << "\nAddress: ";
					getline(cin, person[entry].address);
					cout << "\nContact Number: ";
					getline(cin, person[entry].cnum);
					cout << "\nDepartment: ";
					getline(cin,person[entry].department);
					cout << "\nPosition: ";
					getline(cin, person[entry].position);
					cout << "\nDate Started: ";
					getline(cin, person[entry].date);
					cout << "\nRate Per Day: ";
					cin >> person[entry].rpd;
					person[entry].rph = person[entry].rpd / 8;
					person[entry].over = person[entry].rph * 1.5;
					cout << "\nRate Per Hour: ";
					cout << person[entry].rph;
					cout << "\nOvertime Rate: ";
					cout << person[entry].over;
					entry++;
					cout << "\nDo you want to ADD another employee? (Y/N) :";
					cin >> answ;
					getchar();
					system("cls");
				} while(answ == "Y" || answ == "y");
				break;
			case 2:
				// update
				do{
					do {
						cout << "Input Employee Number: ";
						cin >> searchEntry;
						searchEntry = searchEntry - 1000;
						if (searchEntry <= entry) {
							updateEmployee(searchEntry, person);
						} else {
							cout << "Employee Can't Found\n";
						}
					} while(searchEntry > entry);
					cout << "\nDo you want to SEARCH another employee? (Y/N) :";
					cin >> answ;
					system("cls");	
				}while(answ == "Y" || answ == "y");
				break;
			case 3:
				// search 
				do{
					do {
						cout << "Input Employee Number: ";
						cin >> searchEntry;
						searchEntry = searchEntry - 1000;
						if (searchEntry <= entry) {
							searchEmployee(searchEntry, person);
						} else {
							cout << "Employee Can't Found\n";
						}
					} while(searchEntry > entry);
					cout << "\nDo you want to SEARCH another employee? (Y/N) :";
					cin >> answ;
					system("cls");	
				}while(answ == "Y" || answ == "y");
				break;
			case 4:
				// compute
				do{
					do {
						cout << "Input Employee Number: ";
						cin >> searchEntry;
						searchEntry = searchEntry - 1000;
						if (searchEntry <= entry) {
							computeSalary(searchEntry, person);
						} else {
							cout << "Employee Can't Found\n";
						}
					} while(searchEntry > entry);
					cout << "\nDo you want to COMPUTE another employee? (Y/N) :";
					cin >> answ;
					system("cls");
				}while(answ == "Y" || answ == "y");
				break;
			case 5:
				// display payroll
				if (entry == 0) {
					cout << "Employee Can't Found\n";
					}else{
						displayPayroll(entry, person);
					}
					system("PAUSE");
					system("cls");
				break;
			case 6:
				sysexit(entry, person);
				cout << "Check your RECORDS.txt";
				system("cls");
				return 0;
			default:
				cout << "Invalid Input!\n";
				break;
		}
	} while(choice != 1 || choice != 2 || choice != 3 || choice != 4);


}
