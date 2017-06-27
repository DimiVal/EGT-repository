/*
 * CheckingAccount.cpp
 *
 *  Created on: 9.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double accountBalance, double fee)
:Account(accountBalance){
	setFee(0.8);
}

CheckingAccount::~CheckingAccount() {
	// TODO Auto-generated destructor stub
}

double CheckingAccount::getFee() const {
	return fee;
}

void CheckingAccount::setFee(double fee) {
	this->fee = fee;
}

void CheckingAccount::print() {
	Account::print();
	cout << getFee() << endl;
}

void CheckingAccount::credit(double addAmount){
	Account::credit(addAmount - fee);
}

void CheckingAccount::debit(double withdrawMoney){
	Account::debit(withdrawMoney - fee);
}
