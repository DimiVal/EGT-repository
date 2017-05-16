/*
 * Box.cpp
 *
 *  Created on: 10.05.2017 г.
 *      Author: Dimitrinka Valkova
 */

#include "Box.h"
#include <iomanip>
#include <iostream>

Box::Box() {
	setLength(0.0);
	setWidth(0.0);
	setHeight(0.0);
	// TODO Auto-generated constructor stub
}

//length, Width, Height
Box::Box(double length, double width, double height) {
	setLength(length);
	setWidth(width);
	setHeight(height);
}

Box::~Box() {
	// TODO Auto-generated destructor stub
}

double Box::getHeight() const {
	return height;
}

void Box::setHeight(double height) {  // verification!!!
	if (this->height < 100 && this->height > 999) {
		this->height = 1;
	}
	this->height = height;
}

double Box::getLength() const {
	return length;
}

void Box::setLength(double length) {  // verification!!!
	if (this->length < 100 && this->length > 999) {
		this->length = 1;
	}
	this->length = length;
}

double Box::getWidth() const {
	return width;
}

void Box::setWidth(double width) {  // verification!!!
	if (this->width < 100 && this->width > 999) {
		this->width = 1;
	}
	this->width = width;
}

Box& Box::operator +(Box& rightPlus) {
	double newLengthPlus = this->length + rightPlus.length;
	double newWidthPlus = this->width + rightPlus.width;
	double newHeightPlus = this->height + rightPlus.height;

	Box *newBPlus = new Box(newLengthPlus, newWidthPlus, newHeightPlus); // динамичен начин
	return *newBPlus;
}

bool Box::operator !=(Box& rightDifferent) {
	if (this->length != rightDifferent.length
			|| this->width != rightDifferent.width
			|| this->height != rightDifferent.height) {
		return true;
	} else {
		return false;
	}
}

/*bool Box::operator ==(Box& rightEcual){
	if (this->length == rightEcual.length
				&& this->width == rightEcual.width
				&& this->height == rightEcual.height) {
			return true;
		} else {
			return false;
		}
	}*/

ostream& operator<<(ostream& output, Box& b) {
	output << "[" << b.getLength() << "-" << b.getWidth() << "-"
			<< b.getHeight() << "]" << endl;
	return output;
}

istream& operator>>(istream& input, Box& b) { // [x-y-z]
	input.ignore(1); // "["
	input >> b.length;
	input.ignore(1); // "-"
	input >> b.width;
	input.ignore(1); // "-"
	input >> b.height;
	input.ignore(1); // "]"
	return input;
}

bool Box::operator >(Box& rightCompare) {
	if (this->length > rightCompare.length ||
			this->width > rightCompare.width ||
			   this->height > rightCompare.height) {
		return true;
	} else {
		return false;
	}
}

void Box::print() {
	cout << getLength() << "-" << getWidth() << "-" << getHeight() << endl;
}

double Box::calculateVolume() {
	return getLength() * getWidth() * getHeight();
}

