#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// Custom Rule: 'a' pehle aayega agar 'a' bada hai 'b' se (Descending sort)
bool descendingRule(int a, int b) { return a > b; }

int main() {
  vector<int> nums = {10, 50, 20};

  // Sort ko bataya ke hamara custom rule use karo
  sort(nums.begin(), nums.end(), descendingRule);

  // nums ab ban chuka hai: {50, 20, 10}
  return 0;
}
