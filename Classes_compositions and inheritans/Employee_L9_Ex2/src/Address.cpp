/*
 * Address.cpp
 *
 *  Created on: 20.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Address.h"
#include <iostream>
#include <string>
using namespace std;

Address::~Address() {
	// TODO Auto-generated destructor stub
}

Address::Address() {
	setPostCode(0000);
	setStreet("New street");
	setNumber(000);
	setCity("New city");
	setApartment(00);
}

Address::Address(int postCode, string street, int number, string city, int apartment) {
	setPostCode(postCode);
	setStreet(street);
	setNumber(number);
	setCity(city);
	setApartment(apartment);
}

void Address::print() {
	cout << getPostCode() << " "
	        << getStreet() << " "
			<< getNumber() << " "
			<< getCity() << " "
			<< getApartment() << endl;
}

int Address::getApartment() const {
	return apartment;
}

void Address::setApartment(int apartment) {
	this->apartment = apartment;
}

const string& Address::getCity() const {
	return city;
}

void Address::setCity(const string& city) {
	this->city = city;
}

int Address::getNumber() const {
	return number;
}

void Address::setNumber(int number) {
	this->number = number;
}

const string& Address::getStreet() const {
	return street;
}

void Address::setStreet(const string& street) {
	this->street = street;
}

int Address::getPostCode() const {
	return postCode;
}

void Address::setPostCode(int postCode) {
	this->postCode = postCode;
}
