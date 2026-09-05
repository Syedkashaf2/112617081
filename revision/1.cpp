#include <iostream>
using namespace std;


int main()
{
	cout << "Enter the  number of small rooms : ";
	int small_rooms{};
	cin >> small_rooms;
	
	cout << "Enter the  number of large rooms : ";
	int large_rooms{};
	cin >> large_rooms;
	
	int price_small{25};
	cout << "Price per small room :" << price_small << '\n';

	int price_large{30};
	cout << "Price per large room : " << price_large << '\n';

	int cost = (small_rooms * price_small) + (large_rooms * price_large);
	cout << "cost : " << cost << '\n';

	float tax{0.06};
	cout << "tax : " << tax*cost << '\n';

	cout << "======================================== \n ";

	cout << "Total Estimate : "<< (tax*cost) + cost << '\n';

	int estimate_expiry{30};
	cout << "This estimate is only valid for " << estimate_expiry << '\n';
	

	return 0;
}
