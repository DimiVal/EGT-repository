/*
 * Client.h
 *
 *  Created on: 28.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include "Address.h"
#include <iostream>
#include <string>
using namespace std;

class Client {
public:
	Client();
	Client(string, string, Address& adr);
	virtual void print();

	virtual ~Client();
	const Address& getAdr() const;
	void setAdr(const Address& adr);
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	const string& getLastName() const;
	void setLastName(const string& lastName);

private:
	string firstName;
	string lastName;
	Address adr;

};

#endif /* CLIENT_H_ */
