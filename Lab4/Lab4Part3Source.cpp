#include <iostream>
#include <stdlib.h>
using namespace std;

char c;
int num;

void askPractice() {
	cout << "Practice Addition\n";
	cout << "Practice Subtraction\n";
	cout << "\tEnter your choice(a/b): ";
	cin.get(c);
}

void rng() {
	int num = rand() % 99 + 1;
}

void practiceAdd() {
	_asm {
		call rng
		mov eax, num
		call rng
		mov ebx, num
		sub eax, eba
		mov ecx, eax ; ecx = answer
	}
}

void practiceSub() {
	_asm {
			call rng
			mov eax, num
			call rng
			mov ebx, num
			add eax, eba
			mov ecx, eax ;ecx = answer

	}
}

void askContinue() {
	cout << "Continue(y/n)?: ";
	cin.get(c);
}

void askDone() {
	cout << "Are you done(y/n)?: ";
	cin.get(c);
}

int main() {
	_asm {
		call askPractice
		cmp  c, 'a'
		Je	 practiceA
		cmp  c, 'b'
		Je	 practiceB
	practiceA:
		call practiceAdd
		call askPractice
		cmp c, 'y'
		Je practiceA
		cmp c, 'Y'
		Je practiceA
		cmp c, 'n'
		cmp c, 'N'
		
	practiceB:
		call practiceSub
		call askPractice
		cmp c, 'y'
		Je practiceB
		cmp c, 'Y'
		Je practiceB
		cmp c, 'n'
		cmp c, 'N' 
	}
	return 0;
}