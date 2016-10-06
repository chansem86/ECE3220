/*
 ============================================================================
 Name        : Lab5.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Signals
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

double avg(int a[], int quantity) {
    int total = 0, i = 2; //initialize variables
    double average;
    while (i < quantity + 2) { //Sum up all the numbers in the array
        total += a[i];
        i++;
    }
    average = (double) total / quantity; //Find the average of the sum
    return average; //return average
}

int max(int a[], int length) {
    int Max = 0; //initialize variables
    int i = 2;
    while (i < length + 2) { //Find the max in the array
        if (a[i] > Max)
            Max = a[i];
        i++;
    }
    return Max; //Return the Max
}

void filewrite(double a[], int num, int quantity, double change, int filenum, bool visited, char new[]) {
    int i = 2; //initialize 'i'
    char File[50] = {0};
    if (num == 1) {
        if (visited == true) {
            sprintf(File, "%s_Offset_%d.txt", new, filenum);
        } else
            sprintf(File, "Offset_data_%d.txt", filenum);
        FILE *file = fopen(File, "w"); //Open file and write data to file
        fprintf(file, "%d %.04f\n", quantity, change);
        while (i < quantity + 2) {
            fprintf(file, "%.04f\n", a[i]);
            i++;
        }
        if (file == NULL) { //Check if file opens
            printf("Error! File couldn't be open!");
            exit(0);
        }
        fclose(file); //Close file
    }
    if (num == 2) {
        char File[50] = {0};
        if (visited == true) {
            sprintf(File, "%s_Scaled_%d.txt", new, filenum);
        } else
            sprintf(File, "Scaled_data_%d.txt", filenum);
        FILE *file = fopen(File, "w"); //Open file and write data to file
        fprintf(file, "%d %.04f\n", quantity, change);
        while (i < quantity + 2) {
            fprintf(file, "%.04f\n", a[i++]);
        }
        if (file == NULL) { //Check if file opens
            printf("Error! File couldn't be open!");
            exit(0);
        }
        fclose(file); //Close file
    }
}

void scale(int a[], int length, double scaler, int filenum, bool visited, char new[]) {
    double b[length]; //initialize variables
    int i = 2;
    while (i < length + 2) { //Assign scale of array a to array b
        b[i] = a[i] * scaler;
        i++;
    }
    filewrite(b, 2, length, scaler, filenum, visited, new); //Write array b to file
}

void offset(int a[], int quantity, double oFFset, int filenum, bool visited, char new[]) {
    double b[quantity]; //initialize variables
    int i = 2;
    while (i < quantity + 2) { //Assign offset of array a to array b
        b[i] = a[i] + oFFset;
        i++;
    }
    filewrite(b, 1, quantity, oFFset, filenum, visited, new); //Write array b to file
}

void normal(int array[], int quantity, int max, int filenum, bool visited, char new[]) {
    int i = 2; //initialize variables
    char file[50] = {0};
    float array1[quantity];
    while (i < quantity + 2) {
        array1[i] = array[i]; //assign array to array
        i++;
    }
    i = 2;
    while (i < quantity + 2) { //Normalize arrary2
        array1[i] = array1[i] / max;
        i++;
    }
    i = 2;
    if (visited == true) {
        sprintf(file, "%s_Normalized_%d.txt", new, filenum);
    } else
        sprintf(file, "Normalized_data_%d.txt", filenum);
    FILE *File = fopen(file, "w"); //write information to file
    if (File == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(0);
    }
    fprintf(File, "%d %d\n", quantity, max); //Print information to file
    while (i < quantity + 2) {
        fprintf(File, "%.04f\n", array1[i]);
        i++;
    }
}

void center(int array[], int quantity, int max, int filenum, bool visited, char new[]) {
    int i = 2; //initialize variables
    char file[50] = {0};
    double aveg;
    float array1[quantity];
    aveg = avg(array, quantity); //find average of array
    while (i < quantity + 2) { //Center the array
        array1[i] = array[i] - aveg;
        i++;
    }
    i = 2;
    if (visited == true) {
        sprintf(file, "%s_Centered_%d.txt", new, filenum);
    } else
        sprintf(file, "Centered_data_%d.txt", filenum);
    FILE *File = fopen(file, "w"); //Create file
    if (File == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(0);
    }
    fprintf(File, "%d %.04f\n", quantity, aveg); //Write data to file
    while (i < quantity + 2) {
        fprintf(File, "%.04f\n", array1[i]);
        i++;
    }
}

int main(int argc, char** argv) {
    bool visited = false;
    int choice, quantity, Max, num, i = 0, j = 0, filenum = 0; //initialize variables
    double scaler, oFFset;

    char fIle[50] = {0}, file[50] = {0}, new[20] = {0};
    if (argc < 2) {
        printf("Invalid number of arguments!");
        exit(1);
    }
    while (argv[i][0] != '-' && argv[i][1] != 'h') {
        i++;
    }
    if (argv[i][0] == '-' && argv[i][1] == 'h') {
        printf("The options/parameters that need to be handled are:\n"
                "-n: File number (value needed)\n"
                "-o: offset value (value needed)\n"
                "-s: scale factor (value needed)\n"
                "-S: Get statistics\n"
                "-C: Center the signal\n"
                "-N: Normalize signal\n"
                "-r: Rename files (name needed)\n"
                "-h: Help (display how the program should be called, including the different input options)\n");
        exit(0);
    }
    i = 0;
    while (argv[i][0] != '-' && argv[i][1] != 'n') {
        if (i >= argc) {
            printf("Invalid input!");
            exit(1);
        }
        i++;
    }
    sprintf(fIle, "Raw_data_%d.txt", atoi(argv[++i]));
    filenum = atoi(argv[i]);
    FILE *filE = fopen(fIle, "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    fscanf(filE, "%d %d", &quantity, &Max); //read the chosen file
    int array[quantity + 3];
    while (!feof(filE)) { //assign numbers from file to arrays
        fscanf(filE, "%d\n", &num);
        array[i] = num;
        i++;
    }
    fclose(filE);

    switch (argc) {
        case 4:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 5:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 6:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 7:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 8:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 9:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 10:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 11:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        case 12:
            while (j < argc) {
                if (argv[j][0] == '-' && argv[j][1] == 'r') {
                    sprintf(new, "%s", argv[++j]);
                    sprintf(file, "%s.txt", argv[j]); //copy string to another variable
                    FILE *File = fopen(file, "w"); //open and close file
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%d %d\n", quantity, Max); //Write data to file
                    i = 2;
                    while (i < quantity + 2) {
                        fprintf(File, "%d\n", array[i]);
                        i++;
                    }
                    fclose(File); //Open writable file for average and max
                    visited = true;
                } else if (argv[j][0] == '-' && argv[j][1] == 'S') {
                    if (visited == true) {
                        sprintf(file, "%s_Statistics_%d.txt", new, filenum);
                    } else
                        sprintf(file, "Statistics_data_%d.txt", filenum);
                    FILE *File = fopen(file, "w"); //Open writable file for average and max
                    if (File == NULL) { //Check if file opens
                        printf("Error! File couldn't be open!");
                        exit(1);
                    }
                    fprintf(File, "%.04f %d", avg(array, quantity),
                            max(array, quantity)); //write the average and max to file
                    fclose(File);
                } else if (argv[j][0] == '-' && argv[j][1] == 'C') {
                    center(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'N') {
                    normal(array, quantity, Max, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 's') {
                    sscanf(argv[j + 1], "%lf", &scaler);
                    scale(array, quantity, scaler, filenum, visited, new);
                } else if (argv[j][0] == '-' && argv[j][1] == 'o') {
                    sscanf(argv[j + 1], "%lf", &oFFset);
                    offset(array, quantity, oFFset, filenum, visited, new);
                }
                j++;
            }
            break;
        default:
            printf("Invalid number of arguments!");
            exit(1);
            break;
    }
    return EXIT_SUCCESS;
}