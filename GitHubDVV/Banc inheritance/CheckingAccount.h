/*
 * CheckingAccount.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef CHECKINGACCOUNT_H_
#define CHECKINGACCOUNT_H_

#include "Account.h"

class CheckingAccount: public Account {
public:

	CheckingAccount();
	CheckingAccount(double accountBalance, double fee);

	virtual ~CheckingAccount();
	virtual void print();

	virtual void credit(double addAmount);
	virtual void debit(double withdrawMoney);

	double getFee() const;
	void setFee(double fee);

private:
	double fee;
};

#endif /* CHECKINGACCOUNT_H_ */
