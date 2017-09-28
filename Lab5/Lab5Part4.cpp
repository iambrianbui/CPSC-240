/*-----------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  27 September 2017
Last edited:  27 September 2017
This program will identify the floor of a hotel and where
to stop as an elevator
-----------------------------------------------------*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int randomFloors[10];
short doIGoHere[16];

short floorNo;
int k, thisOne;  //  global index and floor to pass


void randomizeFloors();
void display();
void whereWillIStop();
void nextFloor();
void displayStop();


int main() {
	randomizeFloors();
	display();
	whereWillIStop();
	cout << endl;
	system("pause");
	return 0;
}


//  randomize numbers
void randomizeFloors() {
	for (int i = 0; i < 10; i++) {
		randomFloors[i] = rand() % 15 + 2;
	}
}


//  display in binary 
void display() {
	cout << "AX = ";
	//  place floors from RNG to binary array
	for (int i = 0; i < 10; i++) {
		doIGoHere[randomFloors[i]+1] = 1;
	}


	//  display floors
	for (int i = 15; i >= 0; i--) {
		if (doIGoHere[i] == 1) {
			cout << "1";
		}
		else cout << "0";
		if (i % 4 == 0) cout << " ";
	}
	cout << endl;
}


//  determine where to stop
void whereWillIStop() {
	floorNo = doIGoHere[0];
	cout << "Elevator will stop at floors no. ";
	_asm {
			mov			EBX, 0
	ForLoop:											;  for loop
			cmp			EBX, 16
			jge			DoneLoop

			mov			CX, 1
			and			CX, floorNo
			cmp			CX, 1
			jne			NextNum						
			mov			thisOne, EBX					;  if this is a stop, then display
			call		displayStop						

	NextNum:											;  call the next number
			inc			EBX
			mov			k, EBX
			call		nextFloor

			jmp			ForLoop
	DoneLoop:											;  end loop  
	}
}


//  advance to the next floor
void nextFloor() {
	floorNo = doIGoHere[k];
}


//  display stop
void displayStop() {
	short proxy;
	proxy = 1 +  thisOne;
	cout << proxy << " ";
}