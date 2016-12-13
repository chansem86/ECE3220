#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;
FILE *fop;

// --------- BaseSig class and methods ------------------------------
class BaseSig{
	private:
		// neither derived classes nor other users
		// can access private members
	
	protected:	// accessible by derived classes, not by other users.
		int length;
		int *raw_data;
		
	public:
		BaseSig();		// default constructor.
		BaseSig(int L);	// parametric constructor
		~BaseSig();		// destructor
		int getLength() { return length; };
		int getRawValue(int pos);
		static int numObjects;	// static, only one member for the entire hierarchy
		virtual void printInfo();
};

int BaseSig::numObjects = 0;	// initialize static data member

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
    fop=fopen("Raw_data_02.txt","r");
    if(fop==NULL)//This is to make sure it will open the file correctly.
    {
        cout << "open file failed!\n" << endl;
        exit(1);
    }
    else
    {   
        int len,i;
        double t;
        cout << "open file succeed!\n" << endl;
        fscanf(fop, "%d", &len);//read the first value in the file which is the size of the file.
        fscanf(fop, "%d", &t); //read the second value of the file which is the maximum possible value.
		for (i=0;i<length;++i){
		fscanf(fop, "%d", raw_data+i);//the for loop is to read all the values in the file.
        }
    }
	if(raw_data == NULL)
		cerr << "Error in memory allocation";
	numObjects++;
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
    
    protected:
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
class ProcessedSignal : public BaseSig{
    private: 
        double min, max, average;
        double *pdata;
    public:
        ProcessedSignal(int L);
        ~ProcessedSignal();
    
        double getmax();
        double getmin();
        double getpAverage();
        double getNormal();
        void printInfo();
        double getpValue(int pos);
        int setpValue(int pos, double val);
};

ProcessedSignal::ProcessedSignal(int L) : BaseSig(L){
    pdata = new double[L];
	if(pdata == NULL)
		cerr << "Error in memory allocation";
	else{
		for(int i = 0; i < L; i++){
			pdata[i] = (double)raw_data[i];
        }
        max = getmax();
        min = getmin();
        average = getpAverage();
    }
}

ProcessedSignal::~ProcessedSignal(){
    delete pdata;
    cout << "Goodbey, ProcessedSignal." << endl;
}

double ProcessedSignal::getmax(){
    if(length == 0)
		return(0.0);
	else {
		double max = 0.0;
		for(int i = 0; i < length; i++){
            if (max < pdata[i]){
                max = pdata[i];
            }
        }
        return (max);
    }
}

double ProcessedSignal::getmin(){
    if(length == 0)
		return(0.0);
	else {
		double min = pdata[0];
		for(int i = 1; i < length; i++){
            if (min > pdata[i]){
            min = pdata[i];
            }
        }
        return (min);
    }
}

double ProcessedSignal::getpAverage() {
	if(length == 0)
		return(0.0);
	else {
		double temp = 0.0;
		for(int i = 0; i < length; i++)
			temp += pdata[i];
		return(temp/(double)length);
	}
}

double ProcessedSignal::getNormal(){
    if(length == 0)
		return(0.0);
	else {
		for(int i = 0; i < length; i++){
            pdata[i] = pdata[i]/max;
            cout << pdata[i] << endl;
        }
            average = getpAverage();
            max = getmax();
            min = getmin();
    }
}

double ProcessedSignal::getpValue(int pos) {
	if(pos < 0)			// invalid index
		return(pdata[0]);
	else if(pos >= length)	// invalid index
		return(pdata[length-1]);	
	else
		return(pdata[pos]);
}

int ProcessedSignal::setpValue(int pos, double val) {
	if((pos < 0) || (pos >= length))
		return(-1);	// invalid index
	else {
		pdata[pos] = val;
		average = getpAverage();
        max = getmax();
        min = getmin();
		return(0);	// success
	}
}

// Redefined printInfo function for derived class
void ProcessedSignal::printInfo() {
	cout << "\nLength: " << length << endl
		 << "Average: " << average << endl
         << "Maximum: " << max << endl
         << "minimum: " << min << endl;
}

class ProcessedSignal_v2 : public ExtendSig{
    private: 
        double min, max;
    public:
        ProcessedSignal_v2(int L);
        ~ProcessedSignal_v2();
    
        double getmax();
        double getmin();
        double getNormal();
        void printInfo();
        double getpValue(int pos);
        int setpValue(int pos, double val);
};

ProcessedSignal_v2::ProcessedSignal_v2(int L) : ExtendSig(L){
    data = new double[L];
	if(data == NULL)
		cerr << "Error in memory allocation";
	else{
		for(int i = 0; i < L; i++){
			data[i] = (double)raw_data[i];
        }
        max = getmax();
        min = getmin();
        average = getAverage();
    }
}

ProcessedSignal_v2::~ProcessedSignal_v2(){
    delete data;
    cout << "Goodbey, ProcessedSignal_v2." << endl;
}

double ProcessedSignal_v2::getmax(){
    if(length == 0)
		return(0.0);
	else {
		double max = 0.0;
		for(int i = 0; i < length; i++){
            if (max < data[i]){
                max = data[i];
            }
        }
        return (max);
    }
}

double ProcessedSignal_v2::getmin(){
    if(length == 0)
		return(0.0);
	else {
		double min = data[0];
		for(int i = 1; i < length; i++){
            if (min > data[i]){
            min = data[i];
            }
        }
        return (min);
    }
}

double ProcessedSignal_v2::getNormal(){
    if(length == 0)
		return(0.0);
	else {
		for(int i = 0; i < length; i++){
            data[i] = (data[i]/max);
            cout << data[i] << endl;
        }
            average = getAverage();
            max = getmax();
            min = getmin();
    }
}

double ProcessedSignal_v2::getpValue(int pos) {
	if(pos < 0)			// invalid index
		return(data[0]);
	else if(pos >= length)	// invalid index
		return(data[length-1]);	
	else
		return(data[pos]);
}

int ProcessedSignal_v2::setpValue(int pos, double val) {
	if((pos < 0) || (pos >= length))
		return(-1);	// invalid index
	else {
		data[pos] = val;
		average = getAverage();
        max = getmax();
        min = getmin();
		return(0);	// success
	}
}

// Redefined printInfo function for derived class
void ProcessedSignal_v2::printInfo() {
	cout << "\nLength: " << length << endl
		 << "Average: " << average << endl
         << "Maximum: " << max << endl
         << "minimum: " << min << endl;
}
// Main function. A few examples
int main(){
//	BaseSig bsig1(5);
//	ExtendSig esig1(10);
//	cout << "# of objects created: " << bsig1.numObjects << endl
//		 << "# of objects created: " << esig1.numObjects << endl;
//	bsig1.printInfo();
//	esig1.printInfo();
//	cout << "--------------------------------------------" << endl;
//	
//	cout << endl << bsig1.getRawValue(3) << endl
//		 << esig1.getRawValue(7) << endl
//		 << esig1.getValue(7) << endl;
//	cout << "--------------------------------------------" << endl;
//	
//	cout << endl << esig1.setValue(7, 2.5) << endl
//		 << esig1.setValue(12, 2.0) << endl;
//		 
//	cout << endl << esig1.getValue(7) << endl;
//	esig1.printInfo();
//	cout << "--------------------------------------------" << endl;
    
    ProcessedSignal psig1(15);
    cout << endl << psig1.getpValue(7) << endl;
     psig1.printInfo();//These two Outputs the value of the 8th member of data and then print current info.
		 cout << psig1.setpValue(7, 3.0) << endl;//Change the value of the 8th member to 3.0. Output 0 means success.
         cout << psig1.getpValue(7) << endl;
             psig1.printInfo();//These two get the Outputs the new set value of the 8th member of data and then print current info.
    psig1.getNormal();//Normalization the data and output all data value (one of the member already been changed by last step).
    cout << psig1.getpValue(7) << endl;
    psig1.printInfo();//These two Outputs the value of the 8th member of data and then print current info(after Normalization).
	cout << "--------------------------------------------" << endl;
    ProcessedSignal_v2 psig2(18);
    cout << endl << psig2.getpValue(9) << endl;
     psig2.printInfo();//These two Outputs the value of the 10th member of data and then print current info.
		 cout << psig2.setpValue(9, 60.0) << endl;//Change the value of the 10th member to 60.0.Output 0 means success.
         cout << psig2.getpValue(9) << endl;
             psig2.printInfo();//These two get the Outputs the new set value of the 10th member of data and then print current info.
    psig2.getNormal();//Normalization the data and output all data value (one of the member already been changed by last step).
    cout << psig2.getpValue(9) << endl;
    psig2.printInfo();//These two Outputs the normalized value of the 10th member of data and then print current info(after Normalization).
    	cout << "--------------------------------------------" << endl;
	return 0;
}