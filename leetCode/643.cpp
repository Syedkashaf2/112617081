#include <iostream>
#include <string>
#include <vector>
using namespace std;

double slideWindow(vector<int> &nums) {
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

  return static_cast<double>(maxSum) / k;
}

int main() {
  vector<int> nums{1, 12, -5, -6, 50, 3};

  cout << slideWindow(nums) << '\n';

  return 0;
}
