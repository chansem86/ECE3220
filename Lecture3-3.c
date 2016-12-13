/* L3_Ex3_Operators.c
Original created by: Alina Zare
Modified by: Luis Rivera
*/

#include <stdio.h>
#include <limits.h>
#define XVAL 0x0F	// 0x01, 0x0F
#define ZVAL 0xF0	// 0x02, 0xF0
#define min(a,b) (a > b) ? b : a;

int main(void) 
{
	int x = XVAL, z = ZVAL, y; 
	
	y = z + 1 & x + 1;
	printf("\nx is: %d (%X), z is: %d (%X), z + 1 & x + 1 is: \t\t%d (%X)\n", x, x, z, z, y, y);
	y = z + 1 & x + 1 | x << 2;
	printf("x is: %d (%X), z is: %d (%X), z + 1 & x + 1 | x << 2 is: \t%d (%X)\n", x, x, z, z, y, y);
	y = (z + 1 & x + 1) | x << 2;
	printf("x is: %d (%X), z is: %d (%X), (z + 1 & x + 1) | x << 2 is: \t%d (%X)\n", x, x, z, z, y, y);
	y = z + 1 & (x + 1 | x << 2);
	printf("x is: %d (%X), z is: %d (%X), z + 1 & (x + 1 | x << 2) is: \t%d (%X)\n", x, x, z, z, y, y);
	y = z + 1 & x + 1 | x && z;
	printf("x is: %d (%X), z is: %d (%X), z + 1 & x + 1 | x && z is: \t%d (%X)\n\n", x, x, z, z, y, y);
	
	float r = min(3, 4.0);
	printf("min(3,4) is %f\n\n", r);

	y = 2;
	z = min(++y,y);
	printf("%d\n", z);
	z = min(y++,y);
	printf("%d\n", z);
	z = min(y,y++);
	printf("%d\n", z);
	z = min(++y,y++);
	printf("%d\n", z);

	return 0;
}