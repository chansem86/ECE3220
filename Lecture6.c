/*
 ============================================================================
 Name        : Lecture6.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Memory Allocation
 ============================================================================
 */

#include <stdio.h>
int x = 0;

int f(void){
	int x = 10;
	x = x + 10;
	return x;
}

int g(void){
	static int x = 10;
	x = x + 10;
	return x;
}

double h(double y){
	y += (double)(++x);
	return y;
}

int main(void){
	printf("%04d \n", f());
    printf("%04d \n", g());
	printf("%.2f \n", h(2.5));
	printf("%04d \n", f());
	printf("%04d \n", g());
	printf("%.2f \n", h(2.5));
	return 0;
}
