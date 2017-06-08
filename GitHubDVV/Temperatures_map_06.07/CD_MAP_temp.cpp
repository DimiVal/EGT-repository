//============================================================================
// Name        : CD_MAP_temp.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	/*key       vector<int>
	 Sofia   12  34  17  23  23  ...
	 Plovdiv 15  17  19  32  12  ...
	 Varna   34  20  15   8   9  ...

	 1) V koi grad e bilo nai-toplo;
	 2) V koi grad e bilo nai-studeno, za vseki ot gradovete
	 grad -> nai-niska temp.
	 3) 5 nai-topli dni za stranata: grad -> dni
	 4)kolko dni temp e bila > 15 o: grad ->broika
	 5)kolko dni e imalo temp <= 10, kolko dni e bilo <= 20,
	 kolko dni e bila nad 20: broj dni -> granichna temperatura.
	 */
	int arrSofia[10] = { 10, 34, 17, 23, 23, 25, 28, 36, 31, 30 };  //max 36
	vector<int> temp1(arrSofia, arrSofia + 10);

	int arrPlovdiv[10] = { 22, 15, 33, 19, 6, 15, 17, 19, 21, 20 };  //max 33
	vector<int> temp2(arrPlovdiv, arrPlovdiv + 10);

	int arrVarna[10] = { 34, 20, 15, 8, 9, 10, 15, 18, 14, 33 };    //max 34
	vector<int> temp3(arrVarna, arrVarna + 10);

	map<string, vector<int> > countryTemps;  // greater<string>
	cout << "Temperatures: " << endl;

	countryTemps["Sofia"] = temp1;
	countryTemps["Plovdiv"] = temp2;
	countryTemps["Varna"] = temp3;

	// Arrange the key (strihg - name city) by name
	for (map<string, vector<int> >::iterator iter = countryTemps.begin();
			iter != countryTemps.end(); ++iter) {
		cout << iter->first << " " << endl;
		for (int i = 0; i < (int) iter->second.size(); ++i) {
			cout << iter->second[i] << " ";
		}
		cout << endl;
	}
	cout << "------------------------------" << endl;

	map<string, vector<int> > tempSorted;
	cout << "Sorted temperatures: \n" << "Sofia: " << endl;

	sort(temp1.begin(), temp1.begin() + temp1.size());
	for (int i = 0; i < (int) temp1.size(); i++) {
		cout << temp1[i] << " ";
	}
	cout << endl;

	cout << "Plovdiv: \n";
	sort(temp2.begin(), temp2.begin() + temp2.size());
	for (int i = 0; i < (int) temp2.size(); i++) {
		cout << temp2[i] << " ";
	}
	cout << endl;

	cout << "Varna: \n";
	sort(temp3.begin(), temp3.begin() + temp3.size());
	for (int i = 0; i < (int) temp3.size(); i++) {
		cout << temp3[i] << " ";
	}
	cout << endl;

	tempSorted["Sofia"] = temp1;
	tempSorted["Plovdiv"] = temp2;
	tempSorted["Varna"] = temp3;
	cout << "------------------------------\n" << "1)" << endl;

	// 1) V koi grad e bilo nai-toplo;
	map<string, vector<int> >::iterator ittt;
	int maxTemp = -100;   // for max temperature
	vector<string> cities;
	string city;
	for (ittt = tempSorted.begin(); ittt != tempSorted.end(); ++ittt) {
		vector<int> t = ittt->second;
		cout << "The max temperature in " << ittt->first << " is: " << t[t.size() - 1] << endl; //iter->second[iter->second.size() -1] << endl;
		int maxx = t[t.size() - 1];  // max element vav vseki vector

		if (maxx > maxTemp) {
			maxTemp = maxx;
			city = ittt->first;
		}
	}

	for (ittt = tempSorted.begin(); ittt != tempSorted.end(); ++ittt) {
		vector<int> t = ittt->second;
		if (t[t.size() - 1] == maxTemp) {
			cities.push_back(ittt->first);
		}
	}
	cout << "------------------------------" << endl;

	for (unsigned int i = 0; i < cities.size(); i++) {
		cout << "The max temperature in " << cities[i] << " is: "<< maxTemp << endl;
	}
	cout << "------------------------------\n" << "2)" << endl;

	// 2) V koi grad e bilo nai-studeno, za vseki ot gradovete
	// grad -> min temp
	map<string, int> cityMinTemp;
	for (ittt = tempSorted.begin(); ittt != tempSorted.end(); ++ittt) {
		vector<int> t = ittt->second;
		int minn = t[0];

		cityMinTemp[ittt->first] = minn;
		cout << "The min temp in " << ittt->first << " is: " << minn << endl;
	}
	cout << "------------------------------\n" << "3)" << endl;

	// 3) 5-te nai-topli dni za stranata: grad -> temp
	set<int> allTemps;
	for (ittt = tempSorted.begin(); ittt != tempSorted.end(); ++ittt) {
		vector<int> t = ittt->second;
		//allTemps.insert(allTemps.begin(), t.begin() + t.size());
		copy(t.begin(), t.end(), inserter(allTemps, allTemps.end()));
	}

	vector<int> vv(allTemps.begin(), allTemps.end());
	sort(vv.begin(), vv.begin() + vv.size());

	vector<int> fiveTemps;
	//copy(allTemps.begin() + (allTemps.size() - 5, allTemps.end());

	for (int i = (int) vv.size() - 1; i > (int) vv.size() - 6; i--) {
		fiveTemps.push_back(vv[i]);
	}

	multimap<string, int> result;
	for (int i = 0; i < (int) fiveTemps.size(); i++) {
		int mtemp = fiveTemps[i];
		for (ittt = tempSorted.begin(); ittt != tempSorted.end(); ++ittt) {
			vector<int> t = ittt->second;
			if (find(t.begin(), t.end(), mtemp) != t.end()) {
				result.insert(pair<string, int>(ittt->first, mtemp));
			}
		}
	}

	multimap<string, int>::iterator it2;
	for (it2 = result.begin(); it2 != result.end(); ++it2) {
		cout << it2->first << " " << it2->second << endl;
	}
	cout << "------------------------------\n" << "3) Second var.  " << endl;

	// 3) II) variant. 5-te nai-topli dni za stranata: grad -> dni

	vector<int> allTemperatures;
	sort(allTemperatures.begin(),
			allTemperatures.begin() + allTemperatures.size());
	for (int i = 0; i < (int) allTemperatures.size(); i++) {
		cout << allTemperatures[i] << " ";
	}
	cout << endl;



	// 4 kolko dni temp e bila > 15 o: grad ->broika


	return 0;
}
