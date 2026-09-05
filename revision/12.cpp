#include <iostream>
#include <vector>

using namespace std;

int main()
{       
        vector <int> original {10, 20, 30};
        vector <int> backup = original;

	original.at(0) = 99;

        cout << "Original first element: " << original.at(0) << '\n';
        cout << "Backup first element: " << backup.at(0) << '\n';

        original.clear();

        cout << "Original size after clear: "<< original.size() << '\n';
        cout << "Backup size after clear: "<< backup.size() << '\n';
        
        return 0;
}
