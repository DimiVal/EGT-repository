/*
 * Account.cpp
 *
 *  Created on: 2.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Account.h"

Account::Account() {
	setAccountBalance(0.0);
}

Account::Account(double accountBalance) {
	if (accountBalance >= 0.0) {
		setAccountBalance(accountBalance);
	} else {
		cout << "The initial balance is invalid!" << endl;
		setAccountBalance(0.0);
	}
}

Account::~Account() {
	// TODO Auto-generated destructor stub
}

double Account::getAccountBalance() const {
	return accountBalance;
}

void Account::setAccountBalance(double accountBalance) {
	this->accountBalance = accountBalance;
}

void Account::print() {
	cout << getAccountBalance() << endl;
}

void Account::credit(double addAmount) {
	accountBalance = accountBalance + addAmount;
}

void Account::debit(double withdrawMoney) {
	if (withdrawMoney < accountBalance) {
		accountBalance = accountBalance - withdrawMoney;
	} else {
		cout << "Debit amount exceeded account balance." << endl;
		getAccountBalance();
	}
}
