/*
 * FilmOperations.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef FILMOPERATIONS_H_
#define FILMOPERATIONS_H_
#include "Producer.h"
#include "Film.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class FilmOperations {
public:

	FilmOperations();
	virtual ~FilmOperations();
	void print();

	void addProducer(Producer&);
	void addFilm(Film&);

	void searchByFilmName(string);
	void searchById(int);
	void searchByGenre(Film::types);
	void searchByIsForAdults(bool);
	int countOfFilm(Film&);

	const vector<Film>& getFil() const;
	void setFil(const vector<Film>& fil);
	const vector<Producer>& getProd() const;
	void setProd(const vector<Producer>& prod);

private:
	vector<Producer> prod;
	vector<Film> fil;
	vector<Film*> otherFilms;

	// Producer pr1("Ivan", "Ivanov", "Famous");
	// Producer pr2("John", "Smith", "New producer");
	// Producer pr3("Jan", "Milosh", "Very famous");

};

#endif /* FILMOPERATIONS_H_ */
