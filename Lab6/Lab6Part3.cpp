/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  4 October 2017
Last edited:  4 October 2017
This program will use assembly to traverse through a 3D array
*/

#include<iostream>

using namespace std;

int a[3][3][2] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18 };


void allShirts();  //  calculate the total of shirts
void mediumShirts();  //  calculate the total of medium shirts:  indexes 1,4,7,10,13,16
void shortSleeved();  //  calculate the total of short sleeved shirts:  indexes 3,4,5,9,10,11,15,16,17
void redShirts();  //  calculate the total of red shirts:  indexes 0,1,2,3,4,5



int main() {
	
	allShirts();
	mediumShirts();
	shortSleeved();
	redShirts();

	system("pause");
	return 0;
}

void allShirts() {
	int shirtTotal = 0;
	_asm {
			mov			ecx, 0							;  index
	ForLoop:  
			cmp			ecx, 18
			jge			done 
			mov			eax, [a+ecx*4]					;  multiply the index by 4 because integer
			add			shirtTotal, eax 
			inc			ecx 
			jmp			ForLoop

	Done:  
			
	}
	cout << "Total of shirts:  " << shirtTotal << endl;
}

void mediumShirts() {
	int mediumShirtsTotal = 0;
	_asm {
			mov			ecx, 1							;  index 
	ForLoop2:
			cmp			ecx, 17
			jge			done
			mov			eax, [a + ecx * 4]
			add			mediumShirtsTotal, eax
			add			ecx, 3							;  jump by 3s
			jmp			ForLoop2

			Done :
	}
	cout << "Total medium shirts:  " << mediumShirtsTotal << endl;

}

void shortSleeved() {
	int shortSleevedTotal = 0;
	_asm {
			mov			ecx, 3							;  secondary index to see when to jump 
			mov			ebx, 0							;  index
	ForLoop4:
			cmp			ecx, 18
			jge			done
	IncreaseIndex:  
			cmp			ebx, 3
			jge			BackToZero

			mov			eax, [a + ecx * 4]
			add			shortSleevedTotal, eax
			inc			ecx                               
			inc			ebx
			jmp			ForLoop4
	BackToZero:  
			mov			ebx, 0
			add			ecx, 3							;  add to primary index
			jmp			ForLoop4

	Done :
	}
	cout << "Total short sleeved shirts:  " << shortSleevedTotal << endl;
}

void redShirts() {
	int redShirtsTotal = 0;
	_asm {
			mov			ecx, 0							;  index
	ForLoop3:
			cmp			ecx, 6
			jge			done
			mov			eax, [a + ecx * 4]
			add			redShirtsTotal, eax
			inc			ecx
			jmp			ForLoop3

			Done :
	}
	cout << "Total red shirts:  " << redShirtsTotal << endl;
}