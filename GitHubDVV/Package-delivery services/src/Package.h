/*
 * Package.h
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef PACKAGE_H_
#define PACKAGE_H_
#include "Client.h"
#include "ClientSender.h"
#include <iostream>
#include <string>
using namespace std;

class Package {
public:
	Package();
	Package(double weight, double cost, ClientSender& send, Client& res);
	virtual void print();
	virtual double calculateCost();

	virtual ~Package();
	double getCost() const;
	void setCost(double cost);
	const Client& getRes() const;
	void setRes(const Client& res);
	const ClientSender& getSend() const;
	void setSend(const ClientSender& send);
	double getWeight() const;
	void setWeight(double weight);

private:
	double weight;
	double cost;
	ClientSender send;
	Client res;
};

#endif /* PACKAGE_H_ */
