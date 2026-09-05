#include <iostream>
#include <vector>
using namespace std;

int main()
{
	const int original_res{2000};
	const int export_res{1080};

	vector<int> frame_time {55, 42, 48};

	int var {frame_time.at(0) + frame_time.at(1) + frame_time.at(2) };

	double average_frame_time ;

	average_frame_time = static_cast<double> (var) / 3;

	bool is_optimised = ( original_res > export_res && average_frame_time < 50.0 );

	cout << "Average render time: "	<< average_frame_time << '\n';
	cout << "Is project optimized? " << is_optimised << '\n';


	return 0;
}
