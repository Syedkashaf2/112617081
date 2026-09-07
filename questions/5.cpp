#include <iostream>
#include <vector>
using namespace std;

int main()
{

        vector<int> packets {4, 15, 88, 15, 4};
        bool is_symmetrical = true;
        int left{}, right= packets.size()-1;
        while(left < right)
        {
                if ( packets.at(right) == packets.at(left) )
                {
                        right--;
                        left++;
                } else
                {
                        is_symmetrical = false;
                        break;
                }
        }
        cout << (is_symmetrical == true ? "YES" : "NO" ) << '\n';
        return 0;
}

