/*
 * SavingsAccount.h
 *
 *  Created on: 9.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef SAVINGSACCOUNT_H_
#define SAVINGSACCOUNT_H_

#include "Account.h"

class SavingsAccount: public Account {
public:

	SavingsAccount();
	SavingsAccount(double accountBalance, double interestRate);

	virtual ~SavingsAccount();
	virtual void print();

	double getCalculateInterest() const;
	void setCalculateInterest(double calculateInterest);

	double getInterestRate() const;
	void setInterestRate(double interestRate);

	double calculateInterest();

private:
	double interestRate;

};

#endif /* SAVINGSACCOUNT_H_ */
