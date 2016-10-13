#include <stdio.h>

int factorial ( int num )
{
    if(num>0)
    	return num * factorial( num - 1 );
    else
	return 1;//needed this else case so the recursion wouldn't be infinite and would just stop at 1

}

int main(void)
{
    int no,ans;
    printf("Enter the number \n");
    scanf( "%d", &no );
    ans = factorial( no );
    printf("The factorial is %d ", ans );
    return 0;
}
