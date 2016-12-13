/* L2_Ex1_Types.c
Original created by: Alina Zare
Modified by: Luis Rivera
*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>

int main()
{
    printf("\nChars have the range: %d to %d.\n", CHAR_MIN, CHAR_MAX);
    printf("\nUnsigned chars have the range: 0 to %d.\n", UCHAR_MAX);
    printf("\nShorts have the range: %d to %d.\n", SHRT_MIN, SHRT_MAX);
    printf("\nUnsigned shorts have the range: 0 to %u.\n", USHRT_MAX);
    printf("\nInts have the range: %d to %d.\n", INT_MIN, INT_MAX);
    printf("\nUnsigned ints have the range: 0 to %u.\n", UINT_MAX);
    printf("\nLongs have the range: %lld to %lld.\n", LLONG_MAX, LLONG_MAX);
    printf("\nUnsigned longs have the range: 0 to %llu.\n", ULLONG_MAX);
    printf("\nThe smallest non-zero float value is %.3e.\n", FLT_MIN);
    printf("\nThe smallest non-zero double value is %.3e.\n", DBL_MIN);
    printf("\nThe largest double value is %.5e.\n\n", DBL_MAX);

    signed char c = CHAR_MAX+1;
    signed char d = CHAR_MIN-1;
    printf("\nToo small char value: %d.  A too large char value is %d.\n\n", d, c);

    const signed char charValue1 = 65;
    printf("\nThe character is %c.\n", charValue1);
    printf("\nThe character is %d.\n", charValue1);

    signed char charValue2 = 97;
    printf("\nThe character is %c.\n", charValue2);
    printf("\nThe character is %d.\n", charValue2);

    int i = 256;
    signed char k = i;
    printf("\nValue of i: %i.  Value of i: %c.  Value of k: %d.\n", i, k, k);
    
    i = 3.14;
    double pi = i;
    printf("\nValue of pi: %f. \n", pi);
    
    pi = 3.14;
    printf("\nValue of pi: %f. \n", pi);
	
	return 0;
}