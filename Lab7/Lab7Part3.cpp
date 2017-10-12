/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  9 October 2017
Last edited:  9 October 2017
This program will display a menu and prompt the user for their order.  It will then use ASSEMBLY to calculate
the price of the bill.
The program will also utilize comparisons and jumps as substitutes for conditional statements.
*/

#include<iostream>
#include<string>
using namespace std;

float totalBill, amtDrink, amtSand;
int sandChoice;
char drinkChoice;

void displayMenu();					//  display the menu 
void prompt();						//  update globals 
void calculate();					//  actual assembly

int main() {

	displayMenu();
	prompt();
	calculate();
	system("pause");
	return 0;
}

void displayMenu() {
	string lines = "--------------------";  //  20 dashes
	string dots = "...................";  //  20 dots
	cout << lines << "7-11 Convenient Store" << lines << endl;
	cout << "Drinks" << endl;
	cout << "\t Soda(S).." << dots << dots << "$2.25" << endl;
	cout << "\t Water(W)." << dots << dots << "$1.75" << endl;
	cout << "Sandwiches" << endl;
	cout << "\t 10 inches" << dots << dots << "$3.45" << endl;
	cout << "\t 12 inches" << dots << dots << "$5.25" << endl;
}

void prompt() {

		cout << "How many drinks?  ";
		cin >> amtDrink;
		cout << "\tWhat kind of drink?  (S=Soda, W=Water)  ";
		cin >> drinkChoice;

	//  ask for amount of sandwiches and how many
		cout << "How many Sandwiches?  ";
		cin >> amtSand;
		cout << "\tWhat size of sandwich (10/12 inches)?  ";
		cin >> sandChoice;
}

void calculate() {
	//  amount * price
	float soda = 2.25, water = 1.75, ten = 3.45, twelve = 5.25;

	_asm {
			fld		amtDrink
			cmp		drinkChoice, 'S'
			je		SodaDrink

			cmp		drinkChoice, 's'
			je		SodaDrink				;  Default drink is water
			fld		water  

			jmp		DrinkDone

		SodaDrink :
			fld		soda 					;  load soda

		DrinkDone :
			fmul 
			fstp	amtDrink					;  pop

			fld		amtSand					;  load
			cmp		sandChoice, 10
			je		Sand10

			fld		twelve				;  Default sandwich is 12 inches
			jmp		SandDone

		Sand10 :
			fld		 ten					

		SandDone :
			fmul 
			fstp	amtSand 
						
			fld		amtDrink			;  add the floats
			fld		amtSand
			fadd 
			fstp	totalBill

	}
	cout << "Total bill:  " << totalBill << endl;
	cout << amtDrink << endl << amtSand << endl;
}
