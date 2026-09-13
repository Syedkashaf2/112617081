#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> nums{1, 12, -5, -6, 5, 3};
  int k{4};
  int currentSum{};
  int maxSum{};

  for (int i{0}; i < k; i++) {
    currentSum += nums[i];
  }
  maxSum = currentSum;
  for (int i{k}; i < nums.size(); i++) {
    currentSum += nums[i] - nums[i - k];
    maxSum = max(currentSum, maxSum);
  }

  return 0;
}
