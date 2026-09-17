#include <iostream>
#include <string>
#include <vector>
using namespace std;

void moveZeroes(vector<int> &nums) {
  int slow{};
  for (int i{}; i < nums.size(); i++) {
    if (nums.at(i) != 0) {
      nums.at(slow) = nums.at(i);
      slow++;
    }
  }
  for (int j{slow}; j < nums.size(); j++) {
    nums.at(j) = 0;
  }
}

int main() {
  vector<int> nums{0, 1, 0, 3, 12};
  moveZeroes(nums);

  return 0;
}
