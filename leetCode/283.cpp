#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k{1};
	vector<int> nums {0, 1, 0, 3, 12};

	if (nums.size() == 0)
		return 0;

	for (int i{1}; i < nums.size(); i++)
	{
		if (nums.at(i) != 0)
		{
			nums.at(k) = nums.at(i);
			k++;
		}	
	}

	for (int i{k}; i < nums.size(); i++)
	{
		nums.at(k-1) = 0;
	}

	return 0;
}
