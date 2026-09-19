#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  unordered_map<string, string> registery;

  registery["Player1"] = "Alive";
  registery["Player2"] = "Dead";

  cout << registery.size() << "  ";

  if (registery["Player3"] == "Dead") {
    cout << "Player3 is Dead ";
  } else {
    cout << "Player3 is Unknown ";
  }

  cout << registery.size() << '\n';

  return 0;
}
