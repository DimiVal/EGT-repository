//============================================================================
// Name        : C10Ex5.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Address.h"
#include "Client.h"
#include "ClientSender.h"
#include "Package.h"
#include "TwoDayPackage.h"
#include "OvernightPackage.h"
#include "CompanyOperations.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	// 5. Package-delivery services

	Address adr1("Odrin", "Sofia", "BG", 1200);
	Address adr2("Alabin", "Sofia", "BG", 1100);
	Address adr3("Gladston", "Plovdiv", "BG", 4000);
	Address adr4("Preslav", "Plovdiv", "BG", 4000);
	Address adr5("Nishava", "Varna", "BG", 9000);
	Address adr6("Dunav", "Varna", "BG", 9000);
	Address adr7("Odrin", "Varna", "BG", 9000);
	Address adr8("Pirotska", "Burgas", "BG", 8000);

	ClientSender send1("Lili", "Lilova", adr1, "Iva", 145278964, "Sofia", "Nikola", 45);
	ClientSender send2("Silvia", "Lilova", adr2, "Qna", 547891456, "Sofia", "Shipka", 17);
	Client res3("Ivan", "Ivanov", adr3);
	Client res4("Petar", "Petrov", adr4);
	ClientSender send5("Marina", "Marinova", adr5, "Como", 875421987, "Varna", "Cherno more", 4);
	ClientSender send6("Vania", "Vasileva", adr6, "Intra", 176987555, "Varna", "Osogovo", 9);
	Client res7("Slav", "Slavov", adr7);
	ClientSender send8("Georgi", "Georgiev", adr8, "Bravo", 874563215, "Burgas", "Breza", 65);
	Client res9("Lili", "Lilova", adr1);
	Client res10("Ivan", "Ivanov", adr3);

	Package pack1(0.2, 2.8, send1, res3);
	Package pack2(0.4, 2.8, send2, res4);
	Package pack3(0.7, 2.8, send5, res7);
	TwoDayPackage tdp1(0.3, 2.8, send6, res9, 2.2);
	OvernightPackage onp1(0.5, 2.8, send8, res3, 3.5);

cout << "The price of the pack1 is: " << pack1.calculateCost() << endl;
cout << "The price of the pack2 is: " << pack2.calculateCost() << endl;
cout << "The price of the pack3 is: " << pack3.calculateCost() << endl;
cout << "The price of the two-day-pack is: " << tdp1.calculateCost() << endl;
cout << "The price of the overnight pack is: " << onp1.calculateCost() << endl;
cout << endl;

send1.print();
cout << endl;
cout << "The name of company of the sender 2 is: " << send2.getNameOfCompany() << endl;
cout << endl;
cout << "The receiver 3 is: " << endl;
res3.print();
cout << endl;
cout << "The last name of receiver 4 is: " << res4.getLastName() << endl;
cout << "The VAT number of the sender 5 is: " << send5.getVatNumber() << endl;;
cout << endl;



	return 0;
}
