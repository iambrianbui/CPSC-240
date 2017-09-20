/*
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  19 September 2017
Last edited:  19 September 2017
This program will allow user to practice addition and subtraction
It uses assembly to calculate and compare the user's input to the answer
calculated by the program. User can continue or finish based on input.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

int answer, correctCount = 0, wrongCount = 0, num1, num2;
char choice, continueYesNo, doneYesNo;

void askPractice() {
	cout << "   Enter your choice(a/b): ";
	cin >> choice;
}

void askContinue() {
	cout << "     Continue(y/n)?: ";
	cin >> continueYesNo;
}

void askDone() {
	cout << "  Are you done(y/n)?: ";
	cin >> doneYesNo;
}

void userAnswer() {
	cin >> answer;
}

void isCorrect() {
	cout << "     CORRECT\n";
}

void isWrong() {
	cout << "     WRONG\n";
}

void addEquation() {
	num1 = rand()%99+1;
	num2 = rand()%99+1;
	cout << "    " << num1 << " + " << num2 << " ? ";

	_asm {
		mov		 eax, num1      
		add		 eax, num2
		call	 userAnswer
		cmp		 eax, answer
		Je		 correct
		Jmp		 wrong
	correct:	
		inc		 correctCount
		call	 isCorrect
	wrong:
		inc		 wrongCount
		call	 isWrong
	}
}

void minusEquation() {
	num1 = rand()%99+1;
	num2 = rand()%99+1;
	cout << "    " << num1 << " - " << num2 << " ? ";
	_asm {
		mov		 eax, num1
		sub		 eax, num2
		call	 userAnswer
		cmp		 answer, eax
		Je		 correct
		Jmp		 wrong
	correct:
		inc		 correctCount
		call	 isCorrect
	wrong:
		inc		 wrongCount
		call	 isWrong
	}

}

void showCount() {
	cout << "    No. of CORRECT answers = " << correctCount << endl;
	cout << "    No. of WRONG answers = " << wrongCount << endl;
}

void goodbye() {
	cout << "    Have a nice day!\n";
}

int main() {
	cout << "------Practice Addition & Subtraction------\n";
	cout << "a. Practice Addition\n";
	cout << "b. Practice Subtraction\n";

	_asm {
	beginning:
		call	askPractice
		cmp		choice, 'a'
		Je		addition
		cmp		choice, 'b'
		Je		subtraction
	addition :
		call	 addEquation
		call	 askContinue
		cmp		 continueYesNo, 'Y'  ;go back to addition when continuing, not case sensitive
		Je		 addition
		cmp		 continueYesNo, 'y'
		Je		 addition
		cmp		 continueYesNo, 'N'  ;go to isDone to see if want to finish, not case sensitive
		Je		 isDone
		cmp		 continueYesNo, 'n'
		Je		 isDone
	subtraction :
		call	 minusEquation
		call	 askContinue
		cmp		 continueYesNo, 'Y'  ;go back to subtraction when continuing, not case sensitive
		Je		 subtraction
		cmp		 continueYesNo, 'y'
		Je		 subtraction
		cmp		 continueYesNo, 'N'  ;go to isDone to see if want to finish, not case sensitive
		Je		 isDone
		cmp		 continueYesNo, 'n'
		Je		 isDone

	isDone:	
		call	 showCount			 ;shows how many correct and wrong answers
		mov		 correctCount, 0	 ;reset correctCount in case user wants to continue
		mov		 wrongCount, 0		 ;reset wrongCount in case user wants to continue
		call	 askDone
		cmp		 doneYesNo, 'Y'		 ;go to ending and end program, not case sensitive 
		Je		 ending
		cmp		 doneYesNo, 'y'
		Je		 ending
		cmp		 doneYesNo, 'N'		 ;go back to beginning to practice more, not case sensitive
		Je		 beginning
		cmp		 doneYesNo, 'n'
		Je		 beginning

	ending:
		call	goodbye
	}

	system("pause");
	return 0;
}

/*------------------------------------------
Output:
------Practice Addition & Subtraction------
a. Practice Addition
b. Practice Subtraction
   Enter your choice(a/b): a
    42 + 54 ? 55
     WRONG
     Continue(y/n)?: y
    98 + 68 ? 75
     WRONG
     Continue(y/n)?: N
    No. of CORRECT answers = 0
    No. of WRONG answers = 2
  Are you done(y/n)?: n
   Enter your choice(a/b): b
    63 - 83 ? 12
     WRONG
     Continue(y/n)?: y
    94 - 55 ? 29
     WRONG
     Continue(y/n)?: n
    No. of CORRECT answers = 0
    No. of WRONG answers = 2
  Are you done(y/n)?: Y
    Have a nice day!
Press any key to continue . . .
------------------------------------------*/
