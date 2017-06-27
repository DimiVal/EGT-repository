/*
 * Employee.h
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */
#include "Address.h"
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
	Employee();
	Employee(string firstName, string lastName,
			string department, int salaryPerHour, int hours, Address& adr);
	virtual ~Employee();
	virtual void print();
	virtual int calculateSalary();

	const string& getDepartment() const;
	void setDepartment(const string& department);
	const string& getFirstName() const;
	void setFirstName(const string& firstName);
	int getHours() const;
	void setHours(int hours);
	const string& getLastName() const;
	void setLastName(const string& lastName);
	int getSalaryPerHour() const;
	void setSalaryPerHour(int salaryPerHour);

private:
	string firstName;
	string lastName;
	string department;
	int salaryPerHour;
	int hours;
	Address adr;

};

#endif /* EMPLOYEE_H_ */
