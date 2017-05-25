//============================================================================
// Name        : Exam3Ex2N.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Manufacturer.h"
#include "Med.h"
#include "MedOperations.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
//string nameMan, int code, string country
// string name, double price, int quant, Types type, Manufacturer manuf
// NOtype, FreeSale, BlueRecipe, GreenRecipe
	Manufacturer mf1("Bayer", 4568, "Germany");
	Manufacturer mf2("SoPharma", 1574, "Bulgaria");

	Med m1("Aspirin", 2.9, 50, FreeSale, mf1);
	Med m2("Analgin", 1.6, 30, FreeSale, mf2);
	Med m3("ACC", 0.8, 100, FreeSale, mf1);
	Med m4("Fluditeck", 9.8, 10, withBlueRecipe, mf2);
	Med m5("Ventolin", 12.5, 10, greenRecipe, mf2);

	MedOperations medOp;

	medOp.addMedicine(m1);
	medOp.addMedicine(m2);
	medOp.addMedicine(m3);
	medOp.addMedicine(m4);
	medOp.addMedicine(m5);

	medOp.searchByName("ACC", "Bayer");
	cout << endl;
	medOp.searchByPrice(12.5);
	cout << endl;
	medOp.searchByType(withBlueRecipe);


	return 0;
}
