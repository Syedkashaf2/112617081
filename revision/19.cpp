#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<int> student_distance {12, 65, 150, 40, 200};

	int student_rank{4500};
	const int cutoff_rank{5000};
	int preference {2};

	if ( student_rank < cutoff_rank)
	{
		switch (preference)
		{
			case 1:
				cout << "Allocated: Computer Science Engeineering\n";
				break;
                        case 2:
                                cout << "Allocated: Electronics Engeineering\n";
                                break;
                        case 3:
                                cout << "Allocated: Mechanical Engeineering\n";
                                break;
                        default:
                                cout << "Invalid prerference selected\n";
                                break;

		}
	}
	else
	{
		cout << "Counselling rejected: Rank too low\n";
	}

	string hostel_status;

	hostel_status = ((student_rank < 100) ? "Premium Hostel" : "Standard Hotel");

	cout << "Hostel Status: " << hostel_status << '\n';

	return 0;
}
