/*Zeus CS273-Data Structures*/

#include <iostream>
#include <stdexcept>
#include "readint.h"
using namespace std;
/*Ask user for a range of numbers, display the number the user selects if it is within range*/
int main()
{
	int low, high;
	cout << "Enter the range of values to read.\n";
	cout << "high: ";
	cin >> high;
	cout << "low: ";
	cin >> low;
	try
	{
		/*test to ensure that number range is valid and argument is an int value*/
//		throw (double) high, low; try to catch double value being entered--did not work
		if (low >= high) throw invalid_argument("Invalid range, renter low:");
		int number = read_int("Please enter a number within the range: ", low, high);
		cout << "You entered " << number << endl;
	}
	/*if range is wrong display error and end program*/
	catch (invalid_argument &e) {
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
	}
//	/*if double value is given*/ attempted but did not work correctly, read all entries as an error including proper ones
//	catch (double){
//		cerr << "Value for range must be an integer value.\n";
//	}
}
