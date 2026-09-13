#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isSubsequence(string s, string t) {
  s = "abc";
  t = "ahbgdc";
  int i{}, j{};
  bool is_sub{true};

  while (i < s.length() && j < t.length()) {
    if (s[i] == t[j]) {
      i++;
    }
    j++;
  }
  return (i == s.length());
}

int main() {
  string s{};
  string t{};

  cout << "Enter the sum string : ";
  cin >> s;

  cout << "Enter the main string : ";
  cin >> t;

  cout << isSubsequence(s, t) << '\n';

  return 0;
}
