#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int maxSubarraySum(std::vector<int> &nums, int k) {
  int currentSum{};

  if (nums.size() < k) {
    return 0;
  }

  for (int i{}; i < k; i++) {
    currentSum += nums.at(i);
  }
  int maxSum{currentSum};

  for (int i{k}; i < nums.size(); i++) {
    currentSum += nums.at(i) - nums.at(i - k);
    maxSum = max(currentSum, maxSum);
  }
  return maxSum;
}

int main() {
  vector<int> nums{1, 5, 2, 8, 3, 7, 2};
  int k = 3;
  cout << maxSubarraySum(nums, k) << '\n';
  return 0;
}
