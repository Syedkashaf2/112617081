#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<vector<int>> grid;

	vector <int> row1 {1, 2, 3};
	vector <int> row2 {4, 5};

	grid.push_back(row1);
	grid.push_back(row2);

	cout << "Total rows in grid: " << grid.size() << '\n';
	cout << "Elements in row 2: " << grid.at(1).size() << '\n';
	cout << "Last element of row 2: " << grid.at(1).at(1) << '\n';

	return 0;
}
