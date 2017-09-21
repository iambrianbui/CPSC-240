#include <iostream>
using namespace std;

short printerNum, floppyNum, sizeRAM;
short test;

void printerAmount(){
	_asm{
		mov cx, 1100000000000000b
		and cx, bx
		shr cx, 14
		mov printerNum, cx
	}
}

void floppyAmount(){
	_asm {
		mov cx, 0000000011000000b
		and cx, bx
		shr cx, 6
		mov floppyNum, cx
		inc floppyNum
	}
}

void getRAMsize(){
	_asm {
		mov cx, 0000000000001100b
		and cx, bx
		shr cx, 2
		cmp cx, 0x0000
		Je sixteen			
		cmp cx, 0x0001
		Je thirtytwo			
		cmp cx, 0x0002
		Je fourtyeight
		cmp cx, 0x0003
		Je sixtyfour
sixteen:
		mov sizeRAM, 16
thirtytwo:
		mov sizeRAM, 32
fourtyeight:
		mov sizeRAM, 48
sixtyfour:
		mov sizeRAM, 64
	}
}


int main(){
	_asm{
		mov bx, 1100111010011100b
		call printerAmount
		call floppyAmount
		call getRAMsize
	}
	cout << "Number of printers connected to the computer: " << printerNum << endl;
	cout << "Number of floppy drives: " << floppyNum << endl;
	cout << "Size of RAM: " << sizeRAM << "GB" <<endl;
	return 0;
}