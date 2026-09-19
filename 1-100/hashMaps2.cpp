#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
  // Syntax: std::unordered_map<KeyType, ValueType> mapName;
  unordered_map<string, int> ages;

  // 1. Insert Data (O(1) Time)
  ages["Kashaf"] = 19;
  ages["Ali"] = 22;
  auto test = ages.find("Kashaf");

  // 2. Access Data (O(1) Time)
  cout << test->first << "\n";  // Output: Kashaf
  cout << test->second << "\n"; // Output: 19

  // 3. Update Data (O(1) Time)
  ages["Kashaf"] = 20; // Key already exist thi, toh value overwrite ho jayegi.

  //====================================TRAP===================================================

  unordered_map<string, int> ages1;
  ages1["Kashaf"] = 19;
  ages1["Ali"] = 16;

  // Main print karna chahta hoon kisi anjaan bande ko
  cout << ages1["UnknownPerson"] << '\n'; // Print karega '0' and aik bucket
                                          // UnknownPerson ko allot kar dega.

  //==========================CORRECT-WAY====================================

  if (ages1.count("Ali")) {
    cout << "Ali is in the map!\n";
  }

  auto it = ages1.find(
      "Ali"); // 'auto' use kiya kyunki iterator ki type bohot lambi hoti hai

  if (it != ages1.end()) {
    cout << "Found! Value is: " << it->second << '\n';
  }
  return 0;
}
