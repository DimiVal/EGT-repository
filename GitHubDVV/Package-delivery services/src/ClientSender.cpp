/*
 * ClientSender.cpp
 *
 *  Created on: 2.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "ClientSender.h"

ClientSender::ClientSender() {
		setNameOfCompany("N/A");
		setVatNumber(0);
		setCityC("N/A");
		setStreetC("N/A");
		setNumberC(0);
}

ClientSender::~ClientSender() {
	// TODO Auto-generated destructor stub
}

const string& ClientSender::getCityC() const {
	return cityC;
}

void ClientSender::setCityC(const string& cityC) {
	this->cityC = cityC;
}

const string& ClientSender::getNameOfCompany() const {
	return nameOfCompany;
}

void ClientSender::setNameOfCompany(const string& nameOfCompany) {
	this->nameOfCompany = nameOfCompany;
}

int ClientSender::getNumberC() const {
	return numberC;
}

void ClientSender::setNumberC(int numberC) {
	this->numberC = numberC;
}

const string& ClientSender::getStreetC() const {
	return streetC;
}

void ClientSender::setStreetC(const string& streetC) {
	this->streetC = streetC;
}

int ClientSender::getVatNumber() const {
	return vatNumber;
}

ClientSender::ClientSender(string firstName, string lastName, Address& adr,
		string nameOfCompany, int vatNumber, string cityC, string streetC,
		int numberC)
: Client(firstName, lastName, adr){
	setNameOfCompany(nameOfCompany);
	setVatNumber(vatNumber);
	setCityC(cityC);
	setStreetC(streetC);
	setNumberC(numberC);
}

void ClientSender::print() {
	Client::print();
	cout << getNameOfCompany() << " "
			<< getVatNumber() << " "
			<< getCityC() << " "
			<< getStreetC() << " "
			<< getNumberC() << endl;
}

void ClientSender::setVatNumber(int vatNumber) {
	this->vatNumber = vatNumber;
}


/*void ClientSender::invoice() {

}
*/
