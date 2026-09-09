#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    string signal = "lllllllllKeeeeAeeSehhhhhhhhhhhHeIemmmmmmmmmF";
    char noice[] {'e', 'l', 'h', 'm'};
    int pos{};
    
    int noise_elements = sizeof(noice) / sizeof(noice[0]);
    for (size_t i{}; i < signal.length(); i++)
    {
        for (int j{}; j < noise_elements; j++) 
        {
            size_t found_pos = signal.find(noice[j]);
            while (found_pos != string::npos) 
   		 {
        		signal.erase(found_pos, 1);
	       		found_pos = signal.find(noice[j])
   		 }
        }
    }
    
    cout << signal << '\n';
    return 0;
}

