/*
 * JExpert.cpp
 *
 *  Created on: 24.04.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "JExpert.h"
/*
JExpert::JExpert() :
ExpertInherit(){
	setDegree(" ");
	setOpinion(0);
}

JExpert::JExpert(string firstName,string lastName,string department,
		int salaryPerHour, int hours, Address& adr, int bonus,
		string technologies, string degree, int opinion) :
		ExpertInherit(firstName, lastName, department, salaryPerHour, hours,
				adr, bonus, technologies) {
	setDegree(degree);
	setOpinion(opinion);
}*/

void JExpert::print() {
	ExpertInherit::print();
	cout << "The degree is:" << getDegree() << " Opinion:" << getOpinion() << endl;
}

int JExpert::calculateSalary() {
	return ExpertInherit::calculateSalary() + getBonus();
}

const string& JExpert::getDegree() const {
	return degree;
}

void JExpert::setDegree(const string& degree) {
	this->degree = degree;
}

int JExpert::getOpinion() const {
	return opinion;
}

void JExpert::setOpinion(int opinion) {
	this->opinion = opinion;
}

JExpert::~JExpert() {
	// TODO Auto-generated destructor stub
}

