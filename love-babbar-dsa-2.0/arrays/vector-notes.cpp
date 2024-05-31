#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        // cout << v[i] << " ";
        cout << v.at(i) << " ";
    }
    cout << endl;
}
// Printing vector method 2
void printVector2(vector<int> v)
{
    cout << "Printing vector method 2: " << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v;
    cout << v.size() << endl;

    // while (1)
    // {
    //     int d;
    //     cin >> d;

    //     v.push_back(d);
    //     cout << "Capacity: " << v.capacity() << " Size: " << v.size() << endl;
    // }

    // in vector dont tell size of vector.
    // just keep inserting, i will manage the allocation
    // array hi hai

    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);

    // printVector(v);

    // v.pop_back();

    // printVector(v);

    // // I want to clear all data in vector
    // v.clear();
    // cout << "After clear: " << endl;
    // printVector(v);

    // // vector initialization techniques
    // vector<int> arr;         // default with no data , 0 size
    // vector<int> arr2(5, -1); // init with n size with specific data
    // vector<int> arr3 = {1, 2, 3, 45};
    // vector<int> arr4{1, 2, 3, 4};

    // vector<int> arr5 = {1, 2, 3, 4, 5};
    // vector<int> arr6(arr5);

    // vector<char> charV = {'a', 'b', 'c', 'd'};

    // // front element of vector
    // cout << charV[0] << endl;
    // // OR
    // cout << charV.front() << endl;

    // // end/last element of vector
    // cout << v[v.size() - 1] << endl;
    // // OR
    // cout << charV.back() << endl;
}