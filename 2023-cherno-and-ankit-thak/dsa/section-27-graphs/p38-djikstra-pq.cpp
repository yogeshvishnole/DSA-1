#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

const int INF = 1e9 + 7;

template <typename T>
class PriorityQueue
{
    vector<T> store;

public:
    PriorityQueue()
    {
    }

    void insert(T data)
    {
        store.push_back(data);

        if (store.size() == 1)
        {
            return;
        }

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

    void removeMin()
    {
        if (store.size() == 0)
        {
            throw runtime_error("queue is empty");
        }

        int storeSize = store.size();
        swap(store[0], store[storeSize - 1]);
        store.pop_back();
        storeSize = storeSize - 1;
        int curIndex = 0;

        while (curIndex < (storeSize - 1))
        {
            int leftChild = 2 * curIndex + 1;
            int rightChild = 2 * curIndex + 2;

            if (leftChild < (storeSize - 1) && store[leftChild] < store[curIndex])
            {
                if (rightChild < (storeSize - 1) && store[rightChild] < store[curIndex])
                {
                    swap(store[curIndex], store[rightChild]);
                    curIndex = rightChild;
                }
                else
                {
                    swap(store[curIndex], store[leftChild]);
                    curIndex = leftChild;
                }
            }
            else if (rightChild < (storeSize - 1) && store[rightChild] < store[curIndex])
            {
                if (leftChild < (storeSize - 1) && store[leftChild] < store[curIndex])
                {
                    swap(store[curIndex], store[leftChild]);
                    curIndex = leftChild;
                }
                else
                {
                    swap(store[curIndex], store[rightChild]);
                    curIndex = rightChild;
                }
            }
            else
            {
                return;
            }
        }
    }

    T getMin()
    {
        if (store.size() == 0)
        {
            throw runtime_error("queue is empty.");
        }
        return store[0];
    }

    bool isEmpty()
    {
        return store.size() == 0;
    }
};

vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
{

    // create adjacency list first
    vector<vector<pair<int, int>>> adjList(V, vector<pair<int, int>>());
    for (int i = 0; i < edges.size(); i++)
    {
        adjList[edges[i][0]].push_back({edges[i][1],
                                        edges[i][2]});
        adjList[edges[i][1]].push_back({edges[i][0],
                                        edges[i][2]});
    }

    // Create the priority queue
    // pair<distance from source,node>
    PriorityQueue<pair<int, int>> *pq = new PriorityQueue<pair<int, int>>();
    // create an array for distance of all nodes from the source
    vector<int> distance(V, INF);
    distance[src] = 0;
    pq->insert({0, src});

    // start the BFS
    while (!pq->isEmpty())
    {
        int curDist = pq->getMin().first;
        int curNode = pq->getMin().second;
        pq->removeMin();

        // traverse the adjacents of the current node
        int neibNos = adjList[curNode].size();
        for (int i = 0; i < neibNos; i++)
        {
            int curNeib = adjList[curNode][i].first;
            int neibDist = adjList[curNode][i].second;
            if (distance[curNeib] > (distance[curNode] + neibDist))
            {
                // update the distance of curNeib
                distance[curNeib] = distance[curNode] + neibDist;
                pq->insert({distance[curNeib], curNeib});
            }
        }
    }

    return distance;
}

int main()
{
    PriorityQueue<int> *pq = new PriorityQueue<int>();
    pq->insert(0);
    pq->insert(1);
    pq->insert(2);
    pq->insert(3);

    cout << pq->getMin() << endl;
    pq->removeMin();
    cout << pq->getMin() << endl;
    pq->removeMin();
    cout << pq->getMin() << endl;
    pq->removeMin();
    cout << pq->getMin() << endl;
    pq->removeMin();
    cout << pq->getMin() << endl;
}