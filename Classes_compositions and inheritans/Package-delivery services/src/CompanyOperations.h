/*
 * CompanyOperations.h
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef COMPANYOPERATIONS_H_
#define COMPANYOPERATIONS_H_
#include "Address.h"
#include "Client.h"
#include "ClientSender.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CompanyOperations {
public:
	CompanyOperations();
	virtual ~CompanyOperations();

	void addAddress(Address&);
	void addPackage(Package&);
	void addTwoDayPackage(TwoDayPackage&);
	void addOvernightPackage(OvernightPackage&);

	void searchByWeight(double);
	void searchByAddressCity(string);
	void searchByClientLastName(string);
	void searchByClientFullName(string, string);

	double sumOfCalculateCost(Package&, TwoDayPackage&, OvernightPackage&);
	int countOfPackage(Package&);
	int countOfTwoDayPack(TwoDayPackage&);
	int countOvernightPack(OvernightPackage&);

private:
	vector<Address> adr;
	vector<Package> pack;
	vector<TwoDayPackage> twoDayPack;
	vector<OvernightPackage> overnightPack;

};

#endif /* COMPANYOPERATIONS_H_ */
