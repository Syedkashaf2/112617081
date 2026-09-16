#include <iostream>
#include <iterator>
using namespace std;

void example1() {
  int numbers[3]{10, 20, 30};
  int *p = numbers;

  for (int i{}; i < size(numbers); i++)
    cout << *(p + i) << '\n';
}

void tracing() {
  int arr[4] = {5, 15, 25, 35};
  int *p = arr;

  p = p + 2;

  *p = 99;

  p = p - 1;

  std::cout << *p << " ";
  std::cout << arr[2] << "\n";
}
int main() {

  // example1();
  tracing();
  return 0;
