/*
 * PhOperations.cpp
 *
 *  Created on: 4.06.2017 ã.
 *      Author: Dimitrinka Valkova
 */

#include "PhOperations.h"

#include <map>

using namespace std;

PhOperations::PhOperations() {
	// TODO Auto-generated constructor stub
}

PhOperations::~PhOperations() {
	// TODO Auto-generated destructor stub
}

void PhOperations::addFirstPharmacyInVector() {

	pugi::xml_document doc;

	if (!doc.load_file("PharmacyXML1.xml")) {

		cerr << "The file could not be read !" << endl;
		exit(1);
	} else {
		cout << "The file is readed succesfully!" << endl;
	}
	pugi::xml_node pharmacy = doc.child("Pharmacy");

	for (pugi::xml_node article = pharmacy.first_child(); article; article =
			article.next_sibling()) {

		string name = article.child("name").text().as_string();
		string type = article.child("type").text().as_string();
		int quantity = article.child("quantity").text().as_int();
		double price = article.child("price").text().as_double();

		Medicine *newObj = new Medicine(name, type, quantity, price);

		med1.push_back(newObj);
	}
	if (med1.size() != 0) {
		cout << "Vector is ready !" << endl;
	} else {
		cout << "Vector is not ready!" << endl;
	}
}

void PhOperations::printFirstPharmacy() {
	cout << " First Pharmacy " << endl;
	for (unsigned int i = 0; i < med1.size(); i++) {
		med1[i]->print();
		cout << " ************ " << endl;
	}
}

void PhOperations::salesFirstPharmacy() {
}

void PhOperations::addSecondPharmacyInVector() {
	pugi::xml_document doc;

	if (!doc.load_file("PharmacyXML2.xml")) {

		cerr << "The file could not be read !" << endl;
		exit(1);
	} else {
		cout << "The file is readed succesfully!" << endl;
	}
	pugi::xml_node pharmacy = doc.child("Pharmacy");

	for (pugi::xml_node article = pharmacy.first_child(); article; article =
			article.next_sibling()) {

		string name = article.child("name").text().as_string();
		string type = article.child("type").text().as_string();
		int quantity = article.child("quantity").text().as_int();
		double price = article.child("price").text().as_double();

		Medicine *newObj = new Medicine(name, type, quantity, price);

		med2.push_back(newObj);
	}
	if (med2.size() != 0) {
		cout << "Vector is ready!" << endl;
	} else {
		cout << "Vector is not ready!" << endl;
	}
}

void PhOperations::printSecondPharmacy() {
	cout << " Second Pharmacy " << endl;
	for (unsigned int i = 0; i < med2.size(); i++) {
		med2[i]->print();
		cout << " ************ " << endl;
	}
}

void PhOperations::salesSecondPharmacy() {
}

void PhOperations::addThirdPharmacyInVector() {
	pugi::xml_document doc;

	if (!doc.load_file("PharmacyXML3.xml")) {

		cerr << "The file could not be read !" << endl;
		exit(1);
	} else {
		cout << "The file is readed succesfully!" << endl;
	}
	pugi::xml_node pharmacy = doc.child("Pharmacy");

	for (pugi::xml_node article = pharmacy.first_child(); article; article =
			article.next_sibling()) {

		string name = article.child("name").text().as_string();
		string type = article.child("type").text().as_string();
		int quantity = article.child("quantity").text().as_int();
		double price = article.child("price").text().as_double();

		Medicine *newObj = new Medicine(name, type, quantity, price);

		med3.push_back(newObj);
	}
	if (med3.size() != 0) {
		cout << "Vector is ready!" << endl;
	} else {
		cout << "Vector is not ready!" << endl;
	}
}

void PhOperations::printThirdPharmacy() {
	cout << " Third Pharmacy " << endl;
	for (unsigned int i = 0; i < med3.size(); i++) {
		med3[i]->print();
		cout << " ************ " << endl;
	}
}

void PhOperations::salesThirdPharmacy() {
}

void PhOperations::salesAllPharmacy() {

}

void PhOperations::searchByName(string pillsName) {

	for (unsigned int i = 0; i < med1.size(); i++) {
		if (med1[i]->getName() == pillsName) {
			med1[i]->print();
		}
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		if (med2[i]->getName() == pillsName) {
			med2[i]->print();
		}
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		if (med3[i]->getName() == pillsName) {
			med3[i]->print();
		}
	}

}

void PhOperations::searchByType(string typeRecepy) {

	for (unsigned int i = 0; i < med1.size(); i++) {
		if (med1[i]->getType() == typeRecepy) {
			//cout << "The type in first Pharmacy is:" << endl;
			med1[i]->print();  // like previouse
		}
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		if (med2[i]->getType() == typeRecepy) {
			//cout << "The type in second Pharmacy is:" << endl;
			med2[i]->print();
		}
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		if (med3[i]->getType() == typeRecepy) {
			//cout << "The type in third Pharmacy is:" << endl;
			med3[i]->print();
		}
	}
}
void PhOperations::searchByPrice(double pricePills) {

	for (unsigned int i = 0; i < med1.size(); i++) {
		if (med1[i]->getPrice() == pricePills) {
			cout << "The price on first Pharmacy is:" << endl;
		}
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		if (med2[i]->getPrice() == pricePills) {
			cout << "The price on second Pharmacy is:" << endl;
		}
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		if (med3[i]->getPrice() == pricePills) {
			cout << "The price on third Pharmacy is:" << endl;
		}
	}
}

void PhOperations::searchQuantityPills(int quantityPills) {

	for (unsigned int i = 0; i < med1.size(); i++) {
		if (med1[i]->getQuantity() == quantityPills) {
			cout << "The quantity of pills in first Pharmacy: "
					<< quantityPills
					<< endl;
		}
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		if (med2[i]->getQuantity() == quantityPills) {
			cout << "The quantity of pills in second Pharmacy: "
					<< quantityPills << endl;
		}
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		if (med3[i]->getQuantity() == quantityPills) {
			cout << "The quantity of pills in third Pharmacy: "
					<< quantityPills << endl;
		}
	}
}

double PhOperations::calculatePillPrice() {
	double pillsPrice = 0;

	for (unsigned int i = 0; i < med1.size(); i++) {
		pillsPrice = med1[i]->getPrice() / med1[i]->getQuantity();
		cout << "PillsPrice on first Pharmaci is:" << pillsPrice << endl;
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		pillsPrice = med2[i]->getPrice() / med2[i]->getQuantity();
		cout << "PillsPrice on second Pharmaci is:" << pillsPrice << endl;
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		pillsPrice = med3[i]->getPrice() / med3[i]->getQuantity();
		cout << "PillsPrice on thired Pharmaci is:" << pillsPrice << endl;
	}
	return pillsPrice;
}

void PhOperations::mostExpensivePills() {

}

/*map<double, string, greater<double> > ExpensivePills;
 map<double, string>::iterator it;
 double price = 0;
 for (unsigned int i = 0; i < med1.size(); i++){
 price = med1[i]->getPrice() + med2[i]->getPrice() + med3[i]->getPrice();

 ExpensivePills[price] = med1[i]->getPrice();
 }

 cout << "The most expensive pill is: " << endl;
 it = ExpensivePills.begin();
 cout << it->first << "\t" << it->second << endl;
 }*/

/*map<double, string, greater<double> > myMap1;
 map<double, string, greater<double> > myMap2;
 map<double, string, greater<double> > myMap3;

 for (unsigned i = 0; i < med1.size(); i++) {
 myMap1.insert(
 pair<double, string>(med1[i]->getPrice(), med1[i]->getName()));

 myMap2.insert(
 pair<double, string>(med2[i]->getPrice(), med2[i]->getName()));

 myMap3.insert(
 pair<double, string>(med3[i]->getPrice(), med3[i]->getName()));
 }

 map<double, string>::iterator it1 = myMap1.begin();
 map<double, string>::iterator it2 = myMap2.begin();
 map<double, string>::iterator it3 = myMap3.begin();

 for (unsigned int i = 0; i < myMap1.size(); i++) {
 cout << "Price -> " << it1->first << " Name -> " << it1->second << endl;
 it1++;
 cout << "Price -> " << it2->first << " Name -> " << it2->second << endl;
 it2++;
 cout << "Price -> " << it3->first << " Name -> " << it3->second << endl;
 it3++;
 }
 }*/

void PhOperations::cheapestPills() {


	/*map<double, string, less<double> > myMap1;
	 map<double, string, less<double> > myMap2;
	 map<double, string, less<double> > myMap3;

	 for (unsigned int i = 0; i < med1.size(); i++) {
	 myMap1.insert(
	 pair<double, string>(med1[i]->getPrice(), med1[i]->getName()));

	 myMap2.insert(
	 pair<double, string>(med2[i]->getPrice(), med2[i]->getName()));

	 myMap3.insert(
	 pair<double, string>(med3[i]->getPrice(), med3[i]->getName()));
	 }
	 map<double, string>::iterator it1 = myMap1.begin();
	 map<double, string>::iterator it2 = myMap2.begin();
	 map<double, string>::iterator it3 = myMap3.begin();

	 for (unsigned int i = 0; i < myMap1.size(); i++) {
	 cout << "Price -> " << it1->first << " Name -> " << it1->second << endl;
	 it1++;
	 cout << "Price -> " << it2->first << " Name -> " << it2->second << endl;
	 it2++;
	 cout << "Price -> " << it3->first << " Name -> " << it3->second << endl;
	 it3++;
	 }*/
}

double PhOperations::totalCalcPriceInPharmacy() {
	double calcPriceofPh = 0.0;

	for (unsigned int i = 0; i < med1.size(); i++) {
		calcPriceofPh = med1[i]->getPrice() * med1[i]->getQuantity();
		cout << "The calculate price in first Pharmacy: " << calcPriceofPh
				<< endl;
	}
	for (unsigned int i = 0; i < med2.size(); i++) {
		calcPriceofPh = med2[i]->getPrice() * med2[i]->getQuantity();
		cout << "The calculate price in second Pharmacy: " << calcPriceofPh
				<< endl;
	}
	for (unsigned int i = 0; i < med3.size(); i++) {
		calcPriceofPh = med3[i]->getPrice() * med3[i]->getQuantity();
		cout << "The calculate price in third Pharmacy: " << calcPriceofPh
				<< endl;
	}
	return calcPriceofPh;
}
