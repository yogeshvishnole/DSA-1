#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Time complexity using unordered_map = O(n)
Time complexity using the map = O(nlogn)
 */
vector<int> removeDuplicates(int *a, int n)
{
    vector<int> output;
    unordered_map<int, bool> mymap;

    for (int i = 0; i < n; i++)
    {
        if (mymap.count(a[i]) == 0)
        {
            output.push_back(a[i]);
            mymap[a[i]] = true;
        }
    }

    return output;
}

int main(int argc, char **argv)
{
    int a[] = {1, 5, 2, 4, 4, 3, 3, 6, 7, 1, 1, 2};
    vector<int> output = removeDuplicates(a, 12);

    for (auto item : output)
    {
        cout << item << " ";
    }
    cout << endl;
}