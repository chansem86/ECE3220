/*
 ============================================================================
 Name        : Lecture8-1.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//	multi-dimensional arrays
int main(void) {
	char mdArray[2][13] = {
			{ 97,  98,  99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109},
			{110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122}
	};

	int col, row;

	for (col=0; col<26; col++){
	   printf("val: %d   char: %c\n", mdArray[0][col], mdArray[0][col]);
	}

	int aR[10] = {10, 10, 10, 10, 10};
	int cnt;

	for(cnt = -5; cnt < 15; cnt++){
		printf("Counter cnt is: %d, Value of aR[cnt]: %p. Value at aR[cnt]: %d. \n", cnt, &aR[cnt],  aR[cnt]);
	}

	return 0;
}
