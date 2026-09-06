#include <iostream>
#include <vector>

using namespace std;

int main()

{
	
	vector <int> user1_scores;
	user1_scores.push_back(10);
	user1_scores.push_back(20);
	
	cout << "User 1 size : " << user1_scores.size() << '\n';
	cout << "User 1 scores : " << user1_scores.at(0) << ", " << user1_scores.at(1) << '\n';

	vector <int> user2_scores;
        user2_scores.push_back(30);
        user2_scores.push_back(40);

        cout << "User 2 size : " << user2_scores.size() << '\n';
        cout << "User 2 scores : " << user2_scores.at(0) << ", " << user2_scores.at(1) << '\n';
	
	vector <vector <int>> all_scores;
	all_scores.push_back(user1_scores);
	all_scores.push_back(user2_scores);

	cout << "From 2D Vector (User 1, Scpre 1): " << all_scores.at(0).at(1) << '\n';
	
	return 0;
}
