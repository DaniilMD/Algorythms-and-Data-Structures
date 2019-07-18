#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>

#include "HW2.h"
#include "HW3.h"
#include "HW4.h"
#include "HW5.h"


int main () {
	//Test 1 task
	char Bin[100];
	int count = DecToBinStack(1023, Bin);
	for (int i = 0; i < count; i++ ) {
		printf("%c ", Bin[i]);
	}



	//Test 2 task
	char Brackets[40];
	strcpy(Brackets,"[{)}]");
	printf("\n%d\n", CheckBr(6, Brackets));


	//Test 3 task


	//Test 4 task

	DQueue dq;
	dq.size = 0;
	dq.head = NULL;



	pushhead(&dq, 'a');
	pushhead(&dq, 'b');
	pushhead(&dq, 'c');
	pushhead(&dq, 'd');
	pushhead(&dq, 'e');

	pushtail(&dq, '1');
	pushtail(&dq, '2');
	pushtail(&dq, '3');
	pushtail(&dq, '4');
	pushtail(&dq, '5');

	int s = dq.size;
	for (int i = 0; i < s / 2; i++) {
		printf("%c ", popDQhead(&dq));
		printf("%c ", popDQtail(&dq));
	}

}
