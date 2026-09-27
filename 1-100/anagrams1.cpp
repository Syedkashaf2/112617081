#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(const string &s, const string &t) {

  // 1. Edge Case: Agar length hi barabar nahi, toh anagram nahi ho sakte.
  if (s.size() != t.size()) {
    return false;
  }

  // 2. The 26 Buckets (Initially all 0)
  // By using ('-' - 'a';) where at - might be any alphabet.
  // count[0] track karega 'a' ki frequency
  // count[1] track karega 'b' ki frequency
  // ... count[25] track karega 'z' ki frequency
  vector<int> count(26, 0);

  // 3. Populate the Buckets
  // Hum dono strings ek hi loop mein iterate kar sakte hain kyunki length
  // barabar hai.
  for (int i = 0; i < s.size(); i++) {
    // String 's' wale characters ka count BADAHO (+)
    count[s[i] - 'a']++;

    // String 't' wale characters ka count GHATAO (-)
    count[t[i] - 'a']--;
  }

  // 4. Verify the Balance
  // Agar dono strings Anagrams hain, toh jitne 's' ne add kiye honge, utne hi
  // 't' ne subtract kiye honge. Result mein poora array wapas 0 ho jana
  // chahiye.
  for (int num : count) {
    if (num != 0) {
      return false; // Koi ek letter un-balanced reh gaya
    }
  }

  return true; // Perfect balance!
}

int main() {
  string s = "apple";
  string t = "pleap"; // I made it a valid anagram for testing

  if (isAnagram(s, t)) {
    cout << "Yes, they are anagrams!\n";
  } else {
    cout << "No, they are not anagrams.\n";
  }

  return 0;
}
