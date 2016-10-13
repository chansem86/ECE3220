#include<stdio.h>
int main()
{
	int x=1309;
	int *p = NULL;
	printf("\n The value of x is = %d",x);
	printf("\n The pointer points to the value = %p",&*p); //dereferenced pointer to print value instead of address
	return 1;
}
