#include <iostream>
#include <string>
#include <vector>
using namespace std;

int calculeSum(vector<int> &numbers) {
  int sum{};
  for (int i{}; i < numbers.size(); i++) {
    sum += numbers.at(i);
  }
  return sum;
}

int main() {
  vector<int> mySum{10, 20, 30, 40, 50};
  cout << calculeSum(mySum) << '\n';
  return 0;
}
