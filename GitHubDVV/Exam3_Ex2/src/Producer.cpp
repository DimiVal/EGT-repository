/*
 * Producer.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Producer.h"

Producer::Producer() {
	// TODO Auto-generated constructor stub
	setFirstName("N/A");
	setLastName("N/A");
	setPopularity("N/A");
}

Producer::~Producer() {
	// TODO Auto-generated destructor stub
}

const string& Producer::getFirstName() const {
	return firstName;
}

void Producer::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Producer::getLastName() const {
	return lastName;
}

void Producer::setLastName(const string& lastName) {
	this->lastName = lastName;
}

const string& Producer::getPopularity() const {
	return popularity;
}

void Producer::setPopularity(const string& popularity) {
	this->popularity = popularity;
}

Producer::Producer(string firstName, string lastName, string popularity) {
	setFirstName(firstName);
	setLastName(lastName);
	setPopularity(popularity);
}

void Producer::print() {
	cout << getFirstName() << " " << getLastName()
			<< " " << getPopularity() << endl;
}

