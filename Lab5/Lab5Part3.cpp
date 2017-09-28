/*-----------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  26 September 2017
Last edited:  26 September 2017
This program will identify which sprinklers are on and off
given a hexadecimal number.
-----------------------------------------------------*/

#include<iostream>
using namespace std;

unsigned short moment = 0x6A2F;
int amountofOn = 1;
int defective;

void convertToBinary();
void checkOnSprink();
void displayDefective();


int main() {

	convertToBinary();
	checkOnSprink();
	
	system("pause");
	return 0;
}

void convertToBinary() {
	unsigned short x = 1 << 15;
	unsigned short tempMoment = moment;
	short t;
	cout << x << endl;
	for (int i = 1; i <= 16; i++) {
		t = tempMoment & x;
		tempMoment = tempMoment << 1;
		if (t == 0) {
			cout << "0";
		}
		else {
			cout << "1";
		}
		if (i % 4 == 0) cout << " ";
	}
	cout << endl;
}

void checkOnSprink() {
	_asm {
		mov		AX, 0x6A2F
		mov		EBX, 0					;  index  

	ForLoop:
		cmp		EBX, 15
		jge		DoneLoop				;  finish loop

		mov		CX, 0xF000
		and		CX, AX 
		shr		CX, 15
		cmp		CX, 1
		je		IsOn

		jmp		ShiftLeft


	IsOn:  
		inc		amountofOn

	ShiftLeft:
		inc		EBX 
		shl		AX, 1
		jmp		ForLoop


	DoneLoop: 
	}
	cout << amountofOn << " sprinklers are ON. " << endl;
}

void displayDefective() {
	cout << defective;
}
