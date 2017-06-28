//============================================================================
// Name        : CD_Pharmacy.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iostream>
#include "PhOperations.h"
#include "Medicine.h"
#include "pugixml.hpp"
#include <cstdlib>
using namespace std;

int main() {

	PhOperations op;
	op.addFirstPharmacyInVector();
	op.addSecondPharmacyInVector();
	op.addThirdPharmacyInVector();

	op.mostExpensivePills();
	cout << endl;
	op.cheapestPills();
	cout << endl;
	op.salesAllPharmacy();
	cout << endl;
	op.searchByName("Analgin");
	cout << endl;
	op.searchByPrice(2.65);
	cout << endl;
	op.searchByType("Green");
	cout << endl;
	op.searchQuantityPills(1000);
	cout << endl;
	op.totalCalcPriceInPharmacy();



	return 0;
}
