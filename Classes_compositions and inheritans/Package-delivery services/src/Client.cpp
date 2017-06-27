/*
 * Client.cpp
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Client.h"

Client::Client() {
	setFirstName("N/A");
	setLastName("N/A");
}

Client::Client(string firstName, string lastName, Address& adr) :
		adr(adr) {
	setFirstName(firstName);
	setLastName(lastName);
}

void Client::print() {
	cout << getFirstName() << " " << getLastName() << " " << endl;
	adr.print();
}

const Address& Client::getAdr() const {
	return adr;
}

void Client::setAdr(const Address& adr) {
	this->adr = adr;
}

const string& Client::getFirstName() const {
	return firstName;
}

void Client::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

const string& Client::getLastName() const {
	return lastName;
}

void Client::setLastName(const string& lastName) {
	this->lastName = lastName;
}

Client::~Client() {
	// TODO Auto-generated destructor stub
}
