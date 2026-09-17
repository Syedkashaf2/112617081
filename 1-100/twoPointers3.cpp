#include <iostream>
#include <string>
#include <vector>
using namespace std;
int removeDuplicates(vector<int> &nums) {
  int slow{};
  int k{1};

  for (int i{1}; i < nums.size(); i++) {
    if (nums.at(slow) != nums.at(i)) {
      slow++;
      nums.at(slow) = nums.at(i);
      k++;
    }
  }
  return k;
}
int main() {

  vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
  cout << removeDuplicates(nums) << '\n';
  return 0;
}
