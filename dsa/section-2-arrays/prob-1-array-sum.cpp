#include <iostream>
using namespace std;

// Input -> array [1, 2, 3]
// output --> arraySum  6

int main()
{

    /// first take input array from user.

    // step 1 take size of array

    int n;
    cout << "Please enter size of array whose sum you want to calculate" << endl;

    cin >> n;

    int array[n];

    cout << "Give input " << n << " times for giving all array elements which you want sum" << endl;

    for (int i = 0; i < n; i++)
    {

        cin >> array[i];
    }

    cout << "Given array" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }

    // now actual logic to sum array.

    // aggrgator variable

    int arraySum = 0;

    for (int i = 0; i < n; i++)
    {
        arraySum += array[i];
    }

    cout << "Sum of array is " << arraySum << endl;
}