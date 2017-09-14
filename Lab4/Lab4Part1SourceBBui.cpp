/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  14 September 2017
Last edited:  14 September 2017

This program will counter the amount of yes and no votes given by the user.

It will then print stars equal to the votes.

*/

#include<iostream>
#include<string>
using namespace std;

int yesVote = 0, noVote = 0;
char c;

void prompt();
void checkChar();
void process();
void printStar();
void loop(int);
void display();


int main() {

	prompt();
	process();

	system("pause");
	return 0;
}

void prompt() {
	cout << "Enter a string of votes:  ";
}

void checkChar() {
	cin.get(c);
}

void process() {
	_asm {
				call	checkChar
	WhileLoop:
				cmp		c, '\n'
				je		DoneWhile 

				cmp		c, 'y'
				je		IncYes

				cmp		c, 'n'
				je		IncNo

	ReadNext:
				call	checkChar
				jmp		WhileLoop

	IncYes:
				inc		yesVote
				jmp		ReadNext

	IncNo:		
				inc		noVote 
				jmp		ReadNext

	DoneWhile:
	}
	display();
}

void display() {
	cout << "No. of YES Votes = " << yesVote << " = ";
	loop(yesVote);
	cout << endl << "No. of NO Votes = " << noVote << " = ";
	loop(noVote);
	cout << endl;
}

void loop(int num) {
	_asm {
				mov		EBX, 0
	ForLoop:
				cmp		EBX, num
				jge		DoneLoop
				call	printStar
				inc		EBX
				jmp		ForLoop

	DoneLoop: 

	}
}

void printStar() {
	cout << "* ";
}