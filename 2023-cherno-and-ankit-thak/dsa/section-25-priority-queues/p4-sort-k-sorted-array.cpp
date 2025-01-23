#include <iostream>
#include <queue>
using namespace std;

void sortKSortedArray(vector<int> &array, int k)
{

    priority_queue<int> pq;
    // build the max heap of size K
    for (int i = 0; i < k; i++)
    {
        if (i >= array.size())
        {
            break;
        }
        pq.push(array[i]);
    }

    for (int i = 0; i < array.size(); i++)
    {
        array[i] = pq.top();
        pq.pop();
        if ((i + k) < array.size())
        {
            pq.push(array[i + k]);
        }
    }
}

int main()
{
    vector<int> v{10, 12, 6, 7, 9};
    cout << "Before sorting : " << endl;
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;
    sortKSortedArray(v, 3);
    cout << "After sorting : " << endl;
    for (int item : v)
    {
        cout << item << " ";
    }
    cout << endl;
}