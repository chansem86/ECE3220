/*
 ============================================================================
 Name        : Lab2-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	int choice;
	unsigned short factorial = 0;
	unsigned long total = 0;
	unsigned int year = 0;
	float num1, num2;
	int num3, num4;
	float quotient;
	puts("\nPlease choose one of the following programs to run\n1. Factorial of a number\n2. Leap year or not?\n3. Maximum\n4. Division of two numbers\n"); /* prints menu */
	fflush(stdout);
	scanf("%d", &choice);
	switch (choice) {
	case 1:
		printf("Enter an number between 0 and 21:");
		fflush(stdout);
		scanf("%hu", &factorial);
		if (factorial > 20 || factorial < 1)
			printf("Error! Number is too large!");
		else {fflush(stdout);
			total = factorial;
			choice = factorial;
			while (factorial > 1) {
				factorial--;
				total *= factorial;
			}
			printf("The factorial of %d is %lu", choice, total);
		}
		break;
	case 2:
		printf("Enter an year greater than 0:");
		fflush(stdout);
		scanf("%d", &year);
		if (year < 1)
			printf("Error! Invalid choice");
		else {
			if ((year % 4) == 0)
				puts("It's a leap year!");
			else
				puts("It's not a leap year!");
		}
		break;
	case 3:
		printf("please enter first number:");
		fflush(stdout);
		scanf("%f", &num1);
		printf("please enter second number:");
		fflush(stdout);
		scanf("%f", &num2);
		(num1 < num2) ?
				printf("%f is greater than %f", num2, num1) :
				printf("%f is greater than %f", num1, num2);
		break;
	case 4:
		printf("please enter first number:");
		fflush(stdout);
		scanf("%d", &num3);
		printf("please enter second number:");
		fflush(stdout);
		scanf("%d", &num4);
		quotient = (float) num3 / num4;
		printf("%d/%d=%f", num3, num4, quotient);
		break;
	default:
		printf("Invalid entry. Goodbye.");
		break;
	}
	return EXIT_SUCCESS;
}
