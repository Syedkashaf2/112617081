#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Normal (Pass by Value) - Buri Aadat for large data
void badFunction(vector<int> v) {
  // v ki puri copy bani. Agar vector mein 1 million items hain, toh RAM full
  // aur time zaya!
}

// Pass by Reference - Best Practice
void goodFunction(vector<int> &v) {
  // Sirf vector ka "nickname" pass hua. Koi copy nahi bani. (O(1) space).
  // Agar main 'v' ko yahan change karun, toh original vector bhi change hoga.
}

void swapNumbers(int &x, int &y) {
  int temp = x;
  x = y;
  y = temp;

  cout << "X = " << x << " Y = " << y << '\n';
}

int main() {
  int x{1};
  int y{2};

  swapNumbers(x, y);

  return 0;
}
