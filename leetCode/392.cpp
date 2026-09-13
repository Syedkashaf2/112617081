#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s{"abc"};
string t{"ahbgdc"};
int i{}, j{};
bool is_sub{true};

int main() {
  while (i < s.length() && j < t.length()) {
    if (s[i] == t[j]) {
      i++;
    }

    j++;
  }
  cout << (i == s.length()) << '\n';
  return 0;
}
