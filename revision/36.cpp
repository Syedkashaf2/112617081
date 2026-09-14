#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
public:
  int health;
  int score;
  Player(int h, int s) : health(s), score(s) {};
};

int main() {
  Player p1(100, 50);
  Player p2 = p1;
  Player p3(p1);

  return 0;
}
