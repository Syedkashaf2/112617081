#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> logs {250, 100, -50, 300, 999, 450};
	int valid_total {};

	for ( int i{}; i < logs.size() ; i++ )
	{
		if (logs.at(i) < 0)
			continue;	
		if(logs.at(i) == 999)
			break;
		else
			valid_total += logs.at(i);
	}

	cout << valid_total<< '\n';

	return 0;
}
