/*
 ============================================================================
 Name        : HW3.c
 Author      : Chanse Meyer
 Version     :
 Copyright   : Property of Chanse Meyer. Do Not Copy.
 Description : In Class Assignment 3
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void printerror(void)
{
	printf ("Invalid command line arguments. Should be: \n'./MyProgram' '-f' 'filename' '-w' 'line 1 text' 'line 2 text' 'etc...'\nOR\n'./MyProgram' '-f' 'filename' '-r'");
	return;
}

void filewrite(int argc, char *argv)
{
	int i=4;
	FILE *file = fopen(argv[2], "w");
	for (i<argc){
		fputs(argv[i], file);
		i++;
	}
	fclose(file);
	return;
}

void fileread( int argc, char *argv)
{
	char string[100];
	FILE *file = fopen(argv[2], "r");
	if(file == NULL)
	{
		printf("Error opening file");
		return;
	}
	while( fgets (string, 100, file)!=NULL )
	{
		puts(string);
	}
	fclose(file);
	return;
}

int main(int argc, char *argv[])
{
	printf ("# of arguments is %d\n\n", argc);
	if (argc<=4)
	{
		printerror();
	}
	else if((argv[1][0] != '-') || (argv[1][1] != 'f') || (argv[3][0] != '-') || ((argv[3][1] != 'w')&&(argv[3][1] != 'r')))
	{
		printerror();
	}
	else if (argv[3][1] == 'w')
	{
		filewrite(argc, *argv);
	}
	else if (argv[3][1] == 'r')
	{
		fileread(argc, *argv);
	}
	else
	{
		printerror();
	}
	return 0;
}
