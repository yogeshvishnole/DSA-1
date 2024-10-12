/*
Given a sorted array as input - 5,7,7,8,8,10 and a target 8.
Find the first and last position of 8 in the array

We will make use of binary search here, what we will do is when element is found in the array
we will store its index and still searching in the array
if we need to find first pos we will search at the left array of current position means -
e = mid-1
if we need to find last pos we will search at the right array of current position means -
s = mid+1
 */

#include <iostream>
#include <vector>
using namespace std;

int getIndex(vector<int> &v, int target, bool getFirst = 1)
{
    int s = 0;
    int e = v.size() - 1;
    int ans = -1;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (v[mid] == target)
        {
            ans = mid;
            if (getFirst)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if (target > v[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

vector<int> getFirstAndLast(vector<int> &v, int target)
{
    vector<int> ans(2, -1);
    int first = getIndex(v, target);
    if (first == -1)
    {
        return ans;
    }
    int last = getIndex(v, target, false);
    ans[0] = first;
    ans[1] = last;
    return ans;
}

int main(int argc, char **argv)
{
    vector<int> v{5, 7, 7, 8, 8, 10};
    vector<int> ans = getFirstAndLast(v, 8);
    for (auto el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
}
