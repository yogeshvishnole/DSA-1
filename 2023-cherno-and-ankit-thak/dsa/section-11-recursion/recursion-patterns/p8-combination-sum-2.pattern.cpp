/*
It is very good pattern to understand, as a brute force method we can use the same backracking
solution here that we use in combination sum problem, but now to prevent duplicates at each ans
at each leaf node means for 2 raise to the power n cases I have to check if the given combination
already exists in my list that will be a n*n operation in worst case. So my complexity will become
from 2^n to 2^n*n*n since n*n is very high then 2^n*n*n will be much much more higher.

So efficient approach is very clever and 100% accurate, but small tough to understand.
See for not containing duplicates, if at a given position in ds or combination one element
is already taken then we should not take it again at the same position. this comparison
will be easy if we call all the possible elements at a given position in one go, by looping over
the array, and to leave the same element will be easier if we sort the array, so in this case
complexity will be same as combination that is 2^n, since 2^n + nlogn ==== O(2^n);
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findCombinations(int index, vector<int> &ds, vector<int> &candidates, int curSum, int target, vector<vector<int>> &combinations)
{
    if (curSum == target)
    {
        // vector<int> combination;
        // for (auto el : ds)
        // {
        //     combination.push_back(el);
        // }
        combinations.push_back(ds);
        return;
    }

    for (int i = index; i < candidates.size(); i++)
    {
        if ((i > index && candidates[i] == candidates[i - 1]) || candidates[i] > target)
        {
            continue;
        }

        ds.push_back(candidates[i]);
        findCombinations(i + 1, ds, candidates, curSum + candidates[i], target, combinations);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end());
    vector<int> ds;
    vector<vector<int>> combinations;
    findCombinations(0, ds, candidates, 0, target, combinations);
    return combinations;
}

int main()
{
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int>> combinations = combinationSum2(candidates, target);
    for (auto combination : combinations)
    {
        for (auto el : combination)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}