//============================================================================
// Name        : Exam3Ex2_1005.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "Producer.h"
#include "Film.h"
#include "FilmOperations.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

Producer pr1("Ivan", "Ivanov", "Famous");
Producer pr2("John", "Smith", "New producer");
Producer pr3("Jan", "Milosh", "Very famous");

Film f1("Summer", 1020, true, pr1, Film::Documentary);
Film f2("Jump", 2096, false, pr2, Film::Action);
Film f3("Woman", 1480, true, pr1, Film::Drama);
Film f4("Lost", 2108, false, pr3, Film::Action);

FilmOperations filmOp;





filmOp.addFilm(f1);
filmOp.addFilm(f2);
filmOp.addFilm(f3);
filmOp.addFilm(f4);

filmOp.searchByFilmName("Jump");
filmOp.searchById(1480);
filmOp.searchByGenre(Film::Action);
filmOp.searchByIsForAdults(true);
//filmOp.countOfFilm();
cout << endl;

	return 0;
}
