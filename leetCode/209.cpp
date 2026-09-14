#include <iostream>
#include <vector>
using namespace std;

int minSubArray(int target, vector<int> &nums) {
  int left{};
  int currentSum{};
  int minLength = nums.size() + 1;

  for (int i{}; i < nums.size(); i++) {
    currentSum += nums[i];
    while (currentSum >= target) {
      minLength = min(minLength, 1 + i - left);
      currentSum = currentSum - nums[left];
      left++;
    }
  }
  return (minLength >= nums.size() + 1 ? 0 : minLength);
}

int main() {
  vector<int> nums{2, 3, 1, 2, 4, 3};
  int target{7};

  cout << minSubArray(target, nums) << '\n';
  return 0;
}
