#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Enemy {
  string name;

public:
  void setName(string name) { this->name = name; }

  void printName() { cout << "Enemy name is : " << name << '\n'; }
};

int main() {
  Enemy boss;
  boss.setName("Dragon");
  boss.printName();

  return 0;
}
