#include<iostream>
#include<string>

using namespace std;

void menu();
void promptDrinks();
void promptSandwiches();
void calculate();

int totalBill, amtDrink, amtSand, sandChoice;
char drinkChoice;

int main() {

	menu();
	calculate();
	system("pause");
	return 0;
}

void menu(){
	string dots = "....................";  //  20 dots
	cout << "----------7-11 Convenient Store----------" << endl;
	cout << "Drinks" << endl;
	cout << "\tSoda(S)...." << dots << "$2" << endl;
	cout << "\tWater(W)..." << dots << "$1" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t10 inches.." << dots << "$3" << endl;
	cout << "\t12 inches.." << dots << "$5" << endl;
}

void promptDrinks(){
	cout << "How many drinks?  ";
	cin >> amtDrink;
	cout << "\tWhat kind of drink?  (S=Soda, W=Water)  ";
	cin >> drinkChoice;
}

void promptSandwiches() {
	cout << endl << "How many Sandwiches?  ";
	cin >> amtSand;
	cout << "\tWhat size of sandwich (10/12 inches)?  ";
	cin >> sandChoice;
}

void calculate() {
	_asm {
			call	promptDrinks
			cmp		drinkChoice, 'S' 
			je		SodaDrink

			cmp		drinkChoice, 's'
			je		SodaDrink

			mov		EAX, 1
			imul	amtDrink
			jmp		DrinkDone
	
		SodaDrink:
			mov		EAX, 2
			imul	amtDrink 

		DrinkDone:
			mov		totalBill, EAX

			call	promptSandwiches
			cmp		sandChoice, 10
			je		Sand10 

			mov		EAX, 12
			imul	amtSand
			jmp		SandDone

		Sand10:
			mov		EAX, 10
			imul	amtSand

		SandDone:
			add		totalBill, EAX

	}
	cout << "Total bill:  " << totalBill;
}