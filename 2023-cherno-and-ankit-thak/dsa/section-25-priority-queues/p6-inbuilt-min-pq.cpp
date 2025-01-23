#include <iostream>
#include <queue>
using namespace std;

int main(int argc, char **argv)
{
    // Syntax for creating the min pq / min heap
    priority_queue<int, vector<int>, greater<int>> mpq;

    // Syntax for creating max priority queue/ max heap
    priority_queue<int> maxpq;

    mpq.push(16);
    mpq.push(1);
    mpq.push(167);
    mpq.push(7);
    mpq.push(45);
    mpq.push(32);

    vector<int> test;
    // instead of pushing one by one if we push in one go like then
    // time complexity will become O(n) instead of o(nlogn) I have to reserach the reason
    priority_queue<int, vector<int>, greater<int>> mpq2(test.begin(), test.end());

    cout
        << "Size: " << mpq.size() << endl; // 6
    cout << "Top: " << mpq.top() << endl;  // 1

    while (!mpq.empty())
    {
        cout << mpq.top() << endl;
        mpq.pop();
    }
}