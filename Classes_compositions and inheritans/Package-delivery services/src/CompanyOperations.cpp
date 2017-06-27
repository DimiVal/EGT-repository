/*
 * CompanyOperations.cpp
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "CompanyOperations.h"

CompanyOperations::CompanyOperations() {
	// TODO Auto-generated constructor stub

}

CompanyOperations::~CompanyOperations() {
	// TODO Auto-generated destructor stub
}

void CompanyOperations::addAddress(Address& address) {
	adr.push_back(address);
}

void CompanyOperations::addPackage(Package& package) {
	pack.push_back(package);
}

void CompanyOperations::addTwoDayPackage(TwoDayPackage& twoDayPackage) {
	twoDayPack.push_back(twoDayPackage);
}

void CompanyOperations::addOvernightPackage(
		OvernightPackage& overnightPackage) {
	overnightPack.push_back(overnightPackage);
}

void CompanyOperations::searchByClientLastName(string lastName) {
	for (unsigned int i = 0; i < pack.size(); i++) {
		if (pack[i].getRes().getLastName() == lastName) {
			pack[i].print();
		}
	}
}

void CompanyOperations::searchByWeight(double weight) {
	for (unsigned int i = 0; i < pack.size(); i++) {
		if (pack[i].getWeight() > weight) {
			cout << "Package is: " << endl;
			pack[i].print();
		}
	}
}

void CompanyOperations::searchByAddressCity(string city) {
	for (unsigned int i = 0; i < pack.size(); i++) {
		if (pack[i].getRes().getAdr().getCity() == city) {
			pack[i].print();
		}
	}
}

void CompanyOperations::searchByClientFullName(string firstName, string lastName) {
	for (unsigned int i = 0; i < pack.size(); i++) {
		if ((pack[i].getSend().getFirstName() == firstName)
				&& (pack[i].getRes().getFirstName() == firstName)
				&& (pack[i].getSend().getLastName() == lastName)
				&& (pack[i].getRes().getLastName() == lastName)) {
			pack[i].print();
		}
	}
}

double CompanyOperations::sumOfCalculateCost(Package&, TwoDayPackage&, OvernightPackage&) {
	double sum = 0;
	for (int i = 0; i < pack.size(); i++) {
		for (int j = 0; j < twoDayPack.size(); j++){
			for (int k = 0; k < overnightPack.size(); k++){
				sum = sum + overnightPack[k].calculateCost();
			}
			sum = sum + twoDayPack[j].calculateCost();
		}
		sum = sum + pack[i].calculateCost();
	}
	return sum;
}

int CompanyOperations::countOfPackage(Package&) {
	int countPack = 0;
	for (int i = 0; i < pack.size(); i++) {
		countPack++;
	}
	return countPack;
}

int CompanyOperations::countOfTwoDayPack(TwoDayPackage&) {
	int countOfTwoDayPack = 0;
	for (int i = 0; i < pack.size(); i++) {
		countOfTwoDayPack++;
	}
	return countOfTwoDayPack;
}

int CompanyOperations::countOvernightPack(OvernightPackage&) {
	int countOvernightPack = 0;
	for (int i = 0; i < pack.size(); i++) {
		countOvernightPack++;
	}
	return countOvernightPack;
}
