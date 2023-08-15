#include <iostream>
using namespace std;

/*
Input var a = 10 b = 5;
Output b = 10 , a  = 5;
*/

int main()
{

    int a, b;

    cout << "Enter var a : " << endl;
    cin >> a;

    cout << "Enter var b : " << endl;
    cin >> b;

    cout << endl
         << "Before swapping: "
         << "Var a = " << a << " "
         << "Var b  = " << b << endl;

    // Swapping logic using third variable
    // int c;
    // c = a;
    // a = b;
    // b = c;

    // swapping logic without using third variable
    // a = a + b;
    // b = a - b;
    // a = a - b;

    // Using xor operator
    // a = a ^ b;
    // b = a ^ b;
    // a = a ^ b;

    // using inbuilt function -> always use this to save time and energy
    swap(a, b);

    cout
        << endl
        << "After swapping: "
        << "Var a = " << a << " "
        << "Var b  = " << b << endl;
}