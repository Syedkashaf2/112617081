#include <iostream>
#include <vector>
using namespace std;

int main()
{

	int n{10};
	int votes[10] {2, 4, 2, 1, 2, 3, 4, 2, 1, 4};
	int vote_counts[5] {};
	int k {4};
	int current{0};
	int max{};

	for ( int i{0}; i < 10; i++ )
	{
		vote_counts[votes[i]]++;
	}

	for ( int i{}; i < 5; i++)
	{
		current = vote_counts[i];
	       if (current > max )
	       {
		max = current;
	       }	       
	}
	cout << max << '\n';
	return 0;
}
