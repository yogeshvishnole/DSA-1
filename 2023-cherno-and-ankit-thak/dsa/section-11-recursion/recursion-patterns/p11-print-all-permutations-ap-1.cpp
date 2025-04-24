/*
This solution take O(n) extra space, see the below solution for a intelligent
solution prevent extr O(n) soace.
Time complexity = N!*n, N! =  number of permuation and for each func call we are
doing n iterations.
*/

#include <iostream>
#include <vector>
using namespace std;

void permutations(vector<int> &arr, vector<int> &map, vector<vector<int>> &ans, vector<int> &permutation)
{
    if (permutation.size() == arr.size())
    {
        ans.push_back(permutation);
        return;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        if (!map[i])
        {
            permutation.push_back(arr[i]);
            map[i] = 1;
            permutations(arr, map, ans, permutation);
            permutation.pop_back();
            map[i] = 0;
        }
    }
}

vector<vector<int>> giveAllPermutations(vector<int> &arr)
{
    vector<vector<int>> ans;
    vector<int> map(arr.size(), 0);
    vector<int> permutation;
    permutations(arr, map, ans, permutation);
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