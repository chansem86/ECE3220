// L9_Ex2_CommandLine.c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int value;
	if(argc == 3){
		if((argv[1][0] == '-') && (argv[1][1] == 'n')) {
            value = atoi(argv[2]);
            printf("Int value: %d\n", value);
		}
		else
			printf("Wrong option: %s\n", argv[1]);
	}
	else {
		printf("Invalid number of input arguments: %d\n", argc);
		printf("\nUsage: %s -n IntValue\n\n", argv[0]);
	}

	return 0;
}