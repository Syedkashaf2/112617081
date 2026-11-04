#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  int requiredNumber{};
  unordered_map<int, int> seenNumbers;

  for (int i{}; i < nums.size(); i++) {
    requiredNumber = target - nums.at(i);
    if (seenNumbers.count(requiredNumber) > 0) {
      cout << seenNumbers[requiredNumber] << "  " << i << '\n';
    } else {
      seenNumbers[nums.at(i)] = i;
    }
  }
  return {};
}

int main() {
  vector<int> nums{2, 11, 2, 15, 7};
  int target{9};

  twoSum(nums, target);

  return 0;
}
