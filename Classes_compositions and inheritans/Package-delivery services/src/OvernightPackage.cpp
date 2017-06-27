/*
 * OvernightPackage.cpp
 *
 *  Created on: 29.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "OvernightPackage.h"


OvernightPackage::OvernightPackage()
:Package() {
	setOvernightFeePerOunce(0);
}

OvernightPackage::OvernightPackage(double weight, double cost, ClientSender& send,
		Client& res, double overnightFeePerOunce)
:Package(weight, cost, send, res){
	setOvernightFeePerOunce(overnightFeePerOunce);
}

void OvernightPackage::print() {
	Package::print();
	cout << getOvernightFeePerOunce() << endl;
}

double OvernightPackage::calculateCost() {
	return getWeight() * (getCost() + getOvernightFeePerOunce());
}

OvernightPackage::~OvernightPackage() {
	// TODO Auto-generated destructor stub
}

double OvernightPackage::getOvernightFeePerOunce() const {
	return overnightFeePerOunce;
}

void OvernightPackage::setOvernightFeePerOunce(double overnightFeePerOunce) {
	this->overnightFeePerOunce = overnightFeePerOunce;
}
