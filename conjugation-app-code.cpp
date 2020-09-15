#include <iostream>
#include <conio.h>
#include <fstream>
#include <windows.h> //For the output formatting commands

using namespace std;

class verb{
	string baseVerb;
	string form1, form2, form3, form4, form5, form6;
	int count;
public:
	void getValues(){
		cout << "\n\n\tPlease enter the base verb: ";
		cin >> baseVerb;
		cout << "\n\tPlease enter the conjugations:" << endl;
		cout << "\t\tYo "; cin >> form1;
		cout << "\t\tTu "; cin >> form2;
		cout << "\t\tEl/Ella/Usted "; cin >> form3;
		cout << "\t\tEllos/Ellas/Ustedes "; cin >> form4;
		cout << "\t\tNosotros "; cin >> form5;
		cout << "\t\tVosotros "; cin >> form6;
	}	
	void getCount(){
		ifstream file;
		file.open("Counter.txt", ios::in);
		file >> count;
		file.close();
	}
	void updateCount(){
		ofstream file;
		file.open("Counter.txt", ios::trunc);
		file << count;
		file.close();
	}
	void exportValues(){
		ofstream file;
		file.open("Conjugations.txt", ios::app);
		count++;
		updateCount();
		file << count <<". Conjugaciónes del verbo " << baseVerb << endl;
		file << "\tYo " << form1 << endl;
		file << "\tTú " << form2 << endl;
		file << "\tÉl/Ella/Usted " << form3 << endl;
		file << "\tEllos/Ellas/Ustedes " << form4 << endl;
		file << "\tNosotros " << form5 << endl;
		file << "\tVosotros " << form6 << endl;
		file << "\n";
		file.close();
	}
};

int main(){
	system("color 70");
	CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0;
    cfi.dwFontSize.Y = 19;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    std::wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	//The above lines set the formatting of the output, and have no bearing on the logic of the actual program.
	
	int choice1, choice2, choice3;
	verb x;
	while(1){
		system("cls");
		x.getCount();
		cout << "\n\n\t\t-----------SPANISH CONJUGATIONS-------------\n\n\n";
		cout << "\t1. Enter new conjugation" << endl;
		cout << "\t2. Exit program" << endl;
		cout << "\n\tPlease enter your choice to continue: ";
		cin >> choice1;
		if(choice1==2){
			return 0;
		}
		else{
			a:
			system("cls");
			x.getValues();
			cout << "\n\tPlease make sure the given data has no typos or other errors.";
			cout << "\n\tPress 1 to edit the entered verb forms, or press 2 to continue: ";
			cin >> choice2;
			if(choice2==1){
				goto a;
			}
			x.exportValues();
			cout << "\n\tThanks! The conjugation has been recorded. Press any key to continue.";
		}
	}
	getch();
	return 0;
}
