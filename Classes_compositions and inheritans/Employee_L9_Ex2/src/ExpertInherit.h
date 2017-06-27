/*
 * ExpertInherit.h
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef EXPERTINHERIT_H_
#define EXPERTINHERIT_H_

#include "Employee.h"

class ExpertInherit: public Employee {
public:
	ExpertInherit();
	ExpertInherit(string firstName,string lastName,string department,
			int salaryPerHour, int hours, Address& adr, int bonus);
	virtual void print();
	virtual int calculateSalary();

	virtual ~ExpertInherit();
	int getBonus() const;
	void setBonus(int bonus);

private:
	int bonus;

};

#endif /* EXPERTINHERIT_H_ */
