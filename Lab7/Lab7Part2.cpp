/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  9 October 2017
Last edited:  9 October 2017
This program will calculate a quadratic formula using assembly.


*/

#include<iostream>
using namespace std;


void prompt();
void answer(float, float, float);
float positiveRoots(float,float,float);

int main() {

	prompt();
	system("pause");
	return 0;
}

void prompt() {
	float a, b, c;
	cout << "To see the two real roots of ax^2 + bx + c = 0, \nEnter the a,b, and c values:  " << endl;
	cin >> a >> b >> c;
	answer(a, b, c);
}

void answer(float a, float b, float c) {
	float x1, x2;
	cout << "The answers are:  " << endl;
	x1 = positiveRoots(a,b,c);
	cout << x1 << endl;
}

float positiveRoots(float a, float b, float c) {
	float ans = 0;
	float two = 2, four = 4;
	_asm {
		fld			b
		fld			b
		fmul		
		fld			four
		fld			a 
		fld			c
		fmul 
		fmul
		fsub
		//fsqrt
		fstp		ans
	}

	return ans;
}
