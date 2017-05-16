/*
 * Box.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef BOX_H_
#define BOX_H_
#include <iostream>
#include <string>
using namespace std;

class Box {

	friend ostream& operator<<(ostream& output, const Box& b);
	friend istream& operator>>(istream& input, Box& b);

public:
	Box();
	Box(double lenght, double width, double height);

	Box& operator + (Box&);
	bool operator > (Box&);
	bool operator != (Box&);
	bool operator == (Box&);

	void print();
	virtual ~Box();

	double calculateVolume();

	double getHeight() const;
	void setHeight(double height);

	double getLength() const;
	void setLength(double length);

	double getWidth() const;
	void setWidth(double width);

private:
	//length, Width, Height
	double length;
	double width;
	double height;

};

#endif /* BOX_H_ */
