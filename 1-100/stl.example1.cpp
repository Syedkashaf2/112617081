#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool evenOddRule(int x, int y)
{
    if (x % 2 == 0 && y % 2 != 0)
        return true; // x is even, y is odd -> x goes BEFORE y
    else if (y % 2 == 0 && x % 2 != 0)
        return false; // y is even, x is odd -> x does NOT go before y
    else
        return x < y; // Both are even OR both are odd
}

int main()
{
    vector<int> nums = {3, 8, 5, 10, 9};

    // std::sort yahan aapka function call karega
    sort(nums.begin(), nums.end(), evenOddRule);

    // Hamein output chahiye: pehle even (8, 2), phir odd (3, 5, 9)
    // Inki apni aapas ki tarkeeb aage peechay ho jaye toh koi masla nahi.
    for (auto n : nums)
    {
        cout << n << " ";
    }

    return 0;
}
