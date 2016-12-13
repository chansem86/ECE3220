/*
 ============================================================================
 Name        : ExamExtraCredit10.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int x=2;

int f(void){
	int y=1;
	y=y+10;
	return x;
}

int g(void){
	static int x=3;
	x=x*10;
	return x;
}

int main(void) {
	printf("%d \n", f());
	printf("%d \n", g());
	printf("%d \n", g());
	return 0;
}
