#include <iostream>
using namespace std;

int main ()
{       
        int error_count{3};
        do{
                cout << "Running diagonstic pass...\n";
                error_count --;
        }
        while(error_count > 0);
        return 0;
}       

