#include <iostream>
using namespace std;

void expalination()
{
    int age = 20;    // Ek normal variable
    int *ptr = &age; // Ek pointer variable jiska naam 'ptr' hai. Yeh 'age' ka Pata(&) store kar raha hai.
}

void explaination1()
{
    int age = 20;
    int *ptr = &age;

    cout << *ptr << '\n'; // Yeh "20" print karega!
    // Kyunki *ptr ka matlab hai: ptr ke andar jo address hai, wahan JAAO
    // aur data dekho.

    *ptr = 50;           // ptr wale address par JAAO aur data ko 50 kar do.
    cout << age << '\n'; // Yeh ab "50" print karega! Original variable badal gaya.
    cout << *ptr << '\n';
}

void explaination3()
{
    int score = 100;
    int *p = &score;

    *p = *p + 50;

    cout << score << "\n";
    cout << *p << "\n";
    cout << p << "\n";
}

int main()
{
    // expalination();
    // explaination2();
    explaination3();
    return 0;
}
