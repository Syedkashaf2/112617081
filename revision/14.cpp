#include <iostream>
#include <vector>

using namespace std;

int main ()
{
	int count{10}, result{}, result2{};

	result = ++count ;

	cout << "Result is : " << result << '\n';

	result2 = count++ ;

	cout << "Result is : " << result2 << '\n';
	
	return 0;
}
