#include <iostream>
#include <vector> 

using namespace std;

int main()
{
	const int max_days{5};
	
	double temprature[max_days] {32.5, 34.2, 31.8};

	temprature[0] = 33.0;

	cout << "Day 1 temp : " << temprature[0] << '\n';
	cout << "Day 5 temp : " << temprature[0] << '\n';

	//max_days = 6;
	
	/* it fails because the cons keyword provides a named space a fixed value that cannot be changed using assignment opperator */

	return 0;
}


