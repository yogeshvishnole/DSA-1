#include <iostream>
#include <queue>
using namespace std;

vector<int> kSmallestElements(vector<int> &array, int k)
{
    vector<int> ans;
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
    {
        pq.push(array[i]);
    }

    for (int i = k; i < array.size(); i++)
    {
        int topEl = pq.top();
        if (array[i] > topEl)
        {
            continue;
        }
        pq.pop();
        pq.push(array[i]);
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

int main(int argv, char **argc)
{
    vector<int> v{5, 6, 9, 12, 3, 13, 2};
    cout << endl;
    vector<int> ans = kSmallestElements(v, 3);
    for (int item : ans)
    {
        cout << item << " ";
    }
    cout << endl;
}