#include <iostream>
#include <iomanip>
//#include <cstdio> 
#include <cstdlib>
//#include <string>   // stoi()
#include <istream> // getline()
#include <strings.h>
#include <stdio.h>  // for getchar()
#include <conio.h>
#include <fstream>

using namespace std;

void display_menu(int style, string menu[]);
void display_entry (int entry);
void display_header (void);
void display_footer (void);
void display_one_rec (int entry);
void filePrint(int ent);
int get_entry(int opt) ;

string records [101][5]; 
string tab ="\t ", prompt="Choose an option: ", done="Done!", cont = "Press Enter to Continue " , rest = "Press Enter to Restart ";
string menu [7] = {"Address Book", "Add Contact", "Edit Contact", "Delete Contact", "View Contacts", "Search Address Book", "Exit"};
string proc;
int asize = 0;		// records count
int recw [7] = {12,27,27,27,27};
string vert, hori, tlcor, trcor, blcor, brcor, lfty, rgty, topm, botm,midm;
const int sw = 27;

int main()
{
	int  opt = 1;    		// x for choices
	char choice = '0';		// y for x choices
	
	records[0][0] = "Entry No"; records[0][1] = "First Name"; records[0][2] = "Last name"; records[0][3] = "Address";	records[0][4] = "Contact";
	
	int entry;			// entry no for processing
	asize =0; 	

	do 
	{
		int menu_style = 4;
		cout << left << setw(sw) << setfill(' ') << endl;
		display_menu(menu_style, menu);

		// CHOOSE OPTION Sequence
		// display message if invalid choice then continue to prompt 
		
		if (opt<1||opt>6) {
			cout<<tab<<"Invalid choice! '"<<choice<<"'"<<endl;
		}
		cout << tab << prompt;
		cin >> choice;
		// end of pronpt for choice 

		// Process choice
		opt=choice-'0'; // implicit typecasting 
		//opt=choice-48; // cast char to int and convert ascii to numerical value
		
		if (opt<1 || opt>6)
			cout << "debug invalid "; // shouldnt show due to cls loop =)
		else  // options 1 to 6
		{	
			cout << endl << tab << ">> "  << menu[opt] << endl ;
			
			if ((opt>1 && opt<6) && asize==0) // opt 2,3,4 or 5
				{cout<<tab<<"Address Book Empty!"<<endl<<tab;
				char z; cout << rest ; z=getch() ;
				}
			else
			{
				switch (opt) // Menu Options
				{
					//case 0: continue;
					case 3: 
						{ // DELETE Option
							//cout << "Case 3: " << endl;
							entry = get_entry(opt);
							if (entry > 0) 
							{ 	// Delete statements

								for (int r=entry; r<=asize; r++)
								{	for (int c=1;c<=4;c++)
									{	
										records[r][c] = records[r+1][c];
									}
								}
								asize--;
								cout  << endl << tab << proc << " " << done ;
								char z; cout << endl << tab << cont ; z=getch() ;
							}
							break;
						}
					case 2: 
						{ // UPDATE Option
							proc = (opt==2?"UPDATE":"DELETE");
							entry = get_entry(opt);
							if (entry == 0) break; // exit on NO entry
								// Otherwise fall through? to Add option
						}							
					case 1: 
						{	// ADD Option
							if (opt==1) 
							{	asize++;		// increment size if ADDING
								entry=asize;	// current record
								proc="ADD";		// for prompt // was proc=(x==2?"UPDATE":"ADD");
								//cout << tab<< "asize now: " << asize<< endl;
							}
							// cout << tab << "entry: " << entry ;
							char buffer[3];
							itoa(entry,buffer,10);
							records [entry][0]=buffer;
							cin.ignore();
							for (int c=1;c<=4;c++)
							{	cout <<tab << records[0][c] << "\t: ";
								string ans;
								getline(cin, ans); records[entry][c]=ans;  
								//cin >> records[entry][c];
							}
							
							display_entry(entry);

							cout  << endl << tab << proc << " " << done ;
							char z; cout << endl << tab << cont ; z=getch() ;
							break;
						}
					case 4: 
						{	// VIEW Option

							proc = "VIEW";
							display_header();
							for (int r=1;r<=asize;r++)
								display_one_rec(r);
							display_footer();

							cout  << endl << tab << proc << " " << done ;
							char z; cout << endl << tab << cont ; z=getch() ;
							break;
						}
					case 5: 
						{	// SEARCH Option
							cout << tab << "Choose Search criteria:" << endl;
							for (int cri=1;cri<=4;cri++)
								cout << tab << tab << cri << ". " << records[0][cri] << endl;
							cout << tab << tab << "Option : " ;
							int cri; cin >> cri;
							cout << tab << tab << "Enter [" << records[0][cri] << "] to search : ";
							cin.ignore();
							string searchee;
							getline(cin, searchee); 
							
							//cin >> searchee;
							//cout  << endl << tab << done ; break;
							int found=0;
							for (int rec=1; rec<=asize; rec++)
								{
								if (records[rec][cri]==searchee)
									{found++;
										if (found==1) display_header();
									display_one_rec(rec);}
							}
							if (found>0)
								display_footer();
							else
								cout <<tab <<tab << "\"" << searchee <<  "\" NOT FOUND! in [" << records[0][cri]<< "] records " << endl;
							cout  <<  endl << tab << done ; 
							char z; cout << endl << tab << cont ; z=getch() ;
							
						}
						case 6:
							{
								filePrint();
								break;
							}
						
					case 7: 
						{	// EXIT option, nothing more to do ; 
							cout << tab; break;
						}
					default: 
						{
							cout << opt << ", default case" <<endl; break;
						} // shouldnt reach here // do nothing
				}	
				
			}	// end of if database not empry

		} // end of if choice is valid;
		
	} while (opt!=7); // exit do-while

	char z; cout << cont ; z=getch() ;

	return 0;
}

int get_entry(int opt) {
	proc = (opt==2?"UPDATE":"DELETE");
	char rec; int ent=-1;
	do
	{
		cout << tab << "Entry No to "<< proc << " : "; cin >>rec;
		ent=rec-'0'; //cout << entry;
		if (ent<0 || ent>asize) 
			cout << tab << tab << "Invalid Entry No!" << endl; 
	} while (ent<0 || ent>asize);
	
	if (ent > 0)
	{
		display_entry(ent);
		char ans='x';
	
		//while (ans!='Y' && ans!='y')
		//{
		cout << endl << tab << "Continue [" << proc << "] of Entry " << ent << "? ";
		cin >> ans;
		//}
		if	(ans!='Y' && ans !='y') ent=0;//break;
	}

	return ent;
}

void display_entry (int ent) {									

	display_header();
	display_one_rec(ent);
	display_footer();
	
}

void display_header (void){
	cout << endl;
	 
	/*cout << tab << tlcor; 
	for (int n=1; n<=(sw*5)-1; n++) cout << hori ; 
	cout << trcor << endl;
	*/
	cout << tab << tlcor; 
	for (int n=1; n<=4; n++) 
		{for (int m=1; m<=sw-1; m++) cout << hori;cout << topm; }
	for (int m=1; m<=sw-1; m++) cout << hori;
	cout << trcor << endl;	
	
	cout << tab;
	for (int c=0;c<=4;c++) cout << setw(sw) << setfill(' ') << vert+" "+records[0][c] ;
	cout << vert << endl ;

	cout << tab << lfty;
	for (int n=1; n<=4; n++) 
		{for (int m=1; m<=sw-1; m++) cout << hori;cout << midm; }
	for (int m=1; m<=sw-1; m++) cout << hori;
	cout << rgty << endl; 
}
void display_one_rec (int ent) {									

	cout  << tab ; 
	for (int c=0;c<=4;c++) cout << setw(sw) << setfill(' ') << vert+" "+records[ent][c] ;
	cout << vert << endl;
	
}

void filePrint(int ent) {
	ofstream database;
	database.open("C:\\Users\\201610246\\Documents\\database.txt");
	for (int c=0;c<=4;c++){
	database << setw(sw) << setfill(' ') << vert+" "+records[ent][c] ;
}
	database.close();
}

void display_footer (void){
	cout << tab << blcor; 
	for (int n=1; n<=4; n++) 
		{for (int m=1; m<=sw-1; m++) cout << hori;cout << botm; }
	for (int m=1; m<=sw-1; m++) cout << hori;
	cout << brcor << endl;	
	
	/*
	cout << tab << blcor; 
	for (int n=1; n<=(sw*5)-1; n++) cout << hori ; 
	cout << brcor << endl;
	*/
}

void display_menu(int style, string menu[]) {


	switch (style)
	{
		case 1:
		case 2: { vert="\xB3",hori="\xC4",tlcor="\xDA",trcor="\xBF",blcor="\xC0",brcor="\xD9",lfty="\xC3",rgty="\xB4",topm="\xC2";botm="\xC1",midm="\xC5";break; }
		case 3:
		case 4: { vert="\xBA",hori="\xCD",tlcor="\xC9",trcor="\xBB",blcor="\xC8",brcor="\xBC",lfty="\xCC",rgty="\xB9",topm="\xCB";botm="\xCA",midm="\xCE";break; }
		default: {vert=" ",hori=" ",tlcor=" ",trcor=" ",blcor=" ",brcor=" ",lfty=" ",rgty=" ",topm=" ";botm=" ",midm=" ";break; }
	}

	//string tab ="\t ";

	int lngt = 0, wdth = (sw*5)-5; 
	lngt= (wdth-menu[0].length())/2  ;

		// MENU DISPLAY Sequence
		system("cls");
		cout << "" << endl;
		if (style==1 || style ==3)  // inline
		{	cout << tab << tlcor; 
				for (int l=1; l<=lngt; l++) cout << hori; cout << rgty << " " << menu[0] << " " << lfty; 
				for (int l=1; l<=lngt+ ((menu[0].length())%2==0 ? 0:1); l++) cout << hori; 
			cout << trcor << endl; 
			cout << tab << vert ; 
				for (int n=1; n<=wdth+4; n++) cout << " " ; 
			cout << vert << endl;
		}
		else 						// inbox
		{	cout << tab << tlcor; 
				for (int n=1; n<=wdth+4; n++) cout << hori ; 
			cout << trcor << endl; 
			cout << tab << vert ; 
				for (int l=1; l<=lngt; l++) cout << " "; cout <<"  " << menu[0]  << "  "; 
				for (int l=1; l<=lngt+ ((menu[0].length())%2==0 ? 0:1); l++) cout << " "; 
			cout << vert << endl;
		}
		cout << tab << lfty ; for (int n=1; n<=wdth+4; n++) cout << hori; cout << rgty << endl;
				
		for (int m=1; m<=6; m++) 
			{cout << tab << vert << " " << m << ". " << menu[m] ;
			for (int n=1; n<=wdth - menu[m].length(); n++) cout << " ";
		cout << vert << endl;}
		
		cout << tab << vert ;for (int n=1; n<=wdth+4; n++) cout << " "; cout << vert << endl;
		
		cout << tab << blcor; 
			for (int l=1; l<=wdth+4; l++) cout << hori; 
		cout << brcor << endl;
		// ENDOF MENU DISPLAY SEQUENCE
	return ;

}