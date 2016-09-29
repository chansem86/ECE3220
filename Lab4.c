/*
 ============================================================================
 Name        : Lab4-1.c
 Author      : Jonathan Davis and Chanse Meyer
 Version     :
 Copyright   : Your copyright notice
 Description : Lab 4
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//finds average of array
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
//finds max # in array
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
//function used to write to all the data files
void filewrite(double a[], int num, int quantity, double change) {
    int i = 0;
    if (num == 1) {
        char fIle[] = "Offset_data_nn.txt";
        FILE *file = fopen(fIle, "w");
        fprintf(file, "%d %.04f\n", quantity, change);
        while (i < quantity) {
            fprintf(file, "%.04f\n", a[i]);
            i++;
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
//offset function
void offset(int a[], int quantity) {
    double oFFset, b[quantity];
    int i = 0;
    fflush(stdin);
    printf("how much do you want to offset the signal?");
    fflush(stdout);
    scanf("%lf", &oFFset);
    while (i < quantity) {
        b[i] = a[i] + oFFset;
        i++;
    }
    filewrite(b, 1, quantity, oFFset);
}
//normalize function
void normal(int array[], int quantity, int max) {
    int i = 0;
    float array2[quantity], num = 0;
    while (i < quantity) {
        array2[i] = array[i];
        num = array2[i];
        i++;
    }
    i = 0;
    while (i < quantity) {
        array2[i] = array2[i] / max;
        num = array2[i];
        i++;
    }
    i = 0;
    FILE *File = fopen("Normalized_data_nn.txt", "w");
    fprintf(File, "%d %d\n", quantity, max);
    while (i < quantity) {
        fprintf(File, "%.04f\n", array2[i]);
        i++;
    }
}
//center function
void center(int array[], int quantity, int max) {
    int i = 0;
    double aveg;
    float array2[quantity];
    aveg = avg(array, quantity, max);
    while (i < quantity) {
        array2[i] = array[i] - aveg;
        i++;
    }
    i = 0;
    FILE *File = fopen("Centered_data_nn.txt", "w");
    fprintf(File, "%d %.04f\n", quantity, aveg);
    while (i < quantity) {
        fprintf(File, "%.04f\n", array2[i]);
        i++;
    }
}

int main(int argc, char** argv) {
    int choice, quantity, Max, num;
    int i = 0;
    char fIle[20] = {0};
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
    int array1[quantity], array2[quantity], array3[quantity], array4[quantity];
    ;
    while (!feof(filE)) {
        fscanf(filE, "%d\n", &num);
        //printf("%d", num);
        array1[i] = num;
        array2[i] = num;
        array3[i] = num;
        array4[i] = num;
        //printf("%d", array[i]);
        i++;
    }

    fclose(filE);
    center(array1, quantity, Max);
    normal(array2, quantity, Max);
    FILE *File = fopen("Statistics_data_nn.txt", "w");
    fprintf(File, "%.04f %d", avg(array3, quantity, Max), max(array4, quantity));
    fclose(File);
    int choice2;
    fflush(stdin);
    printf("Enter 1 to offset the chosen file or enter 2 to scale the chosen file:");
    fflush(stdout);
    scanf("%d", &choice2);
    switch (choice2) {
        case 1:
            offset(array4, quantity);
            break;
        case 2:
            scale(array4, quantity);
            break;
        default:
            printf("Error, invalid input");
            break;
    }

    return EXIT_SUCCESS;
}
