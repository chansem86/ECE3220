/*
 ============================================================================
 Name        : Lecture7-4.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int a[10];
	int *arrayPtr = &a[0];

	*arrayPtr = 1;
	*++arrayPtr = 2;
	*++arrayPtr = 3;
	*(arrayPtr+2) = 5;

	printf("The value at location 0 is %d. \n", a[0]);
	printf("The value at location 1 is %d. \n", a[1]);
	printf("The value at location 2 is %d. \n", a[2]);
	printf("The value at location 3 is %d. \n", a[3]);
	printf("The value at location 4 is %d. \n\n", a[4]);

	a[3] = 4;
	arrayPtr = &a[0];
	printf("The value at a[3] is %d. \n", a[3]);
	printf("The value at *(arrayPtr+3) is %d. \n", *(arrayPtr+3));
	printf("The value at *(a+3) is %d. \n\n", *(a+3));

	printf("The address value of arrayPtr is %p.\n", arrayPtr);
	printf("The address value of a is %p.\n", a);
	printf("The address value of &a[0] is %p.\n\n", &a[0]);

	printf("The address value of a+9 is %p.\n", a+9);
	printf("The address value of &a[9] is %p.\n\n", &a[9]);

	printf("The address of location 1 in a is %p. \n", &a[0]);
	printf("The address at location 2 in a is %p. \n\n", &a[1]);

	double b[10];
	printf("The address of location 1 in b is %p. \n", &b[0]);
	printf("The address at location 2 in b is %p. \n\n", &b[1]);

	return 0;
}
