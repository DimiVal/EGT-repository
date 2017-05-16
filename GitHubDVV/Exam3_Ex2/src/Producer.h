/*
 * Producer.h
 *
 *  Created on: 10.05.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#ifndef PRODUCER_H_
#define PRODUCER_H_
#include <iostream>
#include <string>
using namespace std;

class Producer {
public:
	Producer();
	Producer(string firstName, string lastName, string popularity);
	virtual void print();
	virtual ~Producer();

	const string& getFirstName() const;
	void setFirstName(const string& firstName);

	const string& getLastName() const;
	void setLastName(const string& lastName);

	const string& getPopularity() const;
	void setPopularity(const string& popularity);

private:
	string firstName;
	string lastName;
	string popularity;  // rate

};

#endif /* PRODUCER_H_ */
