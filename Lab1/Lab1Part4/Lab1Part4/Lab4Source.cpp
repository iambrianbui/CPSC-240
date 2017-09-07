/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  5 September 2017
Last edited:  6 September 2017
This program will display the sum of a 3 digit number.
*/

#include<iostream>
using namespace std;

void inter(int);  //  display the interface, and loop if necessary 
int calculate(int);  //  calculate the sum of digits


int main() {


	inter(1);
	system("pause");
}

void inter(int x) {

	if (x != 0) {  //  exit the function if 0 is inputted at the prompt
		int number;

		cout << "Please enter a three digit number:  ";
		cin >> number;
		cout << "The sum of the digits is:  " << calculate(number) << endl;
		cout << "Press 0 to exit the program." << endl;
		cin >> x;
		inter(x);
	}


}


//  this function will calculate the digits
int calculate(int number) {
	const int hund = 100, ten = 10;  //  constant numbers for assembly
	int hundDigit, tenDigit, oneDigit;  //  different digit places
	_asm {
		//  hundred's place
		mov			EAX, number				;  EAX = number  
		cdq									;  convert double word to quad word
		idiv		hund					;  divide 100 by EAX  
		mov			hundDigit, EAX			;  hundDigit = EAX  
		mov			tenDigit, EDX			;  tenDigit = EDX, or the remainder  


		//  ten's and one's place
		mov			EAX, tenDigit			;  EAX = tenDigit  
		cdq									;  convert double word to quad word  
		idiv		ten						;  divide 10 by EAX  
		mov			tenDigit, EAX			;  tenDigit = EAX  
		mov			oneDigit, EDX			;  oneDigit = EDX, on the remainder
	}


	return hundDigit + tenDigit + oneDigit; //  return the sum
}
