/*
 ============================================================================
 Name        : Lecture.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

//Ragged Arrays
int main(void) {
	int cnt, i;

	char *strArray[13] = {"Invalid Month", "January", "February", "March", "April",
						  "May", "June", "July", "August", "September", "October",
						  "November", "December"};
	for(cnt = 0; cnt <= 12; cnt++){
		printf("Counter cnt is: %d, Value of strArray[cnt]: %p. Value at strArray[cnt]: %s \n",
			   cnt, &strArray[cnt],  strArray[cnt]);
	}

	double **rArr;
	rArr = (double **)calloc(3, sizeof(double *));
	rArr[0] = (double *)malloc(1*sizeof(double));
	rArr[1] = (double *)malloc(2*sizeof(double));
	rArr[2] = (double *)malloc(3*sizeof(double));

	for(i = 0; i < 1; i++)
		rArr[0][i] = 0.5*i;
	for(i = 0; i < 2; i++)
		rArr[1][i] = 1.5*i;
	for(i = 0; i < 3; i++)
		rArr[2][i] = 2.5*i;

	printf("\nAddresses and Values:\n");
	printf("[0][0]: %p, %.1f\n", &rArr[0][0], rArr[0][0]);
	printf("[1][0]: %p, %.1f; [1][1]: %p, %.1f\n", &rArr[1][0], rArr[1][0], &rArr[1][1], rArr[1][1]);
	printf("[2][0]: %p, %.1f; [2][1]: %p, %.1f; [2][2]: %p, %.1f\n", &rArr[2][0], rArr[2][0], &rArr[2][1], rArr[2][1],
			&rArr[2][2], rArr[2][2]);

	for(i = 0; i < 3; i++)
		free(rArr[i]);

	free(rArr);

	return 0;
}
