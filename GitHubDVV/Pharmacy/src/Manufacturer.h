/*
 * Manufacturer.h
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef MANUFACTURER_H_
#define MANUFACTURER_H_
#include <iostream>
#include <string>
using namespace std;

class Manufacturer {
public:
	Manufacturer();
	Manufacturer(string nameMan, int code, string country);
	virtual ~Manufacturer();
	void print();

	int getCode() const;
	void setCode(int code);

	const string& getCountry() const;
	void setCountry(const string& country);

	const string& getNameMan() const;
	void setNameMan(const string& nameMan);

private:
	string nameMan;
	int code;
	string country;

};

#endif /* MANUFACTURER_H_ */
