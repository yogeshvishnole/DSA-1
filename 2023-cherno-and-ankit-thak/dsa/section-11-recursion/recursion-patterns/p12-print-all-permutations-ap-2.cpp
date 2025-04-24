#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int> &arr, vector<vector<int>> &ans, int size)
{
    if (size == arr.size())
    {
        ans.push_back(arr);
        return;
    }

    for (int i = size; i < arr.size(); i++)
    {
        swap(arr[i], arr[size]);
        permutations(arr, ans, size + 1);
        swap(arr[i], arr[size]);
    }
}

vector<vector<int>> giveAllPermutations(vector<int> &arr)
{
    vector<vector<int>> ans;
    permutations(arr, ans, 0);
    return ans;
}

int main()
{
    vector<int> arr = {1, 3, 2};
    vector<vector<int>> permutations = giveAllPermutations(arr);
    for (auto perm : permutations)
    {
        for (auto el : perm)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}