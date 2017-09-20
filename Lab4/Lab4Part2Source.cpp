/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  19 September 2017
Last edited:  19 September 2017
This program will get a sentence and print each character one by one.
If it's a vowel, it will be uppercased.
*/

#include <iostream>
using namespace std;

char c;

void getChar() {
	cin.get(c);
}

void printLower() {
	cout << c;
}

void printUpper() {
	c = toupper(c);
	cout << c;
}

void convert() {
	_asm {
	startloop :
			call	getChar
			cmp		c, '\n'
			Je		done
			cmp		c, 'a'
			Je		isUpper
			cmp     c, 'e'
			Je      isUpper
			cmp     c, 'i'
			Je      isUpper
			cmp     c, 'o'
			Je      isUpper
			cmp     c, 'u'
			Je      isUpper
			call    printLower
			Jmp     startloop
	isUpper :
			call	printUpper
			Jmp		startloop
	done :
	}
}

int main() {
	cout << "Enter a sentence: ";
	convert();
	cout << endl;
	return 0;
}

/*-------------------------------------
Output:
Enter a sentence: proud is self-respect.
prOUd Is sElf-rEspEct.
Press any key to continue . . .
-------------------------------------*/
