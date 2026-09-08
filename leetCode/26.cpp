#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int k{1};
	vector<int> numb {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	for (int i{1}; i < numb.size(); i++)
	{
		if (numb.size() == 0)
			return 0;
		else if (numb.at(i) != numb.at(i-1))
		{
			numb.at(k) = numb.at(i);
			k++;
		}
	}
	cout << k << '\n';
	return 0;
}
