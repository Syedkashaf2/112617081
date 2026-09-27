#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  // 1. Map to hold our groups. Key: Sorted String, Value: List of original
  // strings strings
  unordered_map<string, vector<string>> groups;

  // 2. Loop through every word in the input array
  for (const string &word : strs) {
    string key = word; // Make a copy to sort (don't ruin the original)
    sort(key.begin(), key.end()); // "eat" becomes "aet"

    // 3. Add the original word to its specific group list
    // If "aet" doesn't exist, C++ creates an empty vector for it first!
    groups[key].push_back(word);
  }

  // 4. Extract just the groups (the values) to return
  vector<vector<string>> result;
  for (auto const &pair : groups) {
    result.push_back(
        pair.second); // pair.first is the key ("aet"), pair.second is the list
  }

  return result;
}

int main() {
  vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

  vector<vector<string>> ans = groupAnagrams(strs);

  for (const auto &group : ans) {
    for (const string &w : group) {
      cout << w << " ";
    }
    cout << "\n";
  }
  return 0;
}
