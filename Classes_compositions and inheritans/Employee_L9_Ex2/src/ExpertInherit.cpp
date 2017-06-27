/*
 * ExpertInherit.cpp
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "ExpertInherit.h"
#include <iostream>
using namespace std;


ExpertInherit::ExpertInherit()
:Employee(){
	setBonus(0);
}

ExpertInherit::ExpertInherit(string firstName, string lastName,
		string department, int salaryPerHour, int hours, Address& adr, int bonus)
:Employee(firstName, lastName, department, salaryPerHour, hours, adr)
{
	setBonus(bonus);
}

void ExpertInherit::print() {
	Employee::print();
	cout << getBonus();
}

int ExpertInherit::calculateSalary() {
	return Employee::calculateSalary() + getBonus();
}

int ExpertInherit::getBonus() const {
	return bonus;
}

void ExpertInherit::setBonus(int bonus) {
	this->bonus = bonus;
}
