//============================================================================
// Name        : CD05_28_Ex6.cpp
// Author      : DVV
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;

int main() {

	//6. Write a program that finds in a given array of integers how
	//many times each of them presents.

	map<int, int, less<int> > counters;
	// key   :   array element  value  :  how many times

	map<int, int>::iterator it;
	int arr[] = { 3, 5, 7, 9, 11, 3, 11, 7, 3, 7 };

	for (int i = 0; i < 10; i++) {
		int key = arr[i];
		it = counters.find(key);
		if (it != counters.end()) {
			// ima takova chislo v map-a
			counters[key]++;
		} else {
			// niama takova chislo v map-a
			counters[key] = 1;
		}
	}
	cout << "Number " << " " << "Times" << endl;
	for (it = counters.begin(); it != counters.end(); it++) {
		cout << it->first << "  -> " << it->second << endl;
	}
	cout << endl;

	return 0;
}
