#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // vector is a inbuilt template class in c++ for dynamic arrays functionality
    // vector is a part of standard template library (STL)
    // vector is a sequence container and also known as dynamic array or array list
    // creating vector dynamically
    vector<int> *vp = new vector<int>;
    // creating vector statically
    vector<int> v;
    // we insert elements in vector using push_back method
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i + 1);
    }
    // we can access elements of vector using [] operator
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
    // we can also access elements of vector using at method, at method provides range checking we can not access elements out of size of vector
    for (int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << " ";
    }
    cout << endl;

    // size method returns the size of vector
    cout << v.size() << endl;
    // capacity method returns the capacity of vector
    cout << v.capacity() << endl;
    // we can also insert elements at any position in vector using insert method
    v.insert(v.begin() + 1, 20);
    // pop_back method removes the last element of vector
    v.pop_back();
    // we can also remove elements at any position in vector using erase method
    v.erase(v.begin() + 1);
    // we can also remove elements in range in vector using erase method
    v.erase(v.begin() + 1, v.begin() + 4);
    // we can also clear the vector using clear method
    v.clear();
    // we can also check if vector is empty or not using empty method
    cout << v.empty() << endl;
    // we can also resize the vector using resize method
    v.resize(10);
    // we can also resize the vector using resize method and also provide the value to be filled in vector
    v.resize(10, 5);

    // we can change the element at any position using[] operator but it is not recommended to use[] operator to change the element of vector
    //     as it does not provide range checking and can cause segmentation fault and also it will not increase the size of vector if we change the element at position greater than size of vector
}