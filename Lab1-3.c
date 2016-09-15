/*
 ===============================================================
 Name        : Lab1-3.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Your copyright notice
 Description : Simple Operation Program
===============================================================*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	float Operand1 = 0;
	float Operand2 = 0;
	char operator;
	char enter;
	float answer;
	puts("Enter operand 1 (This should be an numerical value):"); /* asks user to input first # */
	fflush(stdout);
	scanf("%f",&Operand1);
	printf("Enter operator (This should be +, -, *, /):"); /* asks user to input operator */

	fflush(stdout);
	enter = getchar();
	operator = getchar();
	puts("Enter operand 2 (This should be an numerical value):"); /* asks user to input second # */

	fflush(stdout);
	scanf("%f",&Operand2);
	switch (operator){
	case '+':
		answer = Operand1+Operand2;
		break;
	case '-':
		answer = Operand1-Operand2;
		break;
	case '*':
		answer = Operand1*Operand2;
		break;
	case '/':
		if(Operand2 != 0)
			answer = Operand1/Operand2;
		else{
			printf("Error! Division by zero.");
			exit(0);
		}
		break;
	default:
		printf ("Error! Operator invalid!");
		exit(0);
		break;
	}
	printf ("%f %c %f = %f", Operand1, operator, Operand2, answer);
	return EXIT_SUCCESS;
}
