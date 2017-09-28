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

unsigned short moment = 0x6A2F;					//  AX register at this moment
int amountofOn = 0;
int defective[16];

void convertToBinary();
void checkOnSprink();
//  void displayDefective();					see note at defintion
void displayD();


int main() {

	convertToBinary();
	checkOnSprink();
	//  displayDefective();
	displayD();

	system("pause");
	return 0;
}

//  convert to binary from hexadec
void convertToBinary() {
	unsigned short x = 1 << 15;					//  shift over 15 to the left
	unsigned short tempMoment = moment;			
	short t;									//  proxy
	cout << "AX = ";
	for (int i = 1; i <= 16; i++) {
		t = tempMoment & x;
		tempMoment = tempMoment << 1;
		if (t == 0) {
			cout << "0";
			defective[i] = 1;
		}
		else {
			cout << "1";
		}
		if (i % 4 == 0) cout << " ";
	}
	cout << endl;
}

//  check which sprinklers are on
void checkOnSprink() {
	_asm {
		mov		AX, 0x6A2F
		mov		EBX, 0					;  index  

	ForLoop:
		cmp		EBX, 16
		jge		DoneLoop				;  finish loop

		mov		CX, 0xF000				;  set to 1000 ...
		and		CX, AX					
		shr		CX, 15					;  see if it's 1 or 0
		cmp		CX, 0
		jne		IsOn
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


/*
For some reason, Assembly is changing the value of AX despite the initalization of the register.
My partner and I could not work around this bug/error, so we are opting to put both functions in
one function.


//  display which sprinklers are off
void displayDefective() {
	cout << "Defective sprinklers:  ";
	_asm {
		mov		AX, 0x6A2F
		mov		EBX, 16					;  index

	ForLoop2:
		cmp		EBX, 0
		jle		DoneLoop2				;  finish loop

		mov		CX, 1
		and		CX, AX 
		cmp		CX, 1
		je		ShiftRight 
		
		mov		defective, EBX 
		call	displayD

	ShiftRight:
		dec		EBX 
		shr		AX, 1
		jmp		ForLoop2



	DoneLoop2:
	}
	cout << endl;
}
*/


void displayD() {
	cout << "Defective sprinklers:  ";
	for (int i = 0; i < 16; i++) {
		if (defective[i] == 1) {
			cout << 17-i << " ";
		}
	}
	cout << endl;
}

/*-----------------Output-------------------
AX = 0110 1010 0010 1111
9 sprinklers are ON.
Defective sprinklers:  16 13 11 9 8 7 5
Press any key to continue . . .
-------------------------------------------*/
