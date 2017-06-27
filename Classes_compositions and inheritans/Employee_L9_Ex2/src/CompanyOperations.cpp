/*
 * CompanyOperations.cpp
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "CompanyOperations.h"

CompanyOperations::CompanyOperations() {
	// TODO Auto-generated constructor stub

}

CompanyOperations::~CompanyOperations() {
	// TODO Auto-generated destructor stub
}


int CompanyOperations::sumOfSalaries() {
	int sum = 0;
	for(int i = 0; i < staff.size(); i++){
		sum = sum + staff[i].calculateSalary();
	}
	return sum;
}

void CompanyOperations::addEmployee(Employee& empl) {
	staff.push_back(empl);
}

