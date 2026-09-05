#include <iostream> 
#include <vector>

using namespace std;

int main ()
{
	vector <char> vovels {'a', 'e', 'i', 'o'};

	vovels.push_back('u');
	
	 cout << "Last vovel added : " << vovels.at(4) << '\n'	;

	 vovels.pop_back();

	 cout << "Size after pop : " << vovels.size() << '\n';

	return 0;
}
