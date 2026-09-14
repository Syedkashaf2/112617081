#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  vector<int> nums{2, 4, -1, 5, 2};
  int n{nums.size()};
  vector<long long> prefix(n + 1, 0);

  for (int i{}; i < n; i++) {
    prefix[i + 1] = prefix[i] + nums[i];
  }
  return 0;
}
