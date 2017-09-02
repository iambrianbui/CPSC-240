#include <iostream>
using namespace std;

void displayShape();
int calcTriPeri(int a, int b, int c);

int main() {
	int a, b, c, h, triArea, triPeri;
	int width, length, rectArea, rectPeri;
	displayShape();
	cout << "Enter the values of a,b,c and h for the triangle: ";
	cin >> a >> b >> c >> h;
	cout << "Enter the length and the width of the rectangle: ";
	cin >> length >> width;

	cout << "\tTriangle\n\t\tArea...............";
	cout << "\nPerimeter..........";
	triPeri = calcTriPeri(a, b, c);

	return 0;
}

void displayShape() {
	cout << "     /|\\     \t-------------\n";
	cout << "    / | \\    \t|           |\n";
	cout << "a  /  |  \\  b\t|           |width\n";
	cout << "  /  h|   \\  \t|           |\n";
	cout << " /    |    \\ \t|           |\n";
	cout << " -----------  \t-------------\n";
	cout << "      c       \t   length      ";
}

int calcTriPeri(int a, int b, int c) {
	int perimeter;
	_asm {
		mov eax,a
		add eax,b
		add eax,c
		mov perimeter, eax
	}
	return perimeter;
}

int calcRectPeri(int width, int length) {
	int perimeter;
	_asm {
		mov eax, width
		add eax, length
		add eax, eax
		mov perimeter, eax
	}
	return perimeter;
}