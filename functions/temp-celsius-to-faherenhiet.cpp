#include <iostream>
using namespace std;

double celToFah(double cel)
{
    return (cel * ((float)9 / 5)) + 32;
}

int main()
{
    cout << "Enter temp in celsius : " << endl;
    double celsius;
    cin >> celsius;
    cout << "Temp in fah : " << celToFah(celsius) << endl;
}