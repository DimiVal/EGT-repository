/*
 * Triangle.cpp
 *
 *  Created on: 15.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Triangle.h"

Triangle::Triangle() {
	setA(0.0);
	setB(0.0);
	setC(0.0);
	setH(0.0);
}

Triangle::Triangle(double a, double b, double c, double h) {
	setA(a);
	setB(b);
	setC(c);
	setH(h);
}

istream& operator>>(istream& input, Triangle& rightTr){  // -a-b-c-h
	input.ignore(1); // "-"
	input >> rightTr.a;
	input.ignore(1); // "-"
	input >> rightTr.b;
	input.ignore(1); // "-"
	input >> rightTr.c;
	input.ignore(1); // "-"
	input >> rightTr.h;
	return input;
}

ostream& operator<<(ostream& output, Triangle& rightTr){  // =>a,b,c,h
	output << "=>" << rightTr.getA() << "," << rightTr.getB() << ","
			<< rightTr.getC() << "," << rightTr.getH() << endl;
	return output;
}

bool Triangle::operator==(Triangle& rEqual) {
	if ((this->a == rEqual.a) &&
			(this->b == rEqual.b) &&
			(this->c == rEqual.c) &&
			(this->h == rEqual.h)) {
		cout << "The triangles are equals. (za ==)" << endl;
		return true;
	} else {
		cout << "The triangles are not equals. (za ==)" << endl;
		return false;
	}
}

bool Triangle::operator!=(Triangle& rDifferent) {
	if (this->a != rDifferent.a
			|| this->b != rDifferent.b
			|| this->c != rDifferent.c
			|| this->h != rDifferent.h){
		cout << "The triangles are different. (za !=)" << endl;
		return true;
	}else{
		cout << "The triangles are not different. (za !=)" << endl;
		return false;
	}
}

Triangle::~Triangle() {
	// TODO Auto-generated destructor stub
}

double Triangle::getA() const {
	return a;
}

void Triangle::setA(double a) {
	this->a = a;
}

double Triangle::getB() const {
	return b;
}

void Triangle::setB(double b) {
	this->b = b;
}

double Triangle::getC() const {
	return c;
}

void Triangle::setC(double c) {
	this->c = c;
}

double Triangle::getH() const {
	return h;
}

void Triangle::setH(double h) {
	this->h = h;
}
