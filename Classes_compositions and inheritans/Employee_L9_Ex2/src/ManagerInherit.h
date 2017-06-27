/*
 * ManagerInherit.h
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef MANAGERINHERIT_H_
#define MANAGERINHERIT_H_

#include "Employee.h"
#include <iostream>
#include <string>
using namespace std;

class ManagerInherit: public Employee {

public:
	ManagerInherit();
	ManagerInherit(string firstName, string lastName, string department,
			int salaryPerHour, int hours, Address& adr, int yearsOfExperience);
	virtual void print();
	virtual int calculateSalary();

	virtual ~ManagerInherit();
	int getYearsOfExperience() const;
	void setYearsOfExperience(int yearsOfExperience);

private:
	int yearsOfExperience;

};

#endif /* MANAGERINHERIT_H_ */
