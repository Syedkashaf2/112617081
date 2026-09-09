#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
	int sum{};
	string ok {"Hello"};
	int avg{};
	int x{1};
	for ( auto num : ok )
	{
		cout << "\nElement number " << x << " : " << num  <<'\n';
		cout << "\nElement number(.at) " << ok.at(x-1) << " : " << num  <<'\n';
		x++;

	}
	avg = sum / nums.size();
	cout << "\nFinal average is : " << avg << '\n';
	return 0;
}

