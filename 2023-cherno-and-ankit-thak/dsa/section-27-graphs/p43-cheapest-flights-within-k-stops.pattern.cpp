#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/* 
Initially this question seems very easy, but it really tests your ability
to think of the edges cases.I think the problem is easy and jump into
solving it, from starting I know that BFS will get applies because of
shortest path in directed graph, but what makes the problem interesting
is it should be within K stops or k nodes only, but I still solving
as normal Dijstra with Queue as it is directed graph, but my soln
is breaking when I have two paths to dest node one is in less stops
but higher dist and one is in more stops than K but with lesser dist.
due to dijstra's nature the minimum value is overriding the distance
for the dst node but that answer is not possible due to number of stops
is becoming more than K stops, nut one thing is clear that on node with 
minimum stops we are reaching first and we are reaching the dst first also
from the path which is closer in terms of stops, so tweak is that we will
store  the latestPath in queue as the nearer elements will reach first than
their distance will get also registered, if we are able to reach the dst 
from longer path at dst within the given K stops than if that longer path
price is smaller we will take that otherwise we take the one with higher 
price but within K stops.
*/

const int INF = 1e9 + 7;
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<vector<pair<int, int>>> flightGraph(n, vector<pair<int, int>>());

        for (int i = 0; i < flights.size(); i++)
        {
            flightGraph[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }

        queue<pair<int, pair<int, int>>> bfsQ;
        vector<int> minPriceVec(n,INF);
       
        bfsQ.push({src, {0, 0}});
        minPriceVec[src] = 0;

    

        while (!bfsQ.empty())
        {
            auto curNodeRef = bfsQ.front();
            int curNode = curNodeRef.first;
            int curStop = curNodeRef.second.first;
            int curDist = curNodeRef.second.second;
            bfsQ.pop();
           
            if(curStop > k) break;

            for (int i = 0; i < flightGraph[curNode].size(); i++)
            {
                int neibNode = flightGraph[curNode][i].first;
                int neibPrice = flightGraph[curNode][i].second;
                int curNeibPrice = neibPrice + curDist;

                if (curStop <= k && curNeibPrice<minPriceVec[neibNode])
                {
                    bfsQ.push({neibNode, {curStop + 1, curNeibPrice}});
                    minPriceVec[neibNode] = curNeibPrice;
                }
            }
        }
        return minPriceVec[dst] == INF ? -1 : minPriceVec[dst];
    }
};

int main()
{
}