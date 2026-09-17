#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {10, 20, 30};

  nums.push_back(40); // Fast, add at end
  nums.pop_back();    // Fast, remove from end

  // O(N) operation - Insert 50 at index 1
  nums.insert(nums.begin() + 1, 50);

  // OLd way of writing the code
  for (int i = 0; i < nums.size(); i++) {
    std::cout << nums[i];
  }

  // New and more efficient way of writing code.
  vector<int> nums1 = {10, 20, 30};

  // The Modern Way (Pass by Value - read only)
  for (int n : nums1) {
    cout << n << " "; // Yeh bari bari nums ka har element 'n' mein dalega
  }

  // Use of auto keyword
  auto x = 5;      // Compiler khud isey 'int' samajh lega
  auto y = 10.5;   // Compiler isey 'double' samajh lega
  auto name = "A"; // Compiler isey char/string samajh lega

  // Modifying a vector by using the new iteration method.

  //  WRONG (Vector change nahi hoga, O(N) space extra lag raha hai copies
  //  banane mein)
  for (auto n : nums) {
    n = n * 2;
  }

  // CORRECT (Vector actually change hoga, O(1) space)
  for (auto &n : nums) {
    n = n * 2;
  }

  return 0;
}
