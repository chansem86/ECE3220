/*===============================================================
 Name        : Lab1-2.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Your copyright notice
 Description : Profif/Loss Calculator
===============================================================*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
	float cost = 0;
	float sell = 0;
	float profit = 0;
	printf ("Enter the cost price of your product:"); /* Asks user for price */
	fflush(stdout);
	scanf ("%f", &cost);
	printf ("Enter the selling price of your product:"); /* Asks user for cost */
	fflush(stdout);
	scanf ("%f", &sell);
	profit = sell - cost; /* Calculates difference */
	if(profit < 0){
		printf("You have incurred an loss of $%.2f",profit);
		fflush(stdout);
	} /* Case for loss */
	else if(profit > 0){
		printf("You have made a profit of $%.2f",profit);
		fflush(stdout);
	} /* Case for profit */
	else
		printf("You have neither made a profit or incurred loss."); /* Case for no net loss or profit */
	return EXIT_SUCCESS;
}
