
/* 
 * File:   Lab9.cpp
 * Author: Chanse and Jonathan
 */
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Signal {
private:
    int length; //Declare private methods for the signal class
    double max;
    double aVerage;
    vector<double> data;
    double average();
    void maximum();
public:
    Signal(); //Declare public methods for the signal class
    Signal(int num);
    Signal(string name);
    ~Signal();
    void menu();
    void operator+(double oFFset);
    void operator*(double scaler);
    void operation(int choice);
    void offset(double oFFset);
    void scale(double scaler);
    void normal();
    void center();
    void sig_Info();
    void save_File(string name);
    vector<double> getData() {
        return data;
    }
    int getLength() {
        return length;
    }
    void setLength(int len){
        length = len;
    }
    double getMaximum() {
        maximum();
        return max;
    }
    void setMax(double mAx) {
        max = mAx;
    }
    double getAvg() {
        return average();
    }
    void setAvg(double avg) {
        aVerage = avg;
    }
    void setData(vector<double> data1, vector<double> data2);
};

Signal::Signal() { //This is the default constructor that initialize the
    length = 0; //members of the constructor.
    max = 0;
}

Signal::Signal(int num) { //The constructor takes in an integer value
    Signal();
    char fileName[20] = {'\0'};
    string file; //Declare variables for the
    int i; //constructor
    sprintf(fileName, "Raw_data_%d.txt", num);
    file = fileName;
    FILE *filE = fopen(file.c_str(), "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    double info;
    fscanf(filE, "%d %lf", &length, &max); //Stores the values from file to
    while (!feof(filE)) { //corresponding members of the constructor.
        fscanf(filE, "%lf\n", &info);
        data.push_back(info);   //Pushes the value on to the corresponding vector
    }
}

Signal::Signal(string name) { //The constructor takes in an string variable
    Signal();
    string file = name + ".txt"; //Concatenate name with file type
    int i = 0; //Declare variables for the constructor
    int num = 0;
    FILE *filE = fopen(file.c_str(), "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    double info;
    fscanf(filE, "%d %lf", &length, &max); //Stores the values from file to
    while (!feof(filE)) { //corresponding members of the constructor.
        fscanf(filE, "%lf\n", &info);
        data.push_back(info);   //Pushes the value on to the corresponding vector
    }
}

Signal::~Signal() { //Destructor
}

double Signal::average() { //This method sums up all the data
    int i = 0; //in the vector, divide it by the length, and return the double
    double total = 0, avg; //variable avg.
    while (i < length) { 
        total += data[i];
        i++;
    }
    avg = total / length;
    return avg;
}

void Signal::maximum() { //This method finds the maximum value of the various 
    int i = 0; //values in the data vector and assign the max value to the 
    double mAx = 0; //member of the constructor.
    while (i < length) { 
        if (data[i] > mAx) { 
            mAx = data[i];
        }
        i++;
    }
    max = mAx;
}

void Signal::menu() { //The menu of operations for the user to choose from
    cout << "Choose an option:\n" 
            "1. Signal Info\n"
            "2. Offset\n"
            "3. Scale\n"
            "4. Normalize\n"
            "5. Center\n"
            "6. Save Signal\n";
}

void Signal::operator+(double oFFset) { //This operator overloader adds the
    int i = 0;  //passed double to the data vector
    while (i < length) {
        data[i] += oFFset; 
        i++;
    }
}

void Signal::operator*(double scaler) { //This operator overloader multiplies 
    int i = 0;  //the passed double to the data vector
    while (i < length) {
        data[i] *= scaler;
        i++;
    }
}

void Signal::operation(int choice) { //This method carries out the desired
    double oFFset, scaler; //operation annotation using an switch statement
    string file = "Raw_data_13"; 
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

void Signal::offset(double oFFset) { //Takes in an double variable and calls an
    operator+(oFFset); //operator overloader.
}

void Signal::scale(double scaler) { //Takes in an double variable and calls an
    operator*(scaler); //operator overloader.
}

void Signal::normal() { //Calls the maximum function and calls an operator
    maximum();  //overloader.
    operator*(1 / max);
}

void Signal::center() { //Calls the average function and assigns the value to
    double avg = average(); //an double variable and calls an operator
    operator+(-(avg));  //overloader.
}

void Signal::sig_Info() { //Prints the length of the signal, the maximum, and
    cout << "Length: " << length << endl; //the average
    cout << "Maximum: " << max << endl;
    cout << "Average: " << average() << endl;
}

void Signal::save_File(string name) { //This method takes in an string and
    string ext = ".txt"; //writes the value of the vector to an .txt file.
    string fIle = name + ext; //concatenate the string to the file type
    int i = 0; 
    FILE* file = fopen(fIle.c_str(), "w");
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
    cout << "You have just saved the signal to the file " << fIle << endl; //Prompts on success.
}

void Signal::setData(vector<double> data1, vector<double> data2) { //This method
    int i = 0;  //takes in two vectors and returns an single vector. 
    while (i < length) {
        data.push_back(data1[i] + data2[i]);
        i++;
    }
}

Signal operator+(Signal a, Signal b) {  //This  operator overloader takes two
    Signal temp;    //signals and adds them up if the signals are the same length
    int i = 0;  //returns the maximum value of the two vectors and return the
    double avg1 = a.getAvg(), avg2 = b.getAvg();    //average of the two signals.
    if (a.getLength() == b.getLength()) {
        temp.setLength(a.getLength());
        temp.setData(a.getData(), b.getData());
        if (a.getMaximum() > b.getMaximum())
            temp.setMax(a.getMaximum());
        else
            temp.setMax(b.getMaximum());
        temp.setAvg((avg1 + avg2) / 2);
        return temp;
    }
    else
        cout << "Sorry, we can only add signals of the same length." << endl;
}

int main(int argc, char** argv) {
    string input;
    int file_num, choice = 0;
    if (argc < 2) { //Checks for command line
        cout << "Please enter the file name:"; //arguments
        cin >> input;
        Signal signal1(input);
        while (choice != 6) {
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
            cout << "Please enter the file name of the second signal:"; //Prompts the user
            cin >> input;
            Signal signal2(input);  //Call an second instance of Signal
            Signal sigSum = signal1 + signal2;  //Call the operator overloader
            sigSum.sig_Info();  //Print the information of the signal
    } else if (argv[1][0] == '-' && argv[1][1] == 'n') { //Check for fie number
        file_num = atoi(argv[2]);
        Signal signal1(file_num); //Creates an object
        while (choice != 6) {
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
         cout << "Please enter the file name of the second signal:"; //Prompts the user
            cin >> input;
            Signal signal2(input);  //Call an second instance of Signal
            Signal sigSum = signal1 + signal2;  //Call the operator overloader
            sigSum.sig_Info();  //Print the information of the signal
    } else if (argv[1][0] == '-' && argv[1][1] == 'f') { //Check for file name
        Signal signal1(argv[2]); //Creates an object
        while (choice != 6) {
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
         cout << "Please enter the file name of the second signal:"; //arguments
            cin >> input;
            Signal signal2(input);  //Call an second instance of Signal
            Signal sigSum = signal1 + signal2;  //Call the operator overloader
            sigSum.sig_Info();  //Print the information of the signal
    } else { //Handles invalid command line commands
        std::cout << "Invalid argument.\n The program either take -n followed by an number of -f followed by a filename.\n Or no arguments at all!";
        return (1);
    }
    return 0;
}
