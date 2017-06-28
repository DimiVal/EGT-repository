/*
 * Medicine.cpp
 *
 *  Created on: 4.06.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Medicine.h"

Medicine::Medicine() {
	setName("n/a");
	setType("n/a");
	setQuantity(0);
	setPrice(0.0);
	// TODO Auto-generated constructor stub
}

Medicine::Medicine(string name, string type, int quantity, double price) {
	setName(name);
	setType(type);
	setQuantity(quantity);
	setPrice(price);
}

void Medicine::print() const {
	cout << "Name: " << getName() << endl;
	cout << "Type: " << getType() << endl;
	cout << "Quantity: " << getQuantity() << endl;
	cout << "Price: " << getPrice() << endl;
}

Medicine::~Medicine() {
	// TODO Auto-generated destructor stub
}

const string& Medicine::getName() const {
	return name;
}

void Medicine::setName(const string& name) {
	this->name = name;
}

double Medicine::getPrice() const {
	return price;
}

void Medicine::setPrice(double price) {
	this->price = price;
}

int Medicine::getQuantity() const {
	return quantity;
}

void Medicine::setQuantity(int quantity) {
	this->quantity = quantity;
}

const string& Medicine::getType() const {
	return type;
}

void Medicine::setType(const string& type) {
	this->type = type;
}
