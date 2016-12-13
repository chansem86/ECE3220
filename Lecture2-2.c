/* L2_Ex2_float.c
Original created by: Alina Zare
Modified by: Luis Rivera
*/

#include <stdio.h>

int main(void)
{
    int val, sgn, exp, frac;
    float floatNum;
    int *intNum;
    unsigned char *cNum;
    
    floatNum = 0.15625;
    intNum = &floatNum;
    cNum = &floatNum;
    val = *(int*)(&floatNum);
    
    printf("\nThe float value is: %f. \n", floatNum);
    printf("\nThe int value is: %d. \n", *intNum);
    
    printf("\nIn hexadecimal: %02X %02X %02X %02X \n",  *(cNum+3), *(cNum+2), *(cNum+1), *cNum); //intel machine -> little endian
    
    sgn = (val>>31)&0x01;
    exp = (val>>23)&0x00FF;
    frac = (val)&((0x01<<24) -1);
    
    printf("\nsign: %x, exponent: %X, fraction: %x\n", sgn, exp, frac);
	
	return 0;
}