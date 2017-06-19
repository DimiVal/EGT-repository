/*
 * ClientSender.h
 *
 *  Created on: 2.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef CLIENTSENDER_H_
#define CLIENTSENDER_H_

#include <iostream>
#include <string>
using namespace std;

#include "Client.h"

class ClientSender: public Client {
public:
	ClientSender();
	ClientSender(string, string, Address& adr, string, int, string, string, int);
	virtual void print();
	void invoice();
	virtual ~ClientSender();
	const string& getCityC() const;
	void setCityC(const string& cityC);
	const string& getNameOfCompany() const;
	void setNameOfCompany(const string& nameOfCompany);
	int getNumberC() const;
	void setNumberC(int numberC);
	const string& getStreetC() const;
	void setStreetC(const string& streetC);
	int getVatNumber() const;
	void setVatNumber(int vatNumber);

private:
	string nameOfCompany;
	int vatNumber;
	string cityC;
	string streetC;
	int numberC;

};

#endif /* CLIENTSENDER_H_ */
