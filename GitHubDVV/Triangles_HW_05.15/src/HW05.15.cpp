//============================================================================
// Name        : 15.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Triangle.h"
#include <iostream>
using namespace std;

int main() {

	Triangle tr1;
	cout << "Please enter numbers in type: -a-b-c-h." << endl;
	cin >> tr1; // -a-b-c-h

	//cout << tr1;  // =>a,b,c,h

	Triangle tr2;
	cin >> tr2;

	cout << tr1.operator !=(tr2) << endl;
	cout << tr1.operator ==(tr2) << endl;

	/*if (tr1!=tr2){
		cout << "They are different." << endl;
	}*/

	return 0;
}
