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


void askForSent() {
	cout << "Enter a sentence:  :" << endl;

}

void readChar() {
	cin.get(c);
}

void processChar() {
	_asm {
			call	askForSent
			call	readChar
	WhileLoop: 
			cmp		c, '\n'
			je		EndWhile 
			cmp		c, 'Z'
			jle		LessThanZ			;  c < Z
			cmp		c, 'z'
			jle		LessThanLowerz			;  c < z 

	ReadLoop: 
			call	readChar 
			jmp		WhileLoop			

	LessThanZ:
			cmp		c, 'A'
			jge		CapitalLetter		;  c < A 
			jmp		ReadLoop			;  failed

	LessThanLowerz:
			cmp		c, 'a'
			jge		LowerLetter
			jmp		ReadLoop 

	CapitalLetter:
			inc		upper 
			jmp		ReadLoop 

	LowerLetter:
			inc		lower 
			jmp		ReadLoop

	EndWhile: 
	}
}

void display() {
	cout << "No. of uppercase letters:  " << upper << endl
		<< "No. of lowercase letters:  " << lower << endl;
}