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
			if (low >= high){ throw invalid_argument("Range is invalid"); }
				cout << prompt;
				cin >> num;
				if (num < low || num > high) throw out_of_range("Please select a value within the range: ");
				return num;
		}
		catch (ios_base::failure& ex){
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		catch (out_of_range& ex){
			cerr << "Range is between " << low << " and " << high << endl;
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}

	return 0;
}