#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> commands {3, 1, 4, 0, 2, 5};
	int index{};
	do {
		cout << "Executing command ID: " << commands.at(index) << '\n';
		index ++;
	   }

	while ( commands.at(index-1) != 0 );
	return 0;
}
