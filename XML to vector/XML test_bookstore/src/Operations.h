/*
 * Operations.h
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include "pugixml.hpp"
#include "Book.h"
using namespace std;

class Operations {
public:
	Operations();
	virtual ~Operations();

	void print() const;

	void XmlToVector(const char* file);

	void SearchBook(string);

	const Book& TheCheapestBook() const;
	const Book& TheMostExpensiveBook() const;

	const vector<Book*>& getStore() const;
	void setStore(const vector<Book*>& store);

private:
	vector<Book*> store;

};

#endif /* OPERATIONS_H_ */
