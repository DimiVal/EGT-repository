/*
 * SeniorExpert.h
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef SENIOREXPERT_H_
#define SENIOREXPERT_H_

#include "ExpertInherit.h"

class SeniorExpert: public ExpertInherit {
public:
	SeniorExpert();
	SeniorExpert(string firstName,string lastName,string department,
			int salaryPerHour, int hours, Address& adr, int bonus, string technologies);
	virtual void print();
	virtual int calculateSalary();

	virtual ~SeniorExpert();
	const string& getTechnologies() const;
	void setTechnologies(const string& technologies);

private:
	string technologies;

};

#endif /* SENIOREXPERT_H_ */
