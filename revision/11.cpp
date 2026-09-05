#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector <double> exam_scores (5, 95.5);

	cout << "Scores size: " << exam_scores.size() << '\n';
	cout << "Last score: " << exam_scores.at(4) << '\n';

	vector <bool> is_active ;

	cout << "Is empty initally? "<< is_active.empty() << '\n';

	is_active.push_back(true);

	cout << "Is empty after push? "<< is_active.empty() << '\n';

	return 0;
}
