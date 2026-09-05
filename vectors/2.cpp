#include <iostream>
#include <vector>

using namespace std;

int main()

{
	vector <int> vector1;

	vector1.push_back(10);
	vector1.push_back(20);

	cout << "Vector 1\n";
	cout << vector1.at(0) << '\n';
	cout << vector1.at(1) << '\n';
	cout << "Size : " << vector1.size() << " Capacity : " << vector1.capacity() << '\n';

	vector <int> vector2;
	vector2.push_back(10);
        vector2.push_back(200);

	cout << "\nVector 2\n";
        cout << vector2.at(0) << '\n';
        cout << vector2.at(1) << '\n';

	cout << "Size : " << vector2.size() << " Capacity : " << vector2.capacity() << '\n';


	vector<vector<int>> vector_2d;
	vector_2d.push_back(vector1);
        vector_2d.push_back(vector2);
	
	cout << "\nvector_2d \n";
	cout << vector_2d.at(0).at(0) << ' ' << vector_2d.at(0).at(1) << '\n';
	cout << vector_2d.at(1).at(0) << ' ' << vector_2d.at(1).at(1) << '\n';

	vector1.at(0) = 10000;

	cout << "\nvector_2d \n";
        cout << vector_2d.at(0).at(0) << ' ' << vector_2d.at(0).at(1) << '\n';
        cout << vector_2d.at(1).at(0) << ' ' << vector_2d.at(1).at(1) << "\n\n";

	cout << "Vector 1\n";
        cout << vector1.at(0) << '\n';
        cout << vector1.at(1) << '\n';
        cout << "Size : " << vector1.size() << " Capacity : " << vector1.capacity() << '\n';



	return 0;
}
