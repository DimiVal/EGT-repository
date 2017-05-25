/*
 * Med.cpp
 *
 *  Created on: 19.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Med.h"

Med::Med() {
	setName("n/a");
	setPrice(0.0);
	setQuant(0);
	setType(NOtype);
}


Med::Med(string name, double price, int quant, Types type, Manufacturer manuf)
:manuf(manuf){
	setName(name);
	setPrice(price);
	setQuant(quant);
	setType(type);
}

void Med::print() {
	cout << "Name is:" << getName() << " Price:" << getPrice() <<
			" Q-ty" << getQuant() << " Type:" << getType() << endl;
	manuf.print();
}

Med::~Med() {
	// TODO Auto-generated destructor stub
}

const Manufacturer& Med::getManuf() const {
	return manuf;
}

void Med::setManuf(const Manufacturer& manuf) {
	this->manuf = manuf;
}

const string& Med::getName() const {
	return name;
}

void Med::setName(const string& name) {
	this->name = name;
}

double Med::getPrice() const {
	return price;
}

void Med::setPrice(double price) {
	this->price = price;
}

int Med::getQuant() const {
	return quant;
}

void Med::setQuant(int quant) {
	this->quant = quant;
}

Types Med::getType() const {
	return type;
}

void Med::setType(Types type) {
	this->type = type;
}
