/*---------------------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  5 Sept 2017
Last edited:  6 Sept 2017
This program will prompt for a sides and height of a triangle and 
width and length of the rectangle.  
It will then use ASSEMBLY to calculate the conversion.
-----------------------------------------------------------------*/

#include <iostream>
using namespace std;

void displayShape();
int calcTriArea(int c, int h);
int calcTriPeri(int a, int b, int c);
int calcRectArea(int width, int lengths);
int calcRectPeri(int width, int lengths);

int main() {
	int a, b, c, h, triArea, triPeri;
	int width, length, rectArea, rectPeri;
	displayShape();
	cout << "Enter the values of a,b,c and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> length >> width;

	triArea = calcTriArea(c, h);
	triPeri = calcTriPeri(a, b, c);
	rectArea = calcRectArea(width, length);
	rectPeri = calcRectPeri(width, length);

	cout << "\tTriangle\n\t\tArea..............." << triArea;
	cout << "\n\t\tPerimeter.........." << triPeri << endl;

	cout << "\tRectangle\n\t\tArea..............." << rectArea;
	cout << "\n\t\tPerimeter.........." << rectPeri << endl;

	return 0;
}

void displayShape() {
	cout << "     /|\\     \t-------------\n";
	cout << "    / | \\    \t|           |\n";
	cout << "a  /  |  \\  b\t|           |width\n";
	cout << "  /  h|   \\  \t|           |\n";
	cout << " /    |    \\ \t|           |\n";
	cout << " -----------  \t-------------\n";
	cout << "      c       \t   length    \n";
}

int calcTriArea(int c, int h) {
	int area;
	_asm {
		mov eax, c     ; eax = c
		mov ebx, h     ; ebx = h
		imul ebx       ; eax = h*c
		mov ecx, 2     ; ecx = 2
		idiv ecx       ; h*c / 2
		mov area, eax
	}
	return area;
}

int calcTriPeri(int a, int b, int c) {
	int perimeter;
	_asm {
		mov eax, a
		add eax, b
		add eax, c
		mov perimeter, eax
	}
	return perimeter;
}

int calcRectArea(int width, int lengths) {
	int area;
	_asm {
		mov eax, width
		imul lengths
		mov area, eax
	}
	return area;
}

int calcRectPeri(int width, int lengths) { //needs to be "lengths", not "length" because assembly language uses "length" already
	int perimeter;
	_asm {
		mov eax, width
		add eax, lengths
		add eax, eax
		mov perimeter, eax
	}
	return perimeter;
}
/*
     /|\        -------------
    / | \       |           |
a  /  |  \  b   |           |width
  /  h|   \     |           |
 /    |    \    |           |
 -----------    -------------
       c            length
Enter the values of a,b,c and h for the triangle: 4 6 9 10
Enter the length and the width of the rectangle: 15 10
    Triangle
        Area...............45
        Perimeter..........19
	Rectangle
	    Area...............150
	    Perimeter..........50
Press any key to continue . . .
*/