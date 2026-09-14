#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*
class Player {
private:
  int health;
  int score;

public:
  Player(int h, int s) {
    health = h;
    score = s;
    cout << "Custom Player created\n";
  }
};
*/

class Hero {
private:
  int level;
  int power;

public:
  Hero() : level(1), power(10) {}

  Hero(int l) : level(l), power(20) {}

  Hero(int l, int p) : level(l), power(p) {}

  void showStats() { cout << "Lvl: " << level << " Pwr: " << power << '\n'; }
};

int main() {
  Hero h1;
  Hero h2(5);
  Hero h3(10, 100);

  h1.showStats();
  h2.showStats();
  h3.showStats();

  return 0;
}
