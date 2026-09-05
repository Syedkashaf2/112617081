#include <iostream>
#include <vector>

using namespace std;

int main()

{
	const double tax_rate {0.15};

	vector<double> prices {10.0, 20.0, 30.0 };

	prices.at(1) = prices.at(1) + prices.at(1)*tax_rate;

	cout << "Updated 2nd price : " <<   prices.at(1) << '\n';

	prices.at(2) = 25;

	cout << "Updated 3rd price : " <<   prices.at(2)<< '\n';

	prices.push_back(50.0);

	cout <<  "Final vector size : " << prices.size() << '\n';

	
	return 0;
}
