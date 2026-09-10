#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isPallindrome(string s)
{
    bool n {true};
    for ( int i{}; i < s.length()-1; i++)
    {
        if (s[i] != s[(s.length()-1) - i] )
        {
            n = false;
            break;
        } else
        {
            n = true;
        }
    }
    return n;
}

int main()
{
    cout << "ENTER THE WORD : ";
    string n{};
    cin >> n;
    if ( isPallindrome(n) == true)
        cout << "pallindrome\n";
    else
        cout << "not-pallindrome\n";
	return 0;
}
