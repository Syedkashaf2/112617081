#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string &s) {
  int left{};
  int maxLength{};
  unordered_map<char, int> seen;

  for (int i{}; i < s.size(); i++) {
    if (seen.count(s[i]) > 0) {
      left = max(left, seen[s[i]] + 1);
    }
    seen[s[i]] = i;
    maxLength = max(maxLength, i - left + 1);
  }

  return maxLength;
}

int main() {
  string s{"abcdefaaaaaa"};
  cout << lengthOfLongestSubstring(s) << '\n';
  return 0;
}
