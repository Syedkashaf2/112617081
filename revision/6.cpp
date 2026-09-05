#include <iostream>
#include <string>

using namespace std;

int main()
{
	int arr[3][3] 
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};

	//cout << "Grid value : " << arr[0][1] << endl;
	//cout << "Grid value : " << arr[1][2] << endl;
	//cout << "Grid value : " << arr[2][1] << endl;
	
	for (int i{0}; i < 3; i++ )
	{
		for(int j{0}; j < 3; j++ )
		{
			cout << "Grid : " << arr[i][j] << '\n';
			
		}

	}
	
	return 0;
}

