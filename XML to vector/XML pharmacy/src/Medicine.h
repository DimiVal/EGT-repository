/*
 * Medicine.h
 *
 *  Created on: 4.06.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef MEDICINE_H_
#define MEDICINE_H_
#include <string>
#include <iostream>
using namespace std;

class Medicine {
public:
	Medicine();
	Medicine(string name, string type, int quantity, double price);
	virtual ~Medicine();

	void print() const;

	const string& getName() const;
	void setName(const string& name);
	double getPrice() const;
	void setPrice(double price);
	int getQuantity() const;
	void setQuantity(int quantity);
	const string& getType() const;
	void setType(const string& type);

private:
	string name;
	string type;
	int quantity;
	double price;
};

#endif /* MEDICINE_H_ */
