#include <bits/stdc++.h>
using namespace std;

void printGraph(vector<vector<int>> &adjacencyMatrix)
{
    for (int i = 1; i <= 4; i++)
    {
        cout << "Node: " << i << ", Negighbours: ";
        for (int j = 1; j <= 4; j++)
        {
            if (adjacencyMatrix[i][j] == 1)
            {
                cout << j << " ";
            }
        }
        cout << endl;
    }
}

// Print the Adjacency list
void printAdjacencyList(unordered_map<int, vector<int>> graph)
{
    for (auto x : graph)
    {
        cout << "Node: " << x.first << ", Neighbours: ";
        for (int el : x.second)
        {
            cout << el << " ";
        }
        cout << endl;
    }
}

int main(int argc, char *argv)
{
    vector<vector<int>> edgeList = {
        {1, 2},
        {2, 3},
        {3, 4},
        {4, 2},
        {1, 3}};

    // Adjancency Matrix Implementation
    int n = 5;
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0));

    for (int i = 0; i < edgeList.size(); i++)
    {
        // undirected graph
        int a = edgeList[i][0], b = edgeList[i][1];
        adjacencyMatrix[a][b] = 1;
        adjacencyMatrix[b][a] = 1;
    }
    printGraph(adjacencyMatrix);

    // Adjancency list implementaion
    unordered_map<int, vector<int>> graph; // if it was a weighted graph instead of vector of integers use vector of pairs

    for (int i = 0; i < edgeList.size(); i++)
    {
        int a = edgeList[i][0], b = edgeList[i][1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    printAdjacencyList(graph);
}