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

void displayMenu();  //  display the menu
short calculateIndividual(short, short);  //  function to calculate the individual item
short finalBill(short, short);


int main() {

	short drinksAmount, sandwichAmount, finalAmount;
	displayMenu();

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

	system("pause");
	return 0;
}

void displayMenu() {
	string dashed = "--------------------";  //  20 dashes
	string dotted = "................................";  //  32 dots
	cout << dashed << "MENU" << dashed << endl;
	cout << "Drinks...." << dotted << "$2" << endl;
	cout << "Sandwiches" << dotted << "$4" << endl;
}

short calculateIndividual(short amt, short price) {
	short c;
	//  enter assembly
	_asm {
		mov		AX, price
		imul	amt
		mov		c, AX 
	}
	return c;
}

short finalBill(short drink, short sandwich) {
	short t;
	//  enter assembly
	_asm {
		mov		BX, drink
		add		BX, sandwich  
		mov		t, BX 
	}
	return t;
}