/*
 ============================================================================
 Name        : ExamExtraCredit11.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int rows=8;
	int *array;
	int r, c;

	array=malloc(rows*sizeof(int));

	int x[8][5];

	for(r=0; r<rows; r++){
		static int val=10;
		static int val2=1;
		array[r]=val++;
		printf ("\n                   array(%d) = %d\n", r, array[r]);
		for(c=0; c<5; c++){
			x[r][c]=val2++;
			printf ("%d  ", x[r][c]);
		}
	}
	return 0;
}
