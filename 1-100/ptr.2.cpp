#include <iostream>
using namespace std;

void example1() {
  int x{};
  int &ref = x;

  cout << ref << '\n';
  // cout << *ref << '\n';

  ref = 10;

  cout << ref << '\n';
  cout << x << '\n';
  // cout << *ref << '\n';
}

int main() {
  example1();
  return 0;
}
