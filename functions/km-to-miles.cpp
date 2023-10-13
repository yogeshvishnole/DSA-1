#include <iostream>
using namespace std;

double kmToMiles(int km)
{
    return km * 0.62137273664981;
}

int main()
{
    double km;
    cout << "Enter the kilometers: " << endl;
    cin >> km;

    cout << "Miles = " << kmToMiles(km) << endl;
}