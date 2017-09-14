/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  11 September 2017
Last edited:  13 September 2017
This program will display a menu and prompt the user for their order.  It will then use ASSEMBLY to calculate
the price of the bill.

The program will also utilize comparisons and jumps as substitutes for conditional statements.  
*/

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

//  menu prompt
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

//  ask for amount of drinks and how many
void promptDrinks(){
	cout << "How many drinks?  ";
	cin >> amtDrink;
	cout << "\tWhat kind of drink?  (S=Soda, W=Water)  ";
	cin >> drinkChoice;
}

//  ask for amount of sandwiches and how many
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

			mov		EAX, 1						;  Default drink is water
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

			mov		EAX, 5						;  Default sandwich is 12 inches  
			imul	amtSand
			jmp		SandDone

		Sand10:
			mov		EAX, 3
			imul	amtSand

		SandDone:
			add		totalBill, EAX

	}
	cout << "Total bill:  " << totalBill << endl;
}