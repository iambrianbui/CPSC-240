/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  31 August 2017
Last edited:  31 August 2017

This program will display a menu and prompt the user for their order.  It will then use ASSEMBLY to calculate
the price of the bill.



*/

#include<iostream>
#include<string>
using namespace std;

void inter(int);  //  prompt interface and set up loop
void displayMenu();  //  display the menu
short calculateIndividual(short, short);  //  function to calculate the individual item
short finalBill(short, short);  //  add the shorts


int main() {

	inter(1);  //  run interface
	system("pause");
	return 0;
}


void inter(int x) {
	if (x != 0) {  //  if x is not 0, run program
		short drinksAmount, sandwichAmount, finalAmount;  //  drink amount, sandwich amount, final bill
		displayMenu();  //  display the menu

		//  drinks
		cout << "\tHow many drinks?  ";
		cin >> drinksAmount;
		drinksAmount = calculateIndividual(drinksAmount, 2);

		//  sandwiches
		cout << "\tHow many sandwiches?  ";
		cin >> sandwichAmount;
		sandwichAmount = calculateIndividual(sandwichAmount, 4);

		finalAmount = finalBill(drinksAmount, sandwichAmount);

		cout << "\t\tYour total bill is:  $" << finalAmount << endl;
	}  //  if x is 0, exit
}

void displayMenu() {
	string dashed = "--------------------";  //  20 dashes
	string dotted = "................................";  //  32 dots
	cout << dashed << "MENU" << dashed << endl;
	cout << "Drinks...." << dotted << "$2" << endl;
	cout << "Sandwiches" << dotted << "$4" << endl;
}

short calculateIndividual(short amt, short price) {
	short c;  //  proxy memory
	//  enter assembly
	_asm {
		mov		AX, price				;  AX = price
		imul	amt						;  multiply AX by amt  
		mov		c, AX					;  c = AX  
	}
	return c;  
}

short finalBill(short drink, short sandwich) {
	short t;  //  proxy memory
	//  enter assembly
	_asm {
		mov		BX, drink				;  BX = drink 
		add		BX, sandwich			;  add BX and sandwich  
		mov		t, BX					;  t = BX + sandwich
	}
	return t;
}