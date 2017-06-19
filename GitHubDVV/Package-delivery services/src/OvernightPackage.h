/*
 * OvernightPackage.h
 *
 *  Created on: 29.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef OVERNIGHTPACKAGE_H_
#define OVERNIGHTPACKAGE_H_

#include "Package.h"
#include <iostream>
#include <string>
using namespace std;

class OvernightPackage: public Package {
public:
	OvernightPackage();
	OvernightPackage(double weight, double cost,
			ClientSender& send, Client& res, double overnightFeePerOunce);
	virtual void print();
	virtual double calculateCost();
	virtual ~OvernightPackage();
	double getOvernightFeePerOunce() const;
	void setOvernightFeePerOunce(double overnightFeePerOunce);

private:
	double overnightFeePerOunce;
};

#endif /* OVERNIGHTPACKAGE_H_ */
