#include <iostream>
using namespace std;

void expalination() {
  int age = 20;    // Ek normal variable
  int *ptr = &age; // Ek pointer variable jiska naam 'ptr' hai. Yeh 'age' ka
                   // Pata(&) store kar raha hai.
}

void explaination2() {
  int age = 20;
  int *ptr = &age;

  std::cout << *ptr << '\n'; // Yeh "20" print karega!
  // Kyun? Kyunki *ptr ka matlab hai: ptr ke andar jo address hai, wahan JAAO
  // aur data dekho.

  *ptr = 50; // ptr wale address par JAAO aur data ko 50 kar do.
  std::cout << age
            << '\n'; // Yeh ab "50" print karega! Original variable badal gaya.
  std::cout << *ptr << '\n';
}

void explaination3() {
  int score = 100;
  int *p = &score;

  *p = *p + 50;

  std::cout << score << "\n";
  std::cout << *p << "\n";
  std::cout << p << "\n";
}

int main() {
  // expalination();
  // explaination2();
  explaination3();
  return 0;
}
