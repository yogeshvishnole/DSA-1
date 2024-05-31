#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // ====================First Approach using the temp array ===================================== //

    // Time complexity -> O(n)
    // Space complexity -> O(n)

    // vector<int> v{23, -7, 12, -10, -11, 40, 60};
    // vector<int> tempVector(v.size());

    // int negCount = 0;
    // int posCount = 0;

    // int j = 0;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (v[i] < 0)
    //     {
    //         tempVector[j] = v[i];
    //         j++;
    //     }
    // }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (v[i] >= 0)
    //     {
    //         tempVector[j] = v[i];
    //         j++;
    //     }
    // }
    // for (int i = 0; i < tempVector.size(); i++)
    // {
    //     v[i] = tempVector.at(i);
    // }

    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }

    // ====================Second Approach using the two pointers ===================================== //

    // Time complexity -> O(n)
    // Space complexity ->

    vector<int> v{-7, 23, 12, -10, -11, 40, 60};

    int posOfNeg = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < 0)
        {
            swap(v[posOfNeg], v[i]);
            posOfNeg++;
        }
    }

    for (auto it : v)
    {
        cout << it << " ";
    }
}