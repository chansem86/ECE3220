/* L3_Ex1_Operators.c
Original created by: Alina Zare
Modified by: Luis Rivera
*/

#include <stdio.h>
#include <limits.h>

int main(void)
{
	unsigned int x; 
	int z = 0;
	
	x = 1;
	printf("\nUnary ! operator: x: %d (%X) and !x: %i (%X).\n", x, x, !x, !x);
	printf("Unary ! operator: x+1: %d (%X) and !(x+1): %i (%X).\n", x+1, x+1, !(x+1), !(x+1));
	
	x = 0;
	printf("Unary ! operator: x: %d (%X) and !x: %i (%X).\n", x, x, !x, !x);
	
	x = UINT_MAX;
	printf("Unary ~ operator: x: %u (%X) and ~x: %u (%X).\n", x, x, ~x, ~x);

	x = 0xFFFFFFFE;
	printf("Unary ~ operator: x: %u (%X) and ~x: %u (%X).\n",x, x, ~x, ~x);

	z = 10;
	printf("Unary - operator: z: %d and -z: %d.\n\n",z, -z);

	x = 1;
	printf("Unary ++ prefix operator: x:  %d.\n", x);
	printf("\t \t \t ++x: %d.\n\n", ++x);
	printf("Unary ++ postfix operator: x: %d.\n", x);
	printf("\t \t \t x++: %d.\n", x++);
	printf("\t \t \t x++: %d.\n\n", x++);
	
	return 0;
}