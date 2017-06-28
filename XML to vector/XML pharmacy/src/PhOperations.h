/*
 * PhOperations.h
 *
 *  Created on: 4.06.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef PHOPERATIONS_H_
#define PHOPERATIONS_H_
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <fstream>
#include <iomanip>
using namespace std;
#include "pugixml.hpp"
#include "Medicine.h"

class PhOperations {
public:
	PhOperations();
	virtual ~PhOperations();

	void addFirstPharmacyInVector();
	void printFirstPharmacy();
	void salesFirstPharmacy();

	void addSecondPharmacyInVector();
	void printSecondPharmacy();
	void salesSecondPharmacy();

	void addThirdPharmacyInVector();
	void printThirdPharmacy();
	void salesThirdPharmacy();

	void salesAllPharmacy();

	void searchByName(string);
	void searchByType(string);
	void searchByPrice(double);
	void searchQuantityPills(int);

	double calculatePillPrice();

	void mostExpensivePills();
	void cheapestPills();

	double totalCalcPriceInPharmacy();


private:
	vector<Medicine*> med1;
	vector<Medicine*> med2;
	vector<Medicine*> med3;

};

#endif /* PHOPERATIONS_H_ */
