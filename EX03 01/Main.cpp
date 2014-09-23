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
		/*Run read_int then out put numeric info*/
		int number = read_int("Please enter a number within the range: ", low, high);
		cout << "You entered " << number << endl;
	}
	/*if range is invalid display error and end program*/
	catch (invalid_argument &e) {
		cerr << "Exception: You supplied an invalid argument for read_int!\n";
	}
}
