#include<iostream>
#include<string>

using namespace std;

void menu();
void prompt();
int calculate(int, int, int, int);

int main() {

	menu();
	prompt();
	return 0;
}

void menu(){
	string dots = "....................";  //  20 dots
	cout << "----------7-11 Convenient Store----------" << endl;
	cout << "Soda(S)" << dots << "$2" << endl;
}

void prompt(){
	int totalBill, amtDrink, drinkChoice, amtSand, sandChoice;
	char drinkCh;

	cout << "How many drinks?  ";
	cin >> amtDrink;
	cout << endl << "\tWhat kind of drink?  (S=Soda, W=Water)";
	cin >> drinkCh;
	if (drinkCh == 'S' || drinkCh == 's') {
		drinkChoice = 2;
	}
	else drinkChoice = 1;
	cout << endl << "How many Sandwiches?";
	cin >> amtSand;
	cout << endl << "\tWhat size of sandwich (10/12 inches)?";
	cin >> sandChoice;
	if (sandChoice == 10) {
		sandChoice = 3;
	}
	else sandChoice = 5;



	totalBill = calculate(amtDrink, drinkChoice, amtSand, sandChoice);
}

int calculate(int amtDrink, int drinkChoice, int amtSand, int sandChoice) {
	return 1;
}