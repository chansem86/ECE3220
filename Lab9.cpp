

 /* File:   Lab9.cpp */

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
    void operator*(int scaler);
    void operation(int choice);
    void offset(double oFFset);
    void scale(double scaler);
    void normal();
    void center();
    void sig_Info();
    void save_File(string name);
    vector<double> getData(){
        return data;
    }
    int getLength(){
        return length;
    }
    double getMaximum(){
        maximum();
        return max;
    }
    void setMax(double mAx){
        max = mAx;
    }
    double getAvg(){
        return average();
    }
    void setAvg(double avg){
        aVerage = avg;
    }
    void setData(vector<double> data1, vector<double> data2);
};

Signal::Signal() { //This is the default constructor that initialize the
    length = 0; //members of the constructor.
    max = 0;
    aVerage=0;
    vector<double> data;
}

Signal::Signal(int num) { //The constructor takes in an integer value
    aVerage=0;
	string ext = ".txt";
    string file = "Raw_data_";
    file.push_back(num);
    file = file + ext;//Declare variables for the
    //int i; //constructor
    //sprintf(file, "Raw_data_%d.txt", num);
    FILE *filE = fopen(file.c_str(), "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    double info;
    fscanf(filE, "%d %lf", &length, &max); //Stores the values from file to
    vector<double> data[length]; //corresponding members of the
    while (!feof(filE)) { //constructor.
        fscanf(filE, "%lf\n", &info);



    }
}

Signal::Signal(string name) { //The constructor takes in an character pointer
	aVerage=0;
	Signal();
    string file = name + ".txt"; //Declare variables for the
    //int i = 0; //constructor
    //int num = 0;
    //sprintf(file, "%s.txt", name); //Concatenate name with file type
    FILE *filE = fopen(file.c_str(), "r"); //Open chosen file
    if (filE == NULL) { //Check if file opens
        printf("Error! File couldn't be open!");
        exit(1);
    }
    double info;
    fscanf(filE, "%d %lf", &length, &max); //Stores the values from file to
    //vector<double> data[length]; //corresponding members of the
    while (!feof(filE)) { //constructor.
        fscanf(filE, "%lf\n", &info);
        data.push_back(info);
        //getline(filE,data[i++],'\n');
    }
}

Signal::~Signal() { //Destructor
}

double Signal::average() { //This method sums up all the data
    int i = 0; //in the pointer, divide it by the
    double total = 0, avg; //length, and return the double
    while (i < length) { //variable avg.
        total += data[i];
        i++;
    }
    avg = total / length;
    return avg;
}

void Signal::maximum() { //This method finds the maximum
    int i = 0; //value of the various values in the
    double mAx = 0; //data pointer and assign the max
    while (i < length) { //value to the member of the
        if (data[i] > mAx) { //constructor.
            mAx = data[i];
        }
        i++;
    }
    max = mAx;
}

void Signal::menu() { //The menu of operations for the user
    cout << "Choose an option:\n" //to choose from.
            "1. Signal Info\n"
            "2. Offset\n"
            "3. Scale\n"
            "4. Normalize\n"
            "5. Center\n"
            "6. Save Signal\n";
}

void Signal::operator +(double oFFset){
    int i = 0;
    while (i < length){
        data[i] += oFFset;  //the variable to the values in the data pointer.
    }
}

void Signal::operator *(int scaler){
    int i = 0;
    while(i < length){
        data[i] *= scaler;  //initialize variables the variable to the values in the data
    }                   //pointer.
}

void Signal::operation(int choice) { //This method carries out the desired
    double oFFset, scaler; //operation annotation using an
    string file = "Raw_data_13"; //switch statement
    switch (choice) {
        case 1:
            sig_Info();
            break;
        case 2:
            cout << "How much do you want to offset your signal?:";
            cin >> oFFset;
            offset(oFFset);
            //operator +(oFFset);
            maximum();
            break;
        case 3:
            cout << "How much do you want to scale your signal by?:";
            cin >> scaler;
            scale(scaler);
            //operator *(scaler);
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

void Signal::offset(double oFFset) { //Takes in an double variable and adds
    operator+(oFFset);  //the variable to the values in the data pointer.
}

void Signal::scale(double scaler) { //Takes in an double variable and multiply
    operator*(scaler);  //initialize variables the variable to the values in the data
}                        //pointer.
void Signal::normal() { //Takes the max and divides it by the
    //int i = 0; //initialize variables   //values in the data pointer.
    /*while (i < length) {
        data[i] /= max;
        i++;
    }*/
    operator *(1/max);
}

void Signal::center() { //Takes the average and subtracts it by 
    //int i = 0; //initialize variables   //the values in the data pointer
    double avg = average();
    /*while (i < length) {
        data[i] -= avg;
        i++;
    }*/
    operator +(-(avg));
}

void Signal::sig_Info() { //Prints the length of the signal,
    cout << "Length: " << length << endl; //the maximum, and the average
    cout << "Maximum: " << max << endl;
    cout << "Average: " << average() << endl;
}

void Signal::save_File(string name) { //This method takes in an string and
    string ext = ".txt";
    string fIle = name + ext; //concatenate the string to the file 
    int i = 0; //type
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
    cout << "You have just saved the signal to the file " << fIle; //Prompts on success.
}

void Signal::setData(vector<double> data1, vector<double> data2){
    int i = 0;
    while (i < length){
        data[i] = data1[i] + data2[i];
        i++;
    }
}

Signal operator +(Signal a, Signal b){
    Signal temp;
    //int i = 0;
    double avg1 = a.getAvg(), avg2 = b.getAvg();
    if (a.getLength() == b.getLength())
        temp.setData(a.getData(),b.getData()); 
    if (a.getMaximum() > b.getMaximum())
        temp.setMax(a.getMaximum());
    else
        temp.setMax(b.getMaximum());
    temp.setAvg((avg1 + avg2)/2);
    return 0;

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

            cout << "please enter the file name of the second signal:";
            cin >> input;
            Signal signal2(input);
            Signal sigSum = signal1 + signal2;
            sigSum.sig_Info();


        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'n') { //Check for fie number
        file_num = atoi(argv[2]);
        Signal signal1(file_num); //Creates an object
        while (choice != 6) {
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
    } else if (argv[1][0] == '-' && argv[1][1] == 'f') { //Check for file name
        Signal signal1(argv[2]); //Creates an object
        while (choice != 6) {
            signal1.menu();
            cin >> choice;
            signal1.operation(choice);
        }
    } else { //Handles invalid command line commands
        std::cout << "Invalid argument.\n The program either take -n followed by an number of -f followed by a filename.\n Or no arguments at all!";
        return (1);
    }
    return 0;
}
