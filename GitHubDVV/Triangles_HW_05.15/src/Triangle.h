/*
 * Triangle.h
 *
 *  Created on: 15.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef TRIANGLE_H_
#define TRIANGLE_H_
#include <iostream>
using namespace std;

class Triangle {

	friend ostream& operator<<(ostream& output, const Triangle& rightTr);
	friend istream& operator>>(istream& input, Triangle& rightTr);

public:
	Triangle();
	Triangle(double, double, double, double);
	virtual ~Triangle();

	bool operator==(Triangle&);
	bool operator!=(Triangle&);

	double getA() const;
	void setA(double a);
	double getB() const;
	void setB(double b);
	double getC() const;
	void setC(double c);
	double getH() const;
	void setH(double h);

private:
	double a;
	double b;
	double c;
	double h;

};

#endif /* TRIANGLE_H_ */
