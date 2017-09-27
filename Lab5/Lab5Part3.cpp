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
int amountofOn = 0;
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
	unsigned short x;
	_asm {
		mov		BX, moment
		mov		ECX, amountofOn

		mov		EBX, 0

	ForLoop:
		cmp		EBX, 15
		jge		DoneLoop				;  finish loop


		mov		x, 0xF000
		and		x, BX 
h		je		IsWorking

		mov		EBX, defective 
		call	displayDefective
		jmp    ShiftLoop

	IsWorking:  
		inc		amountofOn

	ShiftLoop:
		shl		BX, 1
		inc		EBX
		jmp		ForLoop

	DoneLoop: 
	}
	cout << amountofOn << " sprinklers are ON. " << endl;
}

void displayDefective() {
	cout << defective;
}
