/*
 * Film.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "Film.h"
// (string filmName, int numID, bool forAdults, Producer& prod,
//types type)
Film::Film() {
	// TODO Auto-generated constructor stub
	setFilmName("N/A");
	setNumId(0);
	setForAdults("no");
	setType(NOtype);
}

Film::~Film() {
	// TODO Auto-generated destructor stub
}

const string& Film::getFilmName() const {
	return filmName;
}

void Film::setFilmName(const string& filmName) {
	this->filmName = filmName;
}

bool Film::isForAdults() const {
	return forAdults;
}

void Film::setForAdults(bool forAdults) {
	this->forAdults = forAdults;
}

int Film::getNumId() const {
	return numId;
}

void Film::setNumId(int numId) {
	this->numId = numId;
}

const Producer& Film::getProd() const {
	return prod;
}

void Film::setProd(const Producer& prod) {
	this->prod = prod;
}

// Comedy, Action, Drama, Thriller, Documentary
string Film::typePr() {
	string res;
	switch (Film::type) {
	case NOtype:
		res = "NOtype";
		break;
	case Comedy:
		res = "Comedy";
		break;
	case Action:
		res = "Action";
		break;
	case Drama:
		res = "Drama";
		break;
	case Thriller:
		res = "Thriller";
		break;
	case Documentary:
		res = "Documentary";
		break;
	default:
		cout << "Error" << endl;

	}
	return res;
}

Film::types Film::getType() const {
	return type;
}

void Film::setType(types type) {
	this->type = type;
}

Film::Film(string filmName, int numId, bool forAdults, Producer& prod,
		types type) :
		prod(prod) {
	setFilmName(filmName);
	setNumId(numId);
	setForAdults(forAdults);
	setType(type);

}

void Film::print() {
	cout << getFilmName() << " " << getNumId()
			<< " " << getType() << endl;
	prod.print();
}


