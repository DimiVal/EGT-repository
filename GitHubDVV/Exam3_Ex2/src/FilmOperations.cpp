/*
 * FilmOperations.cpp
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "FilmOperations.h"

FilmOperations::FilmOperations() {
	// TODO Auto-generated constructor stub

}

FilmOperations::~FilmOperations() {
	// TODO Auto-generated destructor stub
}

void FilmOperations::addProducer(Producer& producer) {
	prod.push_back(producer);
}

void FilmOperations::addFilm(Film& film) {
	bool verify = false;
	for (unsigned int i = 0; i < fil.size(); i++){
		if (fil[i].getNumId() == film.numId){
			cout << "There is such a film already in the video! " << endl;
			verify = true;
		}
	}
	if(verify == false){
		fil.push_back(film);
	}
}

void FilmOperations::searchByFilmName(string filmName) {
	for (unsigned int i = 0; i < fil.size(); i++){
		if (fil[i].getFilmName() == filmName){
			fil[i].print();
		}
	}
}

void FilmOperations::searchById(int numId) {
	for (unsigned int i = 0; i < fil.size(); i++){
		if (fil[i].getNumId() == numId){
			return;
		}
	}
}

int FilmOperations::countOfFilm(Film&) {
	int countFilm = 0;
	for (unsigned int i = 0; i < fil.size(); i++){
		countFilm++;
	}
	return countFilm;
}

void FilmOperations::searchByGenre(Film::types searchGenre) {
	int countGenre = 0;
	for (unsigned int i = 0; i < fil.size(); i++){
		if (fil[i].getType() == searchGenre){
			countGenre = countGenre + 1;
		}
	}
	cout << "Film/s with " << searchGenre <<
			" genre is/are: " << countGenre << endl;
}

const vector<Film>& FilmOperations::getFil() const {
	return fil;
}

void FilmOperations::setFil(const vector<Film>& fil) {
	this->fil = fil;
}

const vector<Producer>& FilmOperations::getProd() const {
	return prod;
}

void FilmOperations::setProd(const vector<Producer>& prod) {
	this->prod = prod;
}

/*void FilmOperations::print() {
    cout << getFil() << endl;
}*/

void FilmOperations::searchByIsForAdults(bool isForAdults) {
	int countForAdults = 0;
	for (unsigned int i = 0; i < fil.size(); i++){
		if (fil[i].isForAdults() == isForAdults){
			countForAdults = countForAdults + 1;
		}
	}
	cout << "Films for adults are: " << isForAdults << endl;
}

/*void statistics(){
	int countJanr1 = 0;
	int countJanr2 = 0;
	int countJanr3 = 0;
	int countJanr4 = 0;

	for (unsigned int i = 0; i < fil.size(); i++){
		if()

	}

}*/
