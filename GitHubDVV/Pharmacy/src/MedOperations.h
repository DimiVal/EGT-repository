/*
 * MedOperations.h
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef MEDOPERATIONS_H_
#define MEDOPERATIONS_H_
#include "Manufacturer.h"
#include "Med.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MedOperations {
public:
	MedOperations();
	virtual ~MedOperations();

	void addMedicine(Med&);
	void searchByName(string, string);
	void searchByPrice(double);
	void searchByType(Types);

private:
	vector<Med> pharm;

};

#endif /* MEDOPERATIONS_H_ */
