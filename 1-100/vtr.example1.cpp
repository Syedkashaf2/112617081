#include <iostream>
#include <vector>

int main() {
  std::vector<int> scores = {5, 10, 15};

  // Loop 1
  for (auto s : scores) {
    s = s + 1;
  }

  // Loop 2
  for (auto &s : scores) {
    s = s - 2;
  }

  // Loop 3
  for (auto s : scores) {
    std::cout << s << " ";
  }

  return 0;
}
