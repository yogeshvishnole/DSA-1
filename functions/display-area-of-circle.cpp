#include <iostream>
#include <math.h>
using namespace std;

double printAreaOfCircle(double radius)
{
    cout << M_PI << endl;
    cout << "Area of circle is : " << M_PI * radius * radius << endl;
}

int main()
{
    int r;
    cin >> r;
    printAreaOfCircle(r);
}