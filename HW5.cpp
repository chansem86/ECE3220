// L14_Ex1_Inheritance.cpp
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

// --------- BaseSig class and methods ------------------------------
class BaseSig{
	private:
		// neither derived classes nor other users
		// can access private members
	
	protected:	// accessible by derived classes, not by other users.
		int length;
		int *raw_data;
		int max;
		
	public:
		BaseSig();		// default constructor.
		BaseSig(int L);	// parametric constructor
		~BaseSig();		// destructor
		int getLength() { return length; };
		int getRawValue(int pos);
		static int numObjects;	// static, only one member for the entire hierarchy
		virtual void printInfo();
};

int BaseSig::numObjects= 0;	// initialize static data member

// Base class constructor
BaseSig::BaseSig(){
	length = 0;
	raw_data = NULL;
	numObjects++;
}

// Base class parametric constructor
// Note that the data array is not being initialized (we could read from a file)
BaseSig::BaseSig(int L){
	length = L;
	raw_data = new int[L];
	if(raw_data == NULL)
		cerr << "Error in memory allocation";
	numObjects++;

	using std::iostream;
	char file[50] = {'\0'};
	int i;
	sprintf(file, "Raw_data_1.txt");
	FILE *filE = fopen(file, "r"); //Open chosen file
	if (filE == NULL) { //Check if file opens
	    printf("Error! File couldn't be open!");
	    exit(1);
	}
	fscanf(filE, "%d %lf", &length, &max);
	raw_data = new double [length];
	while (!feof(filE)) { //assign numbers from file to arrays
	    fscanf(filE, "%lf\n", &raw_data[i++]);
	}
}

// Base class destructor
BaseSig::~BaseSig(){
	delete[] raw_data;
	cout << "Goodbye, BaseSig." << endl;
}

int BaseSig::getRawValue(int pos) {
	if(pos < 0)			// invalid index
		return(raw_data[0]);
	else if(pos >= length)	// invalid index
		return(raw_data[length-1]);	
	else
		return(raw_data[pos]);
}

void BaseSig::printInfo() {
	cout << "\nLength: " << length << endl;
}
// ------------------------------------------------------------------

// --------- ExtendSig class and methods ----------------------------
class ExtendSig : public BaseSig{ // ExtendSig is derived from class BaseSig
//BaseSig is a public base class
	private: 
		double average;		// add new data members
		double *data;
		
	public:
		ExtendSig(int L);	//derived classes need a new constructor
		~ExtendSig();
		
		// define new member functions
		double getValue(int pos);
		int setValue(int pos, double val);
		double getAverage();
		
		// redefine member function. Virtual keyword not needed
		void printInfo();	// new standard: explicit "override" keyword can be used
};

// Derived class constructor. Note how the Base constructor is called.
ExtendSig::ExtendSig(int L) : BaseSig(L) {
	data = new double[L];
	if(data == NULL)
		cerr << "Error in memory allocation";
	else{
		for(int i = 0; i < L; i++)
			data[i] = (double)raw_data[i];
		average = getAverage();
	}
}

// Derived class destructor
ExtendSig::~ExtendSig() {
	//delete raw_data;
	delete data;
	cout << "Goodbye, ExtendSig." << endl;
}

double ExtendSig::getValue(int pos) {
	if(pos < 0)			// invalid index
		return(data[0]);
	else if(pos >= length)	// invalid index
		return(data[length-1]);	
	else
		return(data[pos]);
}

int ExtendSig::setValue(int pos, double val) {
	if((pos < 0) || (pos >= length))
		return(-1);	// invalid index
	else {
		data[pos] = val;
		average = getAverage();
		return(0);	// success
	}
}

double ExtendSig::getAverage() {
	if(length == 0)
		return(0.0);
	else {
		double temp = 0.0;
		for(int i = 0; i < length; i++)
			temp += data[i];
		return(temp/(double)length);
	}
}

// Redefined printInfo function for derived class
void ExtendSig::printInfo() {
	cout << "\nLength: " << length << endl
		 << "Average: " << average << endl;
}
// ------------------------------------------------------------------

// Main function. A few examples
int main(){
	BaseSig bsig1(5);
	ExtendSig esig1(10);
	cout << "# of objects created: " << bsig1.numObjects << endl
		 << "# of objects created: " << esig1.numObjects << endl;
	bsig1.printInfo();
	esig1.printInfo();
	cout << "--------------------------------------------" << endl;
	
	cout << endl << bsig1.getRawValue(3) << endl
		 << esig1.getRawValue(7) << endl
		 << esig1.getValue(7) << endl;
	cout << "--------------------------------------------" << endl;
	
	cout << endl << esig1.setValue(7, 2.5) << endl
		 << esig1.setValue(12, 2.0) << endl;
		 
	cout << endl << esig1.getValue(7) << endl;
	esig1.printInfo();
	cout << "--------------------------------------------" << endl;
	
	BaseSig *ptrB = &bsig1;	// pointer points to object of base class
	BaseSig &refB = bsig1;  // reference to object of base class
	ptrB->printInfo();		// which version is used?
	refB.printInfo();		// which version is used?
	
	ptrB = &esig1;	// pointer points to the base part of the object of derived class
	BaseSig &refB2 = esig1; // reference bound to the base part of esig1
	ptrB->printInfo();		// which version is used?
	refB2.printInfo();		// which version is used?
	cout << "--------------------------------------------" << endl;
	return 0;
}
