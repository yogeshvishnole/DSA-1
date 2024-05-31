#include <iostream>
using namespace std;

// input array ---> 1,2,3,4
// output -> to print given input arrayt in reverse order - 4,3,2,1

int main()
{

    cout << "Give input array length :" << endl;
    int n;
    cin >> n;

    cout << "Give input array : " << endl;
    int array[n];

    for (int i = 0; i < n; i++)
    {
        cin >> array[i];
    }

    cout << "Input array is: " << endl;

    for (int i = 0; i < n; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << "Output reversed array is: " << endl;

    for (int i = n - 1; i >= 0; i--)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}