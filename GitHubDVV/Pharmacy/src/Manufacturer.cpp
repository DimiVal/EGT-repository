/*
 * Manufacturer.cpp
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Manufacturer.h"

Manufacturer::Manufacturer() {
	setNameMan("n/a");
	setCode(0);
	setCountry("n/a");
}

Manufacturer::Manufacturer(string nameMan, int code, string country) {
	setNameMan(nameMan);
	setCode(code);
	setCountry(country);
}

void Manufacturer::print() {
	cout << "Name of manuf.:" << getNameMan() <<
			" Code:" << getCode() << " Country:" << getCountry() << endl;
}

Manufacturer::~Manufacturer() {
	// TODO Auto-generated destructor stub
}

int Manufacturer::getCode() const {
	return code;
}

void Manufacturer::setCode(int code) {
	this->code = code;
}

const string& Manufacturer::getCountry() const {
	return country;
}

void Manufacturer::setCountry(const string& country) {
	this->country = country;
}

const string& Manufacturer::getNameMan() const {
	return nameMan;
}

void Manufacturer::setNameMan(const string& nameMan) {
	this->nameMan = nameMan;
}
