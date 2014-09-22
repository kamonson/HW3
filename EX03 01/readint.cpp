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
			cout << prompt;
			cin >> num;
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