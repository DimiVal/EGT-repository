//============================================================================
// Name        : Exam3Ex1_1005.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Box.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {

	Box b1;
	cin >> b1;  // [x, y, z]
	Box b2;
	cin >> b2;

	Box b3 = b1 + b2;
	//cout << b3;

	if (b1 != b2) {
		cout << "b1 is greater " << endl;
	}



	return 0;
}
