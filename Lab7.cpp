/* 
 * File:   Lab7.cpp
 * Author: Chanse Meyer and Jonathan Davis
 */

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Signal {
private:
    int length;
    double max;
    double *data;
    double average();
    void maximum();
public:
    Signal();
    Signal(int num);
    Signal(char* name);
    ~Signal();
    void menu();
    void operation(int choice);
    void offset(double oFFset);
    void scale(double scaler);
    void normal();
    void center();
    void sig_Info();
    void save_File(char* name);
    
};

Signal::Signal() {
    length = 0;
    max = 0;
    data = NULL;
}

Signal::Signal(int num) {
    Signal();
    using std::iostream;
    char file[50] = {'\0'};
    int i;
    sprintf(file, "Raw_data_%d.txt", num);
    FILE *filE = fopen(file, "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    fscanf(filE, "%d %lf", &length, &max);
    data = new double [length];
    while (!feof(filE)) { //assign numbers from file to arrays
        fscanf(filE, "%lf\n", &data[i++]);
    }
}

Signal::Signal(char* name) {
    Signal();
    using std::iostream;
    char file[50] = {'\0'};
    int i = 0;
    int num = 0;
    sprintf(file, "%s.txt", name);
    std::FILE *filE = fopen(file, "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    fscanf(filE, "%d %lf", &length, &max);
    data = new double [length];
    while (!feof(filE)) { //assign numbers from file to arrays
        fscanf(filE, "%lf\n", &data[i++]);
    }
}

Signal::~Signal() {
    if (data) {
        delete[] data;
    }
}

double Signal::average() {
    int i = 0;
    double total = 0, avg;
    while (i < length) {
        total += data[i];
        i++;
    }
    avg = total / length;
    return avg;
}

void Signal::maximum() {
    int i = 0;
    double mAx = 0;
    while (i < length) {
        if (data[i] > mAx) {
            mAx = data[i];
        }
        i++;
    }
    max = mAx;
}

void Signal::menu() {
    cout << "\nChoose an option:\n"
            "1. Signal Info\n"
            "2. Offset\n"
            "3. Scale\n"
            "4. Normalize\n"
            "5. Center\n"
            "6. Save Signal\n";
}

void Signal::operation(int choice){
    double oFFset, scaler;
    char file[50] = "Raw_data_13";
    switch (choice) {
            case 1:
                sig_Info();
                break;
            case 2:
                cout << "How much do you want to offset your signal?:";
                cin >> oFFset;
                offset(oFFset);
                maximum();
                break;
            case 3:
                cout << "How much do you want to scale your signal by?:";
                cin >> scaler;
                scale(scaler);
                maximum();
                break;
            case 4:
                normal();
                maximum();
                break;
            case 5:
                center();
                maximum();
                break;
            case 6:
                save_File(file);
                break;
            default:
                cerr << "Invalid option, try again!" << endl;
                break;
        }
}

void Signal::offset(double oFFset) {
    int i = 0;
    while (i < length) { //Assign offset of array a to array b
        data[i] += oFFset;
        i++;
    }
}

void Signal::scale(double scaler) {
    int i = 0; //initialize variables
    while (i < length) { //Assign scale of array a to array b
        data[i] *= scaler;
        i++;
    }
}

void Signal::normal() {
    int i = 0; //initialize variables
    while (i < length) { //Normalize arrary2
        data[i] /= max;
        i++;
    }
}

void Signal::center() {
    int i = 0; //initialize variables
    double avg = average(); //find average of array
    while (i < length) { //Center the array
        data[i] -= avg;
        i++;
    }
}

void Signal::sig_Info() {
    cout << "Length: " << length << endl;
    cout << "Maximum: " << max << endl;
    cout << "Average: " << average() << endl;
}

void Signal::save_File(char* name) {
    char fIle[50] = {'\0'};
    int i = 0;
    sprintf(fIle, "%s.txt", name);
    FILE* file = fopen(fIle, "w");
    if (file == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    fprintf(file, "%d %lf\n", length, max); //Write data to file
    while (i < length) {
        fprintf(file, "%lf\n", data[i]);
        i++;
    }
    fclose(file);
    cout << "You have just saved the signal to the file " << fIle;
}

int main(int argc, char** argv) {
    char input[50] = {'\0'};
    int file_num, choice = 0;
    if (argc < 2) {
        cout << "Please enter the file name:";
        cin >> input;
        Signal signal1(input);
        while (choice != 6){
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'n') {
        file_num = atoi(argv[2]);
        Signal signal1(file_num);
        while (choice != 6){
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'f') {
        Signal signal1(argv[2]);
        while (choice != 6){
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
    } else {
        std::cout << "Invalid argument.\n The program either take -n followed by an number of -f followed by a filename.\n Or no arguments at all!";
        return (1);
    }

    return 0;
}
