//============================================================================
// Name        : C11Ex6.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Account.h"
#include "SavingsAccount.h"
#include "CheckingAccount.h"
#include <iostream>
using namespace std;

int main() {

Account acc1(150.5);
Account acc2(1000.0);

cout << "Balance for Account 1 is: " << acc1.getAccountBalance() << endl;
cout << "Balance for Account 2 is: " << acc2.getAccountBalance() << endl;
cout << endl;

cout << "Account 1 wants to withdraw 200 BGN." << endl;
acc1.debit(200.0);
cout << "Account 2 wants to withdraw 400 BGN." << endl;
acc2.debit(400.0);
cout << endl;

cout << "Balance for Account 1 is: " << acc1.getAccountBalance() << endl;
cout << "Balance for Account 2 is: " << acc2.getAccountBalance() << endl;
cout << endl;

cout << "Account 1 wants to deposit 50 BGN." << endl;
acc1.credit(50.0);
cout << "Account 2 wants to deposit 1000 BGN." << endl;
acc2.credit(1000);
cout << endl;

cout << "Balance for Account 1 is: " << acc1.getAccountBalance() << endl;
cout << "Balance for Account 2 is: " << acc2.getAccountBalance() << endl;



	return 0;
}
