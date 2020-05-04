#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <fstream>
using namespace std;

class Exam{
	public:
		char name [20];
		void set_grades(int g);
		int get_grades();
	private:
		int grades;		
};
struct student{  
	char name[30];
	int id , grades;
}; 
struct nde {
	char data;
	int index;
	struct nde * next;
	struct nde * prev;
} *hd;

void Exam::set_grades(int g){
	grades= g;
}
int Exam::get_grades(){
	return grades;
}

void displayMenu(){
	cout<<"======MENU======\n";
	printf("1 - Input Records\n");
	printf("2 - Display Records\n");
	printf("3 - Search\n");
	printf("4 - Exit\n");
}

void writeToFile(){
	FILE *myFile;
	char name[30];
	int id, grades;
	student stud;
	myFile = fopen("input.txt", "a");
	cout<<"Enter student name: ";
	cin>>stud.name;
	cout<<"Enter student I.D.: ";
	cin>>stud.id;
	cout<<"Enter exam grades: ";
	cin>>stud.grades;
	fprintf(myFile,"%s %d %d\n", stud.name, stud.id, stud.grades);
	fclose(myFile);
	
}
void readTofile(){
	
		string STRING;
		ifstream infile;
		infile.open ("input.txt");
        while(infile) // To get you all the lines.
        {
	        getline(infile,STRING); // Saves the line in STRING.
	        cout<<STRING; // Prints our STRING.
        }
	infile.close();
	system ("pause");
			
		}


void searchKeyword() {
    int ocurrences_count = 0;
    char word[20];  //this array will save user input
    int array_size = 1024; // define the size of character array
	char * array = new char[array_size]; // allocating an array of 1kb
	int position = 0; //this will be used incremently to fill characters in the array 
  
  //prompting user to enter a word to be search in the file
  cout << "Please enter the word to  search in file : ";
  cin.get();
  cin.getline(word,19); //reading user input of max 19 characters because our word array size in 20
  int word_size = 0;
  //this loop is calculating the length of input word
  for(int i = 0; word[i] != '\0'; i++)
  {
    word_size++;
  }
  
	ifstream fin("input.txt"); //opening an input stream for file input.txt
	/*checking whether file could be opened or not. If file does not exist or don't have read permissions, file
  stream could not be opened.*/
  if(fin.is_open())
	{
    //file opened successfully so we are here
    cout << "File Opened successfully!!!. Reading data from file into array" << endl;
    //this loop run until end of file (eof) does not occur
		while(!fin.eof() && position < array_size)
		{
			fin.get(array[position]); //reading one character from file to array
			position++;
		}
		array[position-1] = '\0'; //placing character array terminating character

    //this loop is searching for the word in the array
		for(int i = 0; array[i] != '\0'; i++)
		{
			for(int j = 0; word[j] != '\0' && j < 20 ; j++)
      {
        if(array[i] != word[j])
        {
          break;
        }
        else
        {
          i++;
          if(word[j+1] == '\0')
          {
            cout << "Word Found in File at position " << (i-word_size) << endl;
            ocurrences_count++;
          }
        }
      }
		}
    cout << "Total occurences found : " << ocurrences_count << endl;
	}
	else //file could not be opened
	{
		cout << "File could not be opened." << endl;
	}


}

int main () {
	int d;
	

	do {
	displayMenu();
	cin >> d;		
	switch (d) {
		
		case 1: {
			writeToFile();
			break;
		}
		case 2: {
			readTofile();
			break;
		}
		case 3:{
		searchKeyword();
			break;
		default: {
			break;
		}
		}
	}
}while (d!=4);

}
