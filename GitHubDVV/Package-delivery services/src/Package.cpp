/*
 * Package.cpp
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Package.h"
#include <iostream>
#include <string>
using namespace std;

Package::Package() {
	setWeight(0.0);
	setCost(0.0);
}

Package::Package(double weight, double cost, ClientSender& send, Client& res) :
		send(send), res(res) {
	setWeight(weight);
	setCost(cost);
}

void Package::print(){
	cout << getWeight() << " " << getCost() << " " << endl;
	send.print();
	res.print();
}


double Package::getCost() const {
	return cost;
}

void Package::setCost(double cost) { //  Function setCost validates cost.
	this->cost = (cost < 0.0) ? 0.0 : cost;
}

const Client& Package::getRes() const {
	return res;
}

void Package::setRes(const Client& res) {
	this->res = res;
}

const ClientSender& Package::getSend() const {
	return send;
}

void Package::setSend(const ClientSender& send) {
	this->send = send;
}

double Package::getWeight() const {
	return weight;
}

void Package::setWeight(double weight) {  //  Function setWeight validates weight.
	this->weight = (weight < 0.0) ? 0.0 : weight;
}

Package::~Package() {
	// TODO Auto-generated destructor stub
}

double Package::calculateCost() {
	return getWeight() * getCost();
}

