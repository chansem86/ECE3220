//============================================================================
// Name        : ExamExtraCredit12.cpp
// Author      : Chanse Meyer
// Version     :
// Copyright   : Property of Chanse Meyer. Do Not Copy.
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int a=10;
int func(int b){
	a+=b;
	return a;
}

int main() {
	int b=20;
	int &c=b;
	int *d=&b;
	func(b);

	cout << a << endl;
	cout << a+1 << endl;
	cout << c << endl;
	cout << c+1 << endl;
	cout << d << endl;
	cout << d+1 << endl;
}
