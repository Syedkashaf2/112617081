#include <iostream>
/*
#include <string>
#include <vector>
*/
using namespace std;

class Player {
public:
  Player() { cout << "Player created!\n"; }

  ~Player() { cout << "Player destroyed!\n"; }
};

int main() {
  cout << "Start of main\n";

  {
    Player p1;
    cout << "Inside this block\n";
  }

  cout << "End of main\n";
  return 0;
}
