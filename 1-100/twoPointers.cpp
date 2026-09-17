#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool hasPairSum(const std::vector<int> &nums, int target) {
  int left{}, right = nums.size() - 1;
  int currentSum{};

  while (left < right) {
    currentSum = nums.at(left) + nums.at(right);
    if (currentSum > target) {
      right--;
    } else if (currentSum < target) {
      left++;
    } else if (currentSum == target) {
      return 1;
    }
  }
  return 0;
}
