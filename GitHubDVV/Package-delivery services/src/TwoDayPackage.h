/*
 * TwoDayPackage.h
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef TWODAYPACKAGE_H_
#define TWODAYPACKAGE_H_

#include "Package.h"
#include <iostream>
#include <string>
using namespace std;

class TwoDayPackage: public Package {
public:
	TwoDayPackage();
	TwoDayPackage(double weight, double cost,
			ClientSender& send, Client& res, double twoDayDeliveryFee);
	virtual ~TwoDayPackage();

	virtual void print();
	virtual double calculateCost();
	double getTwoDayDeliveryFee() const;
	void setTwoDayDeliveryFee(double twoDayDeliveryFee);

private:
	double twoDayDeliveryFee;
};

#endif /* TWODAYPACKAGE_H_ */
