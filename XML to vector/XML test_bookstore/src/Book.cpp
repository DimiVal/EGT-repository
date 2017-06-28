/*
 * Book.cpp
 *
 *  Created on: 25.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Book.h"

Book::Book() {
	// TODO Auto-generated constructor stub
}

Book::~Book() {
	// TODO Auto-generated destructor stub
}

void Book::print() const {
	cout << "Title of book: " << getTitle() << endl;
	cout << "Language: " << getLanguage() << endl;
	cout << "Author: " << getAuthor() << endl;
	cout << "Year of edition: " << getYearEdition() << endl;
	cout << "Price: " << getPrice() << endl;
}

const string& Book::getAuthor() const {
	return author;
}

void Book::setAuthor(const string& author) {
	this->author = author;
}

const string& Book::getLanguage() const {
	return language;
}

void Book::setLanguage(const string& language) {
	this->language = language;
}

double Book::getPrice() const {
	return price;
}

void Book::setPrice(double price) {
	this->price = price;
}

const string& Book::getTitle() const {
	return title;
}

void Book::setTitle(const string& title) {
	this->title = title;
}

int Book::getYearEdition() const {
	return yearEdition;
}

void Book::setYearEdition(int yearEdition) {
	this->yearEdition = yearEdition;
}
