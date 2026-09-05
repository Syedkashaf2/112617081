#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int total_amount{387};

	const int dollar_value {100};
	const int quarter_value {25};
	const int dime_value {10};
	const int nickel_value {5};
	const int change_value {1};

	vector <int> change_wallet ;
	
	change_wallet.push_back(total_amount / dollar_value);
	total_amount %= dollar_value;

	change_wallet.push_back(total_amount / quarter_value);
        total_amount %= quarter_value;
	
	change_wallet.push_back(total_amount / dime_value);
        total_amount %= dime_value;

	change_wallet.push_back(total_amount / nickel_value);
        total_amount %= nickel_value;

	change_wallet.push_back(total_amount / change_value);
        total_amount %= change_value;

	cout << "Dollar : " << change_wallet.at(0) << '\n';
	cout << "Quarter : " << change_wallet.at(1) << '\n';
	cout << "Dime : " << change_wallet.at(2) << '\n';
	cout << "Nickel : " << change_wallet.at(3) << '\n';
	cout << "Change : " << change_wallet.at(4) << '\n';

	return 0;
}
