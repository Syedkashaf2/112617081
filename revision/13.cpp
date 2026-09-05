#include <iostream>
#include <vector>

using namespace std;

int main()
{
	const int total_levels{3};
	int level_scores[total_levels] {50, 100, 150};

	vector <int> player_scores ;

	player_scores.push_back(level_scores[0] );
	player_scores.push_back(level_scores[2] );

        //vector <int> original {10, 20, 30};
        //vector <int> backup = original;

        //original.at(0) = 99;

        cout << "Player score entries: " << player_scores.size() << '\n';

	player_scores.at(0) = 75;
	

        cout << "Updated level 1 score: " << player_scores.at(0) << '\n';
        cout << "Level 2 score: " << player_scores.at(1) << '\n';

        //cout << "Original size after clear: "<< original.size() << '\n';
        //cout << "Backup size after clear: "<< backup.size() << '\n';

        return 0;
}

