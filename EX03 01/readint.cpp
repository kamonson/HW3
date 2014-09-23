#include "readint.h"
#include <string>
#include <iostream>
#include <stdexcept>
#include <limits>
#include <ios>

using namespace std;

int read_int(const string &prompt, int low, int high){
	/*user picks number, number returned, 0 returned if code has a problem*/
	cin.exceptions(ios_base::failbit);
	int num = 0;
	while (true) {
		try{
			cout << prompt;
			cin >> num;
			/*check to ensure that number range is valid*/
			if (low >= high) throw invalid_argument("Invalid range, renter low:");
			/*check to ensure that the number entered is between the high and low range*/
			if (num < low || num > high) {
				throw out_of_range ("the number you have entered is not within the selected range, please enter a number within the specified range: \n");
			}
			return num;
		}
		/*if range is invalid display error and end program*/
		catch (invalid_argument &e) {
			cerr << "Exception: You supplied an invalid argument for read_int!\n";
			break;
		}
		/*return error message and allow user to select new number*/
		catch (ios_base::failure& ex){
			cout << "Bad numeric string -- try again\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
		/*return error message and allow user to select new number*/
		catch (out_of_range){
			cerr << "Range is between between " << low << " and " << high << ".\n";
			cin.clear();
			cin.ignore(numeric_limits<int>::max(), '\n');
		}
	}

	return 0;
}