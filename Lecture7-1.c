/*
 ============================================================================
 Name        : Lecture.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Pointers
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int x = 1, y = 2;
	int *xPtr;  //int pointer
	xPtr = &x;  //xPtr points to x
	printf("1. The memory address of x is %p\n", &x);
	printf("2. The value of xPtr is %p.\n", xPtr);

	y = *xPtr; //y is assigned the value in the address of xPtr
	printf("3. The value of y is now %d.\n", y);

	y = *xPtr + 1;
	printf("4. The value of y is now %d.\n", y);

	*xPtr = 0; //the address xPtr points to is assigned the value 0
	printf("5. The value of x is now %d.\n", x);
	printf("6. The value of y is now %d.\n", y);

	return 0;
}
