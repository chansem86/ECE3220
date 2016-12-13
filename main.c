/*
 ============================================================================
 Name        : Lab4-1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

double avg(int a[], int quantity, int max) {
	int total = 0, i = 0;
	double average;
	while (i < quantity) {
		total += a[i];
		i++;
	}
	average = (double) total / quantity;
	return average;
}

int max(int a[], int length) {
	int Max = 0;
	int i = 0;
	while (i < length) {
		if (a[i] > Max)
			Max = a[i];
		i++;
	}
	return Max;
}

void filewrite(double a[], int num, int quantity, double change) {
	int i = 0;
	if (num == 1) {
            i = 1;
		char fIle[] = "Offset_data_nn.txt";
		FILE *file = fopen(fIle, "w");
		fprintf(file, "%d %.04f\n", quantity, change);
		while (i <= quantity) {
			fprintf(file, "%.04f\n", a[i++]);
		}
		if (file == NULL) {
			printf("Error! File couldn't be open!");
			exit(0);
		}
		fclose(file);
	}
	if (num == 2) {
		char fIle[] = "Scaled_data_nn.txt";
		FILE *file = fopen(fIle, "w");
		fprintf(file, "%d %.04f\n", quantity, change);
		while (i < quantity) {
			fprintf(file, "%.04f\n", a[i++]);
		}
		if (file == NULL) {
			printf("Error! File couldn't be open!");
			exit(0);
		}
		fclose(file);
	}
}

void scale(int a[], int length) {
	double scaler, b[length];
	int i = 0;
	printf("What would you like the scaler to be?: ");
	fflush(stdout);
	scanf("%lf", &scaler);
	while (i < length) {
		b[i] = a[i] * scaler;
		i++;
	}
	filewrite(b, 2, length, scaler);
}

void offset(int a[], int quantity) {
	double oFFset, b[quantity];
	int i = 0;
	printf("how much do you want to offset the signal?");
	fflush(stdout);
	scanf("%lf", &oFFset);
	while (i <= quantity) {
		b[i] = a[i++] + oFFset;
                printf("%f",b[i-1]);
	}
	filewrite(b, 1, quantity, oFFset);
}

void normal(FILE *file) {
	int quantity, num, max, i = 0;
	fscanf(file, "%d %d", &quantity, &max);
	int array[quantity];
	while (!feof(file)) {
		fscanf(file, "%d\n", &num);
		array[i] = num;
		i++;
	}
	FILE *File = fopen("Normalized_data_nn.txt", "w");
	fclose(file);
	i = 0;
	while (i < quantity)
	{
		array[i] = array[i++]/max;
	}
	i = 0;
	fprintf(File, "%d %d\n", quantity, max);
	while (i < quantity){
		fprintf(File, "%.04f\n", array[i]);
	}
}

void center(FILE *file)
{
	int quantity, num, max, i = 0;
		fscanf(file, "%d %d", &quantity, &max);
		int array[quantity];
		while (!feof(file)) {
			fscanf(file, "%d\n", &num);
			array[i] = num;
			i++;
		}
		fclose(file);
		FILE *File = fopen("Centered_data_nn.txt", "w");
		i = 0;
		while (i < quantity)
		{
			array[i] = array[i++] - avg(array,quantity,max);
		}
		i = 0;
		fprintf(File, "%d -%.04f\n", quantity, avg(array,quantity,max));
		while (i < quantity){
			fprintf(File, "%.04f\n", array[i]);
		}
}

int main(int argc, char** argv) {
	int choice, quantity, Max, num;
	int i = 0;
	char fIle[20] = { 0 };
	puts("Choose a number between 0 and 12:");
	fflush(stdout);
	scanf("%d", &choice);
	sprintf(fIle, "Raw_data_%d.txt", choice);
	FILE *filE = fopen(fIle, "r");
	if (filE == NULL) {
		exit(0);
	}
	fscanf(filE, "%d %d", &quantity, &Max);
	//printf("%d %d", quantity, max);
	int array[quantity];
	while (!feof(filE)) {
		fscanf(filE, "%d\n", &num);
		//printf("%d", num);
		array[i] = num;
		//printf("%d", array[i]);
		i++;
	}
	FILE *File = fopen("Statistics_data_nn.txt", "w");
	fprintf(File, "%f %d", avg(array, quantity, Max), max(array,quantity));
	fclose(File);
	//center(filE);
	//normal(filE);
	fclose(filE);
	int choice2;
	printf("Enter 1 to offset the chosen file or enter 2 to scale the chosen file:");
	fflush(stdout);
	//fflush(stdin);
	scanf("%d",&choice2);
	switch(choice2){
	case 1:
		offset(array, quantity);
		break;
	case 2:
		scale(array, quantity);
		break;
	default:
		printf("Error, invalid input");
		break;
	}

	return EXIT_SUCCESS;
}
