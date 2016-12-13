/*
 ============================================================================
 Name        : Lecture7-5.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	FILE *fp_r, *fp_w;
	int i, datain[5]; // fixed size.
					  // What if the size is not known beforehand?

	fp_r = fopen("L7_f1.txt","r");  // open for reading
	if(fp_r == NULL)
		perror("Error opening file");
	else {
		for(i = 0; i < 5; i++)
			fscanf(fp_r, "%d", datain+i); // same: &datain[i]
	}
	fclose(fp_r);

	fp_w = fopen("L7_f2.txt","w"); // the name could be created using sprintf
	if(fp_w == NULL)
		perror("Error opening file");
	else {
		for(i = 0; i < 5; i++)
			fprintf(fp_w, "Data %d:\t%d,\t%f,\t%X\n",
					i, datain[i], 1.0*datain[i], datain[i]);
	}
	fclose(fp_w);

	printf("Done!\n");

	return 0;
}

