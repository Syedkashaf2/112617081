#include <climits>
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLength(int target, std::vector<int> &nums) {
  int left{};
  int currentLength{};
  int currentSum{};
  int minLength = nums.size() + 1;
  for (int i{}; i < nums.size(); i++) {
    currentSum += nums.at(i);

    while (currentSum >= target) {
      currentLength = i - left + 1;
      minLength = min(currentLength, minLength);
      currentSum -= nums.at(left);
      left++;
    }
  }
  if (minLength == nums.size() + 1) {
    return 0;
  } else
    return minLength;
}

int main() {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int target = 7;
  cout << minSubArrayLength(target, nums) << '\n';
}
