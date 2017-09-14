/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  12 September 2017
Last edited:  13 September 2017
This program will analyze a sentence given by the user and dissect the amount of uppercase and lowercase letters.

The program will also utilize comparisons and jumps as substitutes for conditional statements.
*/

#include<iostream>
using namespace std;

void askForSent();
void readChar();
void processChar();
void display();

int upper = 0, lower = 0;
char c;

int main() {
	processChar();
	display();

	system("pause");
	return 0;

}

//  prompt user for sentence
void askForSent() {
	cout << "Enter a sentence:  :" << endl;

}


//  read the next character
void readChar() {
	cin.get(c);
}

void processChar() {
	_asm {
			call	askForSent				;  ask for character first
			call	readChar
	WhileLoop:								;  start while loop
			cmp		c, '\n'
			je		EndWhile 
			cmp		c, 'Z'
			jle		LessThanZ				;  c < Z
			cmp		c, 'z'
			jle		LessThanLowerz			;  c < z 

	ReadLoop:								;  go here after done with letter
			call	readChar 
			jmp		WhileLoop			

	LessThanZ:
			cmp		c, 'A'
			jge		CapitalLetter			;  c < A 
			jmp		ReadLoop				;  failed

	LessThanLowerz:
			cmp		c, 'a'
			jge		LowerLetter
			jmp		ReadLoop 

	CapitalLetter:							;  increase upper counter

			inc		upper 
			jmp		ReadLoop 

	LowerLetter:							;  increase lower counter
			inc		lower 
			jmp		ReadLoop

	EndWhile:								;  done
	}
}

void display() {
	cout << "No. of uppercase letters:  " << upper << endl
		<< "No. of lowercase letters:  " << lower << endl;
}