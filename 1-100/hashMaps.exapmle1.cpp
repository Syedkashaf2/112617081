#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  vector<int> nums = {1, 2, 2, 3, 1, 1, 4};

  // Key: integer (the number), Value: integer (its frequency)
  unordered_map<int, int> frequencyMap;

  for (int n : nums) {
    // Bracket Operator Trap? Yahan woh trap hamare faide mein kaam
    // aata hai! Jab pehli baar 'n' aayega, map.count 0 hoga, aur
    // frequencyMap[n] automatically 0 create karega. Phir ++ us 0 ko 1 kar
    // dega. Agli dafa jab wohi number aayega, toh woh ++ hoke 2 ho jayega.
    frequencyMap[n]++;
  }

  // Map ko print karne ka tareeqa (Range-based loop)
  // Map ka har element ek 'pair' hota hai.
  for (auto const &pair : frequencyMap) {
    cout << "Number " << pair.first << " appears " << pair.second
         << " times.\n";
  }

  return 0;
}
