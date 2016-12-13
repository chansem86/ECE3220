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

int max (int a[], length){
	int Max=0;
	int i=0;
	while (i<length)

}
double avg(int a[], int quantity, int max){
	int total = 0, i = 0;
	double average;
	while(i<quantity){
		total += a[i];
		i++;
	}
	average = (double) total/quantity;
	return average;
	/*FILE *file = fopen("Statistics_data_nn.txt", "w");
	fprintf(file, "%f %d", average, max);
	fclose(file);*/
}
void filewrite (int a[], int num){
	if (num==1)
		FILE *file = fopen("Offset_data_nn.txt", "w");
	if (num==2)
		FILE *file = fopen("Scaled_data_nn.txt", "w");
	fprintf();
}
void offset(int a[], int quantity){
	double oFFset, b[quantity];
	int i = 0;
	printf("how much do you want to offset the signal?");
	fflush(stdout);
	scanf("%f",&oFFset);
	while(i<quantity)
	{
		b[i] = a[i] - oFFset;
	}
	FILE *file = fopen("Offset_data_nn.txt", "w");


}

int main(int argc, char** argv) {
	int choice, quantity, max, num;
	int i;
	char fIle[20] = {0};
	puts("Choose a number between 0 and 12:");
	scanf("%d", &choice);
	sprintf(fIle, "Raw_data_%d.txt", choice);
	i = 0;
	FILE *file = fopen(fIle, "r");
	if (file == NULL) {
		exit(0);
	}
	fscanf(file, "%d %d", &quantity, &max);
	printf("%d %d", quantity, max);
	int array[quantity];
	while (!feof(file)) {
		fscanf(file, "%d\n", &num);
		array[i] = num;
		i++;
	}
	fclose(file);
	return EXIT_SUCCESS;
}
