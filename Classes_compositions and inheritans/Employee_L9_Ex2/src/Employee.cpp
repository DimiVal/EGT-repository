/*
 * Employee.cpp
 *
 *  Created on: 22.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */
#include "Address.h"
#include "Employee.h"
#include <iostream>
using namespace std;

Employee::Employee() :adr(0, " ", 0, " ", 0) {
	setFirstName("New first name");
	setLastName("New last name");
	setDepartment("New department");
	setSalaryPerHour(000);
	setHours(00);
}

Employee::Employee(string firstName, string lastName, string department,
		int salaryPerHour, int hours, Address& adr) :
		adr(adr) {
	setFirstName(firstName);
	setLastName(lastName);
	setDepartment(department);
	setSalaryPerHour(salaryPerHour);
	setHours(hours);
}

void Employee::print() {
	cout << getFirstName() << " " << getLastName() << " " << getDepartment()
			<< " " << getSalaryPerHour() << " " << getHours() << endl;
	adr.print();

}

int Employee::calculateSalary() {
	return getSalaryPerHour() * getHours();
}

void Employee::setSalaryPerHour(int salaryPerHour) {
	this->salaryPerHour = salaryPerHour;
}

const string& Employee::getDepartment() const {
	return department;
}

void Employee::setDepartment(const string& department) {
	this->department = department;
}

const string& Employee::getFirstName() const {
	return firstName;
}

void Employee::setFirstName(const string& firstName) {
	this->firstName = firstName;
}

int Employee::getHours() const {
	return hours;
}

void Employee::setHours(int hours) {
	this->hours = hours;
}

const string& Employee::getLastName() const {
	return lastName;
}

void Employee::setLastName(const string& lastName) {
	this->lastName = lastName;
}

int Employee::getSalaryPerHour() const {
	return salaryPerHour;
}

Employee::~Employee() {
	// TODO Auto-generated destructor stub
}
