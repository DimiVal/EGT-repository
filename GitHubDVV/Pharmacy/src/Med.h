/*
 * Med.h
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef MED_H_
#define MED_H_
#include "Manufacturer.h"
#include <iostream>
#include <string>
using namespace std;

enum Types {NOtype, FreeSale, withBlueRecipe, greenRecipe};
class Med {
public:

	Med();
	Med(string name, double price, int quant, Types type, Manufacturer manuf);
	virtual ~Med();
	void print();

	const Manufacturer& getManuf() const;
	void setManuf(const Manufacturer& manuf);

	const string& getName() const;
	void setName(const string& name);

	double getPrice() const;
	void setPrice(double price);

	int getQuant() const;
	void setQuant(int quant);

	Types getType() const;
	void setType(Types type);

private:
	string name;
	double price;
	int quant;
	Types type;
	Manufacturer manuf;

};

#endif /* MED_H_ */
