#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getFirstElement(int arr[], int size) {
  return arr[0]; // Sirf 1 step laga.
}
// O(1) Time , O(1) Size

void printAll(int arr[], int N) {
  for (int i = 0; i < N; i++) {
    std::cout << arr[i]; // Yeh line N dafa chalegi
  }
}
// O(N) Time, O(1) Space

void copyArray(int original[], int N) {
  int copy[N]; // Naya array bana liya (N size ka)

  for (int i = 0; i < N; i++) {
    copy[i] = original[i];
  }
}
// O(N) Time, O(N) Space because of the array of size N.
