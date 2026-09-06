#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> frames {120, -50, 105, 110, -20, -5, 130, 95};
	vector<int> clean_frames;
	int count{};

	for (int i{}; i < 8; i++)
	{
		if (frames.at(i) > 0)
		{
			clean_frames.push_back(frames.at(i));
			count ++;
		}	
	}

	cout << clean_frames.size() << '\n';
	
	for ( int i{}; i < count; i++)
	{
		cout << clean_frames.at(i) << "  ";
	}

	return 0;
}
