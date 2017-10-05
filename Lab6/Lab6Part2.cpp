/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  3 October 2017
Last edited:  5 October 2017
This program will use assembly to bubble sort.

*/

#include<iostream>

int a[5] = { 9,3,22,8,1 };
int index = 0, indexJ = 0;

void bubbleSort();										//  2d forloop
void checkBubble();										//  do we have to switch?
void displayArray();									//  display array
void swapB();											//  swap the elements

using namespace std;

int main() {

	displayArray();
	bubbleSort();
	displayArray();
	system("pause");
	return 0;
}

void bubbleSort() {
	int temp = 0, tempECX, tempEBX;						//  using a lot of temp variables as substitutes for registers
	_asm {
		mov			ebx, index 
	ForLoop1:
		cmp			ebx, 4
		jge			DoneLoop
		mov			indexJ, 0							;  IMPORTANT TO STOP INFINITE LOOP!!!!
		mov			ecx, indexJ


		ForLoop2:
			mov			temp, 5
			sub			temp, ebx
			dec			temp
			cmp			ecx, temp
			jge			Done2
			mov			tempECX, ecx					;  proxy 
			mov			tempEBX, ebx					;  proxy

			call		checkBubble						;  see if we need to bubbleSort
			mov			ecx, tempECX
			inc			ecx
			mov			indexJ, ecx
			jmp			ForLoop2


		Done2:					
			mov			ebx, tempEBX
			inc			ebx 
			jmp			ForLoop1 

	DoneLoop:


	}


}

void checkBubble() {
	_asm {
		mov			eax, indexJ							;  get the index 
		mov			ebx, [a + eax * 4]					;  a[j]
		mov			ecx, [a + 4 + eax * 4]				;  a[j+1]
		cmp			ebx, ecx							;  check if greater than 
		jle			Done
		call		swapB
	Done:  

	}
}


void displayArray() {
	cout << "a:  ";
	for (int i = 0; i < 5; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

void swapB() {
	int temp;

	temp = a[indexJ];									//  pass the index through the global variable
	a[indexJ] = a[indexJ+1];
	a[indexJ+1] = temp;
}
