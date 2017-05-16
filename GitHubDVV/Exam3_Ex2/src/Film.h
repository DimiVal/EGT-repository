/*
 * Film.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef FILM_H_
#define FILM_H_
#include "Producer.h"
#include <iostream>
#include <string>
using namespace std;

class Film {

public:
	enum types {NOtype, Comedy, Action,
		Drama, Thriller, Documentary};

	Film();
	Film(string filmName, int numId, bool forAdults, Producer& prod,
			types type);
	virtual void print();
	virtual ~Film();
	string typePr();
	const string& getFilmName() const;
	void setFilmName(const string& filmName);

	bool isForAdults() const;
	void setForAdults(bool forAdults);

	int getNumId() const;
	void setNumId(int numId);

	const Producer& getProd() const;
	void setProd(const Producer& prod);

	types getType() const;
	void setType(types type);
	int numId;

private:
	string filmName;

	bool forAdults;
	Producer prod;
	types type;
};

#endif /* FILM_H_ */
