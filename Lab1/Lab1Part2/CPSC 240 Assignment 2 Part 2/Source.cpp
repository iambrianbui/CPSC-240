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
		mov eax, c
		imul h
		//cannot finish because need to divide by 2. h*base/2
	}
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