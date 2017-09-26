/*-----------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  24 September 2017
Last edited:  24 September 2017
This program find te number of printers connected to computer,
the number of floppy drives, and the size of the RAM, based on 
bx in the main function.
-----------------------------------------------------*/

#include <iostream>
using namespace std;

short printerNum, floppyNum, sizeRAM;
short test;

void printerAmount() {
	_asm {
			mov cx, 1100000000000000b	
			and cx, bx					;uses cx because do not want to change original
			shr cx, 14					;shifts right 14 times to get the 2 significant bits to most right
			mov printerNum, cx
	}
}

void floppyAmount() {
	_asm {
			mov cx, 0000000011000000b
			and cx, bx					;uses cx because do not want to change original
			shr cx, 6					;shifts right 6 times to get the 2 significant bits to most right
			mov floppyNum, cx
			inc floppyNum
	}
}

void getRAMsize() {
	_asm {
			mov cx, 0000000000001100b
			and cx, bx					;uses cx because do not want to change original
			shr cx, 2					;shifts right 2 times to get the 2 significant bits to most right
			cmp cx, 0x0000				;compares the 2 bit to see what size of RAM is
			Je sixteen
			cmp cx, 0x0001
			Je thirtytwo
			cmp cx, 0x0002
			Je fourtyeight
			cmp cx, 0x0003
			Je sixtyfour
	sixteen :
			mov sizeRAM, 16
	thirtytwo :
			mov sizeRAM, 32
	fourtyeight :
			mov sizeRAM, 48
	sixtyfour :
			mov sizeRAM, 64
	}
}


int main() {
	_asm {
			mov bx, 1100111010011100b
			call printerAmount
			call floppyAmount
			call getRAMsize
	}
	cout << "Number of printers connected to the computer: " << printerNum << endl;
	cout << "Number of floppy drives: " << floppyNum << endl;
	cout << "Size of RAM: " << sizeRAM << "GB" << endl;
	system("pause");
	return 0;
}

/*-------------Output:------------------------------
Number of printers connected to the computer: 3
Number of floppy drives: 3
Size of RAM: 64GB
Press any key to continue . . .
--------------------------------------------------*/