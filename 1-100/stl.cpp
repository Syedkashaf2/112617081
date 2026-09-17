#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

void explaination1(vector<int> &nums) {
  /* 1: std::sort(start, end)Kaam: Array ya Vector ko ascending order (chotay se
   * bada) mein sort karta hai.Time Complexity: $O(N \log N)$ (Yeh sabse fast
   * sorting algorithm ka mix hai - Introsort).Example: std::sort(nums.begin(),
   * nums.end()); */
  sort(nums.begin(), nums.end());
}

void explaination2(vector<int> &nums) {
  /* 2: std::reverse(start, end)Kaam: Elements ki tarkeeb ko bilkul ulta kar
   * deta hai.Time Complexity: $O(N)$Example: std::reverse(nums.begin(),
   * nums.end()); */
  reverse(nums.begin(), nums.end());
}

void explaination3(vector<int> &nums) {
  /* 3: std::max_element(start, end) / std::min_element(start, end)Kaam: Sabse
   * bada ya chota element dhoondhta hai. Yeh value nahi, balki us element ka
   * Iterator (Pointer) return karta hai. Value dekhne ke liye dereference (*)
   * karna padta hai.Time Complexity: $O(N)$Example: int max_val =
   * *std::max_element(nums.begin(), nums.end()); */
  int max_val = *max_element(nums.begin(), nums.end());
}

void explaination4(vector<int> &nums) {
  /* 4: std::accumulate(start, end, initial_value) (Header: <numeric>)Kaam: Sare
   * elements ka sum (jama) nikalta hai.Time Complexity: $O(N)$Example: int sum
   * = std::accumulate(nums.begin(), nums.end(), 0); */
  int sum = std::accumulate(nums.begin(), nums.end(), 0);
}
// Custom Rule: 'a' pehle aayega agar 'a' bada hai 'b' se (Descending sort)
bool descendingRule(int a, int b) { return a > b; }

int main() {
  std::vector<int> nums = {10, 50, 20};

  // Sort ko bataya ke hamara custom rule use karo
  std::sort(nums.begin(), nums.end(), descendingRule);

  // nums ab ban chuka hai: {50, 20, 10}
  return 0;
}
