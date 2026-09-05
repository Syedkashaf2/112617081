#include <iostream>
#include <vector>
using namespace std;


int main()
{
	
	vector <int>nums = {10, 20, 30, 40 };

	//cout << nums[0] << '\n';
	//cout << nums[2] << '\n';
	//cout << nums[3] << '\n';
	//cout << nums[4] << '\n';
	
	cout << "Size : " << nums.size() << '\n';
	cout << "Capacity : " << nums.capacity() << '\n';

	return 0;
}
