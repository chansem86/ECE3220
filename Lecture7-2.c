/*
 ============================================================================
 Name        : Lecture7-2.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void inc(int x){
	x++;
}

void incP(int *x){
	(*x)++;
}

int *retP(void){
	int *newPtr = (int *)malloc(sizeof(int));
	*newPtr = 10;
	return(newPtr);
}

int main(void) {
	int x = 1;
	int *xPtr = &x;  // xPtr points to x

	inc(x);
	printf("1. The value of x is now %d.\n", x);

	incP(xPtr);
	printf("2. The value of *xPtr is now %d.\n", *xPtr);
	printf("3. The value of x is now %d.\n", x);

	printf("4. The value of xPtr (address) is %p.\n", xPtr);
	xPtr = retP();  // does xPtr still point to x after this?
	printf("5. The value of xPtr (address) is now %p.\n", xPtr);
	printf("6. The value of *xPtr is now %d.\n", *xPtr);
	printf("7. The value of x is now %d.\n", x);

	return 0;
}
