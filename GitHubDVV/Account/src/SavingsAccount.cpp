/*
 * SavingsAccount.cpp
 *
 *  Created on: 9.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double accountBalance, double interestRate) :
		Account(accountBalance) {
	setInterestRate(interestRate);
}

SavingsAccount::~SavingsAccount() {
	// TODO Auto-generated destructor stub
}

double SavingsAccount::getInterestRate() const {
	return interestRate;
}

void SavingsAccount::setInterestRate(double interestRate) {
	this->interestRate = interestRate;
}

double SavingsAccount::calculateInterest() {
	return getAccountBalance() * getInterestRate();
}

void SavingsAccount::print() {
	Account::print();
	cout << getInterestRate() << endl;
}
