#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
//  BEST PRACTICE : USING STATIC_CAST UNSIGNED CHAR TO AVOID UB.
bool isPalindrome(const string &s) {
  if (s.empty())
    return true; // Edge case

  int left = 0;
  int right = s.size() - 1;

  while (left < right) {
    // Skip INVALID char
    while (left < right && !isalnum(s[right])) {
      right--;
    }

    // Skip INVALID char
    while (left < right && !isalnum(s[left])) {
      left++;
    }
    // Compare.
    if (tolower(s[left]) != tolower(s[right])) {
      return false;
    }

    // next pair
    left++;
    right--;
  }

  return true;
}
