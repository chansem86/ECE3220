/*
 ============================================================================
 Name        : Lecture8-2.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

//Ragged Arrays
int main(void) {
	int x, y, z;
	char a, b, c;
	char s[10] = "ECE 3220";
	x = 10;
	y = 20;
	z = 30;
	a = 1;
	b = 2;
	c = 3;

	void *ptrArray[10];

	ptrArray[0] = &x;
	ptrArray[1] = &y;
	ptrArray[2] = &z;
	ptrArray[3] = &a;
	ptrArray[4] = &b;
	ptrArray[5] = &s[0];
	ptrArray[6] = &c;

	printf("Value of ptrArray[0]: %p. Value at location: %d.\n", ptrArray[0], *(int *)ptrArray[0]);
	printf("Value of ptrArray[1]: %p. Value at location: %d.\n", ptrArray[1], *(int *)ptrArray[1]);
	printf("Value of ptrArray[2]: %p. Value at location: %d.\n", ptrArray[2], *(int *)ptrArray[2]);
	printf("Value of ptrArray[3]: %p. Value at location: %d.\n", ptrArray[3], *(char *)ptrArray[3]);
	printf("Value of ptrArray[4]: %p. Value at location: %d.\n", ptrArray[4], *(char *)ptrArray[4]);
	printf("Value of ptrArray[5]: %p. Value at location: %s.\n", ptrArray[5], (char *)ptrArray[5]);
	printf("Value of ptrArray[6]: %p. Value at location: %d.\n", ptrArray[6], *(char *)ptrArray[6]);

	return 0;
}
