/*-----------------------------------------------------
CPSC240
Created by:  Bui, Brian and Liao, Joey
Created on:  24 September 2017
Last edited:  26 September 2017
This program find if the PIN  is acceptable. The total must
be even when added up.
-----------------------------------------------------*/
#include <iostream>;
using namespace std;

short x, i = 0, result = 0;

short addUp(short PIN){
	_asm{
			mov ax, PIN
			mov x, 0x000F
			and x, ax
			mov cx, x 
			shr ax, 4
	repeat:
			inc i
			mov x, 0x000F
			and x, ax
			add cx, x
			shr ax, 4
			cmp i, 3
			Jne repeat
			Jmp done
	done:		
			mov result, cx
	}
	return result;
}

int main(){
	if(addUp(0xBEEF)%2==0){
		cout << "BEEF is a valid ID for the family." << endl;
	}else{
		cout << "BEEF is not a valid ID for the family." << endl;
	}
	if(addUp(0xFADE)%2==0){
		cout << "FADE is a valid ID for the family." << endl;
	}else{
		cout << "FADE is not a valid ID for the family." << endl;
	}
	if(addUp(0xCABE)%2==0){
		cout << "CABE is a valid ID for the family." << endl;
	}else{
		cout << "CABE is not a valid ID for the family." << endl;
	}

	system("Pause");
	return 0;
}

/*------------Output--------------------
BEEF is a valid ID for the family.
FADE is a valid ID for the family.
CABE is not a valid ID for the family.
Press any key to continue . . .
--------------------------------------*/