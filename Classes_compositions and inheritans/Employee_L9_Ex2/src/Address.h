/*
 * Address.h
 *
 *  Created on: 20.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <iostream>
#include <string>
using namespace std;

class Address {
public:
	Address();
	Address(int postCode, string street, int number, string city, int apartment);
	void print();

	virtual ~Address();
	int getApartment() const;
	void setApartment(int apartment);
	const string& getCity() const;
	void setCity(const string& entrance);
	int getNumber() const;
	void setNumber(int number);
	const string& getStreet() const;
	void setStreet(const string& street);
	int getPostCode() const;
	void setPostCode(int postCode);

private:
	int postCode;
	string street;
	int number;
	string city;
	int apartment;

};

#endif /* ADDRESS_H_ */
