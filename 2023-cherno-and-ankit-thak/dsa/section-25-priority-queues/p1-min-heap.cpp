#pragma once
#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
    vector<int> store;

public:
    MinHeap()
    {
    }

    void insert(int data)
    {
        store.push_back(data);
        if (store.size() == 1)
            return;

        int curIndex = store.size() - 1;
        while (curIndex > 0)
        {
            int curParentIndex = (curIndex - 1) / 2;
            if (store[curParentIndex] > store[curIndex])
            {
                swap(store[curParentIndex], store[curIndex]);
                curIndex = curParentIndex;
            }
            else
            {
                return;
            }
        }
    }

    int getMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        return store[0];
    }

    int removeMin()
    {
        if (isEmpty())
        {
            return 0;
        }
        int minEl = store[0];
        swap(store[0], store[store.size() - 1]);
        store.pop_back();

        int curChildIndex = 0;
        while (curChildIndex < (store.size() - 1))
        {
            if (((2 * curChildIndex + 1) <= (store.size() - 1)) && (store[2 * curChildIndex + 1] < store[curChildIndex]))
            {
                if (((2 * curChildIndex + 2) <= (store.size() - 1)) && (store[2 * curChildIndex + 2] < store[2 * curChildIndex + 1]))
                {
                    swap(store[2 * curChildIndex + 2], store[curChildIndex]);
                }
                else
                {
                    swap(store[2 * curChildIndex + 1], store[curChildIndex]);
                }
            }
            else if (((2 * curChildIndex + 2) <= (store.size() - 1)) && (store[2 * curChildIndex + 2] < store[curChildIndex]))
            {
                if (((2 * curChildIndex + 1) <= (store.size() - 1)) && (store[2 * curChildIndex + 1] < store[2 * curChildIndex + 2]))
                {
                    swap(store[2 * curChildIndex + 1], store[curChildIndex]);
                }
                else
                {
                    swap(store[2 * curChildIndex + 2], store[curChildIndex]);
                }
            }
            else
            {
                return minEl;
            }
        }
        return minEl;
    }

    bool isEmpty()
    {
        return store.size() == 0;
    }
};

int main()
{
    MinHeap *myMinHeap = new MinHeap();
    // myMinHeap->insert(5);
    // myMinHeap->insert(7);
    // myMinHeap->insert(9);
    // myMinHeap->insert(3);
    // myMinHeap->insert(4);
    // myMinHeap->insert(2);
    // myMinHeap->insert(1);
    // myMinHeap->insert(8);

    myMinHeap->insert(12);
    myMinHeap->insert(6);
    myMinHeap->insert(5);
    myMinHeap->insert(100);
    myMinHeap->insert(1);
    myMinHeap->insert(9);
    myMinHeap->insert(0);
    myMinHeap->insert(14);

    while (!(myMinHeap->isEmpty()))
        cout << myMinHeap->removeMin() << endl;

    // cout << myMinHeap->getMin() << endl;
}