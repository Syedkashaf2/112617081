/*
#include <iostream>
#include <vector>
*/
#include <string>
using namespace std;

class Car {
private:
  string brand;
  int year;
  int topSpeed;

  /*================OLD CODE======================
  public:
      Car(string b, int y, int ts)    {
          brand = b;
          year = y;
          topSpeed = ts;
      }
  ==================NEW CODE=====================*/

public:
  Car(string b, int y, int ts) : brand(b), year(y), topSpeed(ts) {}
};

int main() {
  Car c1("lambo", 2026, 120);
  return 0;
}
