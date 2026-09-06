#include <iostream>
//#include <vector>
using namespace std;

int main()
{	
	int current_streak{1}, max_streak{1}, n{7};
	int a[] {12, 15, 22, 10, 18, 25, 30};
	for (int i{1}; i < n; i++)
	{
		if ( a[i] >  a[i-1])
		{
			current_streak++;
		} else 
		{
			current_streak = 1;
			max_streak = 1;
		}

		if ( current_streak > max_streak )
		{
			max_streak = current_streak;
		}

	}	
	cout << max_streak << '\n';

	return 0;
}
