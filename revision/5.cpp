#include <iostream>
#include <string>

using namespace std;

int main()
{
	int num[] {10, 20, 30, 40, 50};

	int size_arr = sizeof(num);
	cout << "Size of the array is : " << size_arr << '\n';

	int size_ell = sizeof(num[0]);
	cout << "Size of the element is : " << size_ell << '\n';

	return 0;
}
