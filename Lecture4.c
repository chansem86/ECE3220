/* L4_Ex1_Preprocessor.c
created by: Luis Rivera
*/

#include <stdio.h>
#define PRINTF 0

int main(void)
{
	char a;
	printf("\nAlways to be printed. Type a letter to continue.\n");
	fflush(stdout);
	scanf("%c", &a);

#if PRINTF > 0
	printf("\nPrinted if PRINTF > 0\n");
#endif

#if PRINTF > 1
	printf("\nPrinted if PRINTF > 1\n");
#endif
	
	return 0;
}