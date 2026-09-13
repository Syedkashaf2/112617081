#include <iostream>
#include <vector>
#include <string>
using namespace std;

string longestCommonPrefix(vector<string>& words)
{
	string prefix {words[0]};
	for ( int i{}; i < words.size(); i++ )
	{
		while ( words[i].find(prefix) != 0 )
		{	
			prefix.pop_back();
			if (prefix.empty())
				return "";

		}
	}
	return prefix;
}

int main()
{
	vector<string> myWords {"flower", "flow", "flight"};
	
	cout << longestCommonPrefix(myWords) << '\n';
	return 0;
}
