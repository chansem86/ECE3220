/*
 ============================================================================
 Name        : Lecture7-3.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int x = 1;
	int *xPtr = &x;  // xPtr points to x

	printf("The memory address of x and the value of xPtr is %p.\n", xPtr);
	xPtr++;
	printf("After xPtr++: The  value of xPtr is %p.\n\n", xPtr);

	double *xPtrd = (double *)&x;	// without the cast, you get a warning
	printf("The memory address of x and the value of xPtrd is %p.\n", xPtrd);
	xPtrd++;
	printf("After xPtrd++: The value of xPtrd is %p.\n\n", xPtrd);

	char *xPtrc = (char *)&x;	// without the cast, you get a warning
	printf("The memory address of x and the value of xPtrc is %p.\n", xPtrc);
	xPtrc++;
	printf("After xPtrc++: The value of xPtrc is %p.\n\n", xPtrc);

	return 0;
}
