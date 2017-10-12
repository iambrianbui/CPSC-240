/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  9 October 2017
Last edited:  9 October 2017
This program will calculate a quadratic formula using assembly.


*/

#include<iostream>
#include<iomanip>
using namespace std;

float a, b, c, inside, X1, X2;
float zero = 0, two = 2, four = 4;

void insideSqrt() {
	_asm {
		fld b
		fld b              ;postfix = bb*(four)ac**-
		fmul
		fld four
		fld a 
		fld c
		fmul
		fmul
		fsub
		fsqrt
		fstp inside
	}
}

void calcX1() {
	_asm {
		fld zero
		fld b
		fsub
		fld inside         ;postfix = 0b-(inside)+(two)a*/
		fadd 
		fld two 
		fld a
		fmul
		fdiv
		fstp X1
	}
}

void calcX2() {
	_asm {
		fld zero
		fld b
		fsub				;postfix = 0b-(inside)-(two)a*/
		fld inside
		fsub 
		fld two 
		fld a
		fmul
		fdiv
		fstp X2
	}
}

int main() {
	cout << "To see the two real roots of ax^2 + bx + c = 0, \nEnter the a,b, and c values: ";
	cin >> a >> b >> c;
	
	insideSqrt();
	calcX1();
	calcX2();

	cout << fixed << showpoint << setprecision(2);

	cout << "\tX1 = " << X1 << "\tX2 = " << X2 << endl;
	system("pause");
	return 0;
}
