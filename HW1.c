/*
 ============================================================================
 Name        : HW1.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	int number, choice, count;
	double out;	/*define variables*/
	printf ("\nPlease enter a number between 2 and 10!\n"); /* prints command*/
	fflush (stdout);
	scanf ("%d", &number);	/*scan for input*/
	if (number<=1||number>>9) /*error check*/
	{
		printf ("\nInvalid Entry! Please enter a number between 2 and 10!\n"); /* prints command again*/
		fflush (stdout);
		scanf ("%d", &number);	/*scan for input*/
		if (number<=1||number>>9) /*error check again*/
		{
			printf ("\nToo many incorrect inputs. Goodbye!\n");
			fflush (stdout);
			return 0;
		}
	}
	printf("\nWould you like the first 10 multiples or the first 6 exponential powers of %d?\n Please enter 1 for multiples or 2 for powers. ", number);
	fflush (stdout);
	scanf ("%d", &choice);	/*scan for input*/
	if (choice<=0||choice>>2) /*error check*/
	{
		printf ("\nInvalid Entry! Please enter 1 for multiples or 2 for powers. \n"); /* prints command again*/
		fflush (stdout);
		scanf ("%d", &choice);	/*scan for input*/
		if (choice<=0||choice>>2) /*error check again*/
		{
			printf ("\nToo many incorrect inputs. Goodbye!\n");
			fflush (stdout);
			return 0;
		}
	}
	count=0;
	if (choice==1) /*if they choose multiples*/
	{
		printf ("\nFirst 10 multiples of %d are:", number);
		fflush (stdout);
		while (count<10)	/*loop to execute 10 times*/
		{
			count++;
			out=number*count;
			printf (" %d ", (int) out);
			fflush (stdout);
		}
	}
	if (choice==2)	/*if they choose powers*/
	{
		printf ("\nFirst 6 powers of %d are:", number);
		fflush (stdout);
		while (count<6)	/*loop to execute 6 times*/
		{
			count++;
			out=pow((double)number, (double)count);
			printf (" %d ", (int) out);
			fflush (stdout);
		}
	}
	printf ("\nThanks for Playing!!!\n");
	fflush (stdout);
	return 0;
}
