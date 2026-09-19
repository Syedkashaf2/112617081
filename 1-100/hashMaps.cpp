#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// BUCKET ARRAY: its like a vector but instead of pusing the elements on the end
// we dinamically place elements on specific indexes.

// HASH FUNCTION: We gave it a key and it generates a random , massive and
// psudo-random integer ( HASH CODE).

// MODULO OPERATOR(%): HASH CODE is usaually much larger then the number of
// available buckets. the modulo operator compresses the code to a valid index
// within the bucket array; ( Indedx = Hashcode % NumberOfBuckets)

int main() {
  // Key type is string, Value type is int
  unordered_map<string, int> ageMap;

  // 1. Insertion & Updating: O(1) Average
  ageMap["Kashaf"] = 19;
  ageMap["Twin1"] = 5;

  // 2. Accessing: O(1) Average
  int myAge = ageMap["Kashaf"];

  // cout << &myAge["Kashaf"] << '\n';
  // cout << &myAge["Twin1"] << '\n';
  cout << myAge["Kashaf"] << '\n';
  cout << myAge["Twin1"] << '\n';

  // TRAP!
  if (ageMap["Nobody"] == 0) {
    // This condition might be true, BUT you just accidentally added "Nobody" to
    // the map! This wastes memory and corrupts your data.
  }

  // The Correct Way (Existence check only)
  if (ageMap.count("Kashaf") > 0) {
    // It exists!
  }

  // The Professional Way (Check and retrieve in one O(1) operation)
  auto it = ageMap.find("Kashaf");
  if (it != ageMap.end()) {
    cout << it->second; // 'first' is the key, 'second' is the value
  }

  return 0;
}
