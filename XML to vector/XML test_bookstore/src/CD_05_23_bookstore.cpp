//============================================================================
// Name        : CD_05_23_bookstore.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include "pugixml.hpp"
#include "Book.h"
#include "Operations.h"
using namespace std;

int main() {

	Operations op1;
	op1.XmlToVector("Book.xml");
	op1.print();
	cout << endl;

	cout << "The cheapest book in the store: \n";
	op1.TheCheapestBook().print();
	cout << endl;

	cout << "The most expensive book in the store: \n";
	op1.TheMostExpensiveBook().print();


return 0;
}
