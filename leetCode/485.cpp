#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums { 1, 1, 0, 1, 1, 1 };
	int current_ones{}, max_ones{};

	for (int i{}; i < nums.size(); i++)
	{
		if ( nums.at(i) == 1 )
			current_ones++;
		else 
			current_ones = 0;

		if ( current_ones > max_ones )
			max_ones = current_ones;
	}	
	cout << max_ones << '\n';
	return 0;
}
