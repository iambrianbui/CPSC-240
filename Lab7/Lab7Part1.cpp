/*---------------------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  10 October 2017
Last edited: 10 October 2017
This program will prompt for a sides and height of a triangle and
width and length of the rectangle.
It will then use ASSEMBLY to calculate the conversion.
-----------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
using namespace std;

float two = 2;
float a, b, c, h, triArea, triPeri;
float lengths, width, rectArea, rectPeri;

void displayShape() {
	cout << "     /|\\     \t-------------\n";
	cout << "    / | \\    \t|           |\n";
	cout << "a  /  |  \\  b\t|           |width\n";
	cout << "  /  h|   \\  \t|           |\n";
	cout << " /    |    \\ \t|           |\n";
	cout << " -----------  \t-------------\n";
	cout << "      c       \t   length    \n";
}

void calcTriArea() {
	_asm {
		fld h 
		fld c					;postfix = hc*2/
		fmul
		fld two
		fdiv
		fstp triArea
	}
}

void calcTriPeri() {
	_asm {
		fld a
		fld b 
		fadd					; postfix = ab+c+
		fld c
		fadd
		fstp triPeri
	}
}

void calcRectArea() {
	_asm {
		fld width				;postfix = wl*
		fld lengths
		fmul
		fstp rectArea
	}
}

void calcRectPeri() { //needs to be "lengths", not "length" because assembly language uses "length" already
	_asm {
		fld width
		fld width
		fadd					;postfix = ww+l+l+
		fld lengths
		fadd
		fld lengths
		fadd
		fstp rectPeri
	}
}

int main() {
	displayShape();

	cout << "Enter the values of a,b,c, and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: : ";
	cin >> lengths >> width;

	calcTriArea();
	calcTriPeri();
	calcRectArea();
	calcRectPeri();

	cout << fixed << showpoint << setprecision(2); //force 2 decimal places

	cout << "\tTriangle\n\t\tArea..............." << triArea;
	cout << "\n\t\tPerimeter.........." << triPeri << endl;
	cout << "\tRectangle\n\t\tArea..............." << rectArea;
	cout << "\n\t\tPerimeter.........." << rectPeri << endl;
	return 0;
}