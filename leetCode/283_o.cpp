#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int k{};
    vector<int> nums{0, 1, 0, 3, 12};

    if (nums.size() == 0)
        return 0;

    for (int i{}; i < nums.size(); i++)
    {
        if (nums.at(i) != 0)
        {
            swap(nums.at(k), nums.at(i));
            k++;
        }
    }
    return 0;
}

gf