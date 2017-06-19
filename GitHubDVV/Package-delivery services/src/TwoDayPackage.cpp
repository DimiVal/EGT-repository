/*
 * TwoDayPackage.cpp
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "TwoDayPackage.h"

TwoDayPackage::TwoDayPackage() :Package() {
	setTwoDayDeliveryFee(0.0);
}

TwoDayPackage::TwoDayPackage(double weight, double cost, ClientSender& send,
		Client& res, double twoDayDeliveryFee)
:Package(weight, cost, send, res){
	setTwoDayDeliveryFee(twoDayDeliveryFee);
}

void TwoDayPackage::print() {
	Package::print();
	cout << getTwoDayDeliveryFee() << endl;
}

double TwoDayPackage::calculateCost() {
	return Package::calculateCost() + twoDayDeliveryFee;
}

double TwoDayPackage::getTwoDayDeliveryFee() const {
	return twoDayDeliveryFee;
}

void TwoDayPackage::setTwoDayDeliveryFee(double twoDayDeliveryFee) {
	this->twoDayDeliveryFee = twoDayDeliveryFee;
}

TwoDayPackage::~TwoDayPackage() {
	// TODO Auto-generated destructor stub
}
