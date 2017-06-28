/*
 * Book.h
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef BOOK_H_
#define BOOK_H_
#include <iostream>
#include <string>
#include "pugixml.hpp"
using namespace std;

class Book {
public:
	Book();
	virtual ~Book();

	void print() const;

	const string& getAuthor() const;
	void setAuthor(const string& author);

	const string& getLanguage() const;
	void setLanguage(const string& language);

	double getPrice() const;
	void setPrice(double price);

	const string& getTitle() const;
	void setTitle(const string& title);

	int getYearEdition() const;
	void setYearEdition(int yearEdition);

private:
	string title;
	string language;
	string author;
	int yearEdition;
	double price;
};

#endif /* BOOK_H_ */
