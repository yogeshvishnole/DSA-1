/* 

Pattern - Simple question, use graph traversal on all connected components.
answer will be equal to number of connected components.

More learnings - 
How to run bfs/dfs on a adjacency matrix and when index 0 represents the node 1 and so on,
means index n represents the n+1th node.

*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
    public:
    
        void bfs(vector<vector<int>>& graph,vector<int> &visited,int source){
            queue<int> q;
            q.push(source);
            visited[source] = 1;
    
            while(!q.empty()){
    
                 int curNode = q.front();
                 q.pop();
    
                 for(int i=0;i<graph.size();i++){
                     if(graph[curNode-1][i] && !visited[i+1]){
                        q.push(i+1);
                        visited[i+1] = 1;
                     }
                 }
    
            } 
        }
    
        int findCircleNum(vector<vector<int>>& isConnected) {
            
            vector<int> visited(isConnected.size()+1,0);
    
            int numberOfProvinces = 0;
            for(int i=1;i<visited.size();i++){
                if(!visited[i]){
                   numberOfProvinces++;
                   bfs(isConnected,visited,i);
                }
              
            }
    
            return numberOfProvinces;
        }
    };