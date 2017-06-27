/*
 * CompanyOperations.h
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef COMPANYOPERATIONS_H_
#define COMPANYOPERATIONS_H_
#include <vector>
#include "ManagerInherit.h"
#include "ExpertInherit.h"
#include "SeniorExpert.h"
#include "JExpert.h"
#include "CompanyOperations.h"
#include "Address.h"

class CompanyOperations {

public:
	CompanyOperations();
	virtual ~CompanyOperations();

	int sumOfSalaries();
	void addEmployee(Employee& staff);

	const vector<Employee>& getStaff() const;
	void setStaff(const vector<Employee>& staff);

private:
	vector<Employee> staff;

};

#endif /* COMPANYOPERATIONS_H_ */
