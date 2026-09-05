#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int entrance_score {85};
	char major_choice {'C'};
	bool hostel_required = true;

	if (entrance_score >= 90)
		cout << "Tier 1 College Allocated\n";
	else if (entrance_score >= 80)
		{
			cout << "Tier 2 College Allocated\n";
			switch (major_choice)
			{
				case 'C':
					cout << "Seat: Computer science engineering\n"; 
					break;
				default :
					cout << "Seat: General Engineering\n";
					break;
			}
			if (hostel_required)
				cout << "Priority: Hostel accommodation Confirmed\n";
			else
				cout << "Score too low for allocation\n";
		}

	return 0;
}


