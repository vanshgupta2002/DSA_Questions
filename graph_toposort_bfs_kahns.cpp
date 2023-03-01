#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int,bool> visited;
    unordered_map<int,list<int>> adj;
    vector<int> indegree(v);
    queue<int> q;
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
    }
    for(auto i:adj)
    {
        for(auto j:i.second)
        {
            indegree[j]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    //bfs
   vector<int> ans;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        ans.push_back(front);
        for(auto i:adj[front])
        {
            indegree[i]--;
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
    }
    return ans;
}