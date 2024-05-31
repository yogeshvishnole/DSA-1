#include <iostream>
using namespace std;

/*
input -> array -> 4 2 1 10
output --> largest element of array - 10
*/

int main()
{

    // first take length of array

    int n;
    cout << "Enter array len " << endl;
    cin >> n;

    cout << "Enter elements of array " << endl;

    int array[n];
    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << endl
         << "Given array is " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    int largest = array[0];
    int smallest = array[0];

    for (int i = 1; i < n; i++)
    {

        // logic for largest
        if (array[i] > largest)
        {
            largest = array[i];
        }

        // logic  for smallest
        if (array[i] < smallest)
        {
            smallest = array[i];
        }
    }
    cout << endl
         << "Largest of array is : " << largest << endl;
    cout << endl
         << "smallest of array is : " << smallest << endl;
}
