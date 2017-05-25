/*
 * MedOperations.cpp
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "MedOperations.h"

MedOperations::MedOperations() {
	// TODO Auto-generated constructor stub

}

MedOperations::~MedOperations() {
	// TODO Auto-generated destructor stub
}

void MedOperations::addMedicine(Med& meds) {
	pharm.push_back(meds);
}

void MedOperations::searchByName(string medName, string manufName) {
	for (unsigned int i = 0; i < pharm.size(); i++) {
		if (pharm[i].getName() == medName
				&& pharm[i].getManuf().getNameMan() == manufName) {
			pharm[i].print();
		}
	}
}

void MedOperations::searchByPrice(double medPrice) {
	for (unsigned int i = 0; i < pharm.size(); i++) {
		if (pharm[i].getPrice() == medPrice) {
			pharm[i].getPrice();
		}
	}
	cout << "The price is: " << medPrice << endl;
}

void MedOperations::searchByType(Types typesss) {
	for (unsigned int i = 0; i < pharm.size(); i++) {
		if (pharm[i].getType() == typesss) {
			pharm[i].print();
		}
	}
}
