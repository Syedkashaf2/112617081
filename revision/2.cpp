#include  <iostream>
using namespace std;

int main ()
{
	int test [5] {100,200,300};
	cout << test [0] << '\n';
	cout << test [3] << '\n';
	cout << test [5] << '\n';

	cout << test [6] << '\n';
	cin >> test [4];

	cout << test [] << '\n';
	return 0;
}
