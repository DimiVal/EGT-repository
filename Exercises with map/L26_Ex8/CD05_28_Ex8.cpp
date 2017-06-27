//============================================================================
// Name        : CD05_28_Ex8.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {

//	8. Write a program that removes from a given
//	sequence all the numbers that present in it odd
//	number of times.

	map<int, int, less<int> > counters;
	// key   :   array element  value  :  hou many times

		map<int, int>::iterator it;
		int arr[] = { 2, 5, 6, 9, 11, 2, 11, 6, 2, 6 };

		vector<int> occur(&arr[0], &arr[0] + 10);

		for (int i = 0; i < 10; i++) {
			int key = arr[i];
			it = counters.find(key);
			if (it != counters.end()) {
				// ima takova chislo v map-a
				counters[key]++;
			} else {
				// nqma takova chislo v map-a
				counters[key] = 1;
			}
		}
		vector<int>::iterator itv;
		cout << "Number " << " " << "Occurences" << endl;

		for (it = counters.begin(); it != counters.end(); it++) {

			cout << it->first << "\t " << it->second << endl;
		}
		for (unsigned int i = 0; i < occur.size(); i++) {
			if (counters[occur[i]] % 2 != 0) {
				occur.erase(occur.begin() + i);
				i--;
			}
		}
		for ( unsigned int i = 0; i < occur.size(); i++) {
			cout << occur[i] << " ";

		}

	return 0;
}
