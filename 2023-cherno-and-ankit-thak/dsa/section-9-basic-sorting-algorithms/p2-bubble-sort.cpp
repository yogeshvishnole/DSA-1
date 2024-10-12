#include <iostream>
#include <vector>
using namespace std;

void bubbleSort(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - 1 - i; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}

void printVector(vector<int> &v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v{7, 5, 3, 6, 8};
    cout << "Before sorting: " << endl;
    printVector(v);
    bubbleSort(v);
    cout << "After sorting: " << endl;
    printVector(v);
}