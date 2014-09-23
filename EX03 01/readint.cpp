#include "readint.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>

using namespace std;

int read_int(const string &prompt, int low, int high){

	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try{
			/*check to ensure range is valid*/
			if (low >= high){ throw invalid_argument("Range is invalid"); }
			cout << prompt;
			cin >> num;
			/*check to ensure num is within range*/
			if (num < low || num > high) throw ios_base::failure("Please select a value within the range: ");

			return num;
		}
		catch (ios_base::failure& ex){
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}

	return 0;
}