/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  3 October 2017
Last edited:  3 October 2017
This program will use assembly count what is wanted:
total number of all shirts, toital number of large shirts,
and total number of black shirts.
*/

#include <iostream>
using namespace std;

int shirtNum, largeNum, blackNum;
int arr[4][4] = {10,20,30,40,20,10,40,30,5,15,20,25,30,25,20,15};

void totalShirts(){
	_asm{
			mov shirtNum, 0	
			mov ecx, 0								;ecx = i
	ForLoop:
			cmp ecx , 16							;for(i = 0; i != 16; i++)
			Je done
			mov eax, [arr+ecx*4]					;traverse all the index
			add shirtNum, eax
			inc ecx
			Jmp ForLoop
	done:

	}
}

void totalLarge(){
	_asm{
			mov largeNum, 0
			mov ebx, 8								;start of Large column
			mov ecx, 0
	ForLoop2:
			cmp ecx, 16							    ;for(i = 0; i != 16; i++)
			Je done2
			mov eax, [arr+ebx]						;only traverse down a column, starting from Large column
			add largeNum, eax
			inc ecx
			add ebx, 16								;inc ebx by 16 to go down
			Jmp ForLoop2
	done2:
	}
}

void totalBlack(){
	_asm{
			mov blackNum, 0
			mov ebx, 48								;start of Black row
			mov ecx, 0
	ForLoop3:
			cmp ecx, 16								;for(i = 0; i != 16; i++)
			Je done3
			mov eax, [arr+ebx]						;only traverse across a row, starting from Black row
			add blackNum, eax
			add ebx, 4								;inc ebx by 4 to go across
			inc ecx
			Jmp ForLoop3
	done3:
	}
}

int main(){
	totalShirts();
	totalLarge();
	totalBlack();
	cout << "Total number of all shirts: " << shirtNum << endl;
	cout << "Total number of large shirts: " << largeNum << endl;
	cout << "Total number of black shirts: " << blackNum << endl;
	system("pause");
	return 0;
}