/*
 * Account.h
 *
 *  Created on: 2.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef ACCOUNT_H_
#define ACCOUNT_H_
#include <iostream>
#include <string>
using namespace std;

class Account {
public:

	Account();
	Account(double accountBalance);

	virtual void print();
	virtual ~Account();

	virtual void credit(double addAmount);
	virtual void debit(double withdrawMoney);

	double getAccountBalance() const;
	void setAccountBalance(double accountBalance);

private:
	double accountBalance;

};

#endif /* ACCOUNT_H_ */
