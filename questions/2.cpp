#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> batches {40, 50, 120, 30, 25};
	int index{}, total_processed{};

	do
	{
		total_processed += batches.at(index);
		index++;
	}
	while ( batches.at(index-1) <= 100 && (index < batches.size()) );
	
	cout << total_processed << '\n';
	return 0;
}
