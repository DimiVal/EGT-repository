/*
 * ManagerInherit.cpp
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "ManagerInherit.h"
#include <iostream>
#include <string>
using namespace std;

ManagerInherit::ManagerInherit():Employee(){
	setYearsOfExperience(0);
}

ManagerInherit::ManagerInherit(string firstName, string lastName,
		string department, int salaryPerHour, int hours, Address& adr,
		int yearsOfExperience)
:Employee(firstName, lastName, department, salaryPerHour, hours, adr)
{
	setYearsOfExperience(yearsOfExperience);
}

void ManagerInherit::print() {
	Employee::print();
	cout << getYearsOfExperience() << endl;
}

int ManagerInherit::calculateSalary() {
	return Employee::calculateSalary();
}

void ManagerInherit::setYearsOfExperience(int yearsOfExperience) {
	this->yearsOfExperience = yearsOfExperience;
}

int ManagerInherit::getYearsOfExperience() const {
	return yearsOfExperience;
}

ManagerInherit::~ManagerInherit() {
	// TODO Auto-generated destructor stub
}
