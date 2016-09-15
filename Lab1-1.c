/*
============================================================================
 Name        : Lab1-1.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Your copyright notice
 Description : Area of Circle
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.14

int main(void) {
	float radius = 0;
	float area;
	printf("Enter the radius of your circle:"); /*Ask user for radius */
	fflush(stdout);
	scanf("%f",&radius);
	area = PI*radius*radius; /* Calculates area */
	printf ("The area of the circle is %.2f", area);
	printf ("The new area of the circle is %.2f", area);

	return EXIT_SUCCESS;
}
