#include <iostream>
using namespace std;

int main()
{

    // int balance;
    // cin >> balance;

    // if statement block
    // if (balance >= 10)
    // {
    //     cout << "maggi";
    // }

    // if-else block

    // if (balance >= 10)
    // {
    //     cout << "maggi";
    // }
    // else
    // {
    //     cout << "kurkure";
    // }

    int sides;

    cin >> sides;

    // if (sides == 3)
    // {
    //     cout << "It is a triangle";
    // }
    // else
    // {
    //     cout << "Not a triangle";
    // }

    if (sides == 3)
    {
        cout << "It is a triangle";
    }
    else if (sides == 4)
    {
        cout << "Its a rectangle";
    }
    else if (sides == 5)
    {
        cout << "Its a pentagon";
    }
    else
    {
        cout << "Mujhe nhi pta";
    }
}