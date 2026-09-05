#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector <int> match_scores {85, 92, 79};
	int total_score {match_scores.at(0) + match_scores.at(1) + match_score.at(2) };

	double average_score{};

	average_score = static_cast<double> (total_score) / 3;

	cout << "Total match score: " << total_score << '\n';
	cout << "Exact average score: " << average_score << '\n';

	return 0;
}
