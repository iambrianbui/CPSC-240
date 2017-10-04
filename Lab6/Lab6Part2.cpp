/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  3 October 2017
Last edited:  3 October 2017
This program will use assembly to bubble sort.

*/

#include<iostream>

int a[5] = { 9,3,22,8,1 };

void bubbleSort();
void displayArray();

using namespace std;

int main() {

	displayArray();
	bubbleSort();
	displayArray();
	system("pause");
	return 0;
}

void bubbleSort() {
	int n = 5;
	int i = 0;
	int j = 0;
	int temp;
	_asm {
		mov				eax, i
	Loop1:  
		cmp				eax, 4
		jge				DoneLoop

			mov				ebx, j
			Loop2:  
				mov				ecx, n
				sub				ecx, eax
				sub				ecx, 1 
				cmp				ebx, n
				jge				OutOfLoop 

					cmp				[a + ebx*4], [a + 4 + ebx*4]
					jle				Next
					mov				temp, [a + ebx * 4]
					mov				[a + ebx * 4], [a + 4 + ebx * 4]
					mov				[a + 4 + ebx*4], temp

				Next:

				inc				ebx
				
		OutOfLoop:
		inc				eax

	DoneLoop:
	}
}


void displayArray() {
	cout << "a:  ";
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

