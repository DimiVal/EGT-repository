/*
 * SeniorExpert.cpp
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "SeniorExpert.h"
#include <iostream>
using namespace std;

SeniorExpert::SeniorExpert() :
		ExpertInherit() {
	setTechnologies("n/a");
}

SeniorExpert::SeniorExpert(string firstName, string lastName, string department,
		int salaryPerHour, int hours, Address& adr, int bonus,
		string technologies) :
		ExpertInherit(firstName, lastName, department, salaryPerHour, hours,
				adr, bonus) {
	setTechnologies(technologies);
}

int SeniorExpert::calculateSalary() {
	return ExpertInherit::calculateSalary() + getBonus();
}

void SeniorExpert::print() {
	ExpertInherit::print();
	cout << getTechnologies() << endl;
}

const string& SeniorExpert::getTechnologies() const {
	return technologies;
}

void SeniorExpert::setTechnologies(const string& technologies) {
	this->technologies = technologies;
}

SeniorExpert::~SeniorExpert() {
	// TODO Auto-generated destructor stub
}
