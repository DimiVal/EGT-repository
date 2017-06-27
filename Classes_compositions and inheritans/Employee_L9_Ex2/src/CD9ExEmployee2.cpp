//============================================================================
// Name        : CD9ExEmployee2.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Employee.h"
#include "ManagerInherit.h"
#include "ExpertInherit.h"
#include "SeniorExpert.h"
#include "JExpert.h"
#include "CompanyOperations.h"
#include "Address.h"
#include <vector>
using namespace std;

int main() {

Address adr1(1012, "Nishava", 42, "Sofia", 21);
ManagerInherit mngr1("Lili", "Ivanova", "HR", 12, 160, adr1, 5);

Address adr2(1056, "Odrin", 11, "Sofia", 4);
SeniorExpert sinexp1("Niki", "Petrova", "HR", 19, 120, adr2, 300, "C++");

CompanyOperations co;
co.addEmployee(mngr1);
co.addEmployee(sinexp1);
cout << co.sumOfSalaries();


	return 0;
}
