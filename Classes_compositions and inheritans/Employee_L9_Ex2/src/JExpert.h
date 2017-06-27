/*
 * JExpert.h
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef JEXPERT_H_
#define JEXPERT_H_

#include "ExpertInherit.h"

class JExpert: public ExpertInherit {
public:
	JExpert();
	JExpert(string firstName,string lastName,string department,
			int salaryPerHour, int hours, Address& adr, int bonus,
			string technologies, string degree, int opinion);
	virtual void print();
	virtual int calculateSalary();

	virtual ~JExpert();
	const string& getDegree() const;
	void setDegree(const string& degree);
	int getOpinion() const;
	void setOpinion(int opinion);

private:
	string degree;
	int opinion;
};

#endif /* JEXPERT_H_ */
