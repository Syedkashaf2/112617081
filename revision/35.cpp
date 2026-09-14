#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Soldier {
  string name;

public:
  Soldier(string n) : name(n) { cout << name << " is borm\n"; }

  ~Soldier() { cout << name << " dies.\n"; }
};

void battle() { Soldier s2("Bravo"); }

int main() {
  Soldier s1("Alpha");
  battle();

  Soldier s3("Charlie");
  return 0;
}
