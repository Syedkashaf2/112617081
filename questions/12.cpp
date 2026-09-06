#include <iostream>
#include <vector>

using namespace std;

int main()
{
        int movie_ratings [2][3]
        {
                {5, 6, 4},
                {6, 7, 8}       
        };
        
        int current_sum{movie_ratings[0][0] + movie_ratings[1][0]};

        vector<int> movie1_totals;

        movie1_totals.push_back(current_sum);

        cout << "Vector size: " << movie1_totals.size() << '\n';
        cout << "Total for Movie 1: " << movie1_totals.at(0) << '\n';

        return 0;
}

