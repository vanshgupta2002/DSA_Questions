#include<bits/stdc++.h>
using namespace std;
bool iscyclic(unordered_map<int,list<int>> adj,int src, unordered_map<int,bool> visited)
{
    unordered_map<int,int> parent;
    parent[src]=-1;
    visited[src]=1;
    queue<int> q;
    q.push(src);
    while(!q.empty())
    {
      int front=q.front();
      q.pop();
      for(auto neighbour: adj[front])
      {
        if(visited[neighbour]==true && neighbour!=parent[front])
        {
            return true;
        }
        else if(!visited[neighbour])
        {
            visited[neighbour]=true;
            q.push(neighbour);
            parent[neighbour]=front;
        }
      }

    }
    return false;

}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
   unordered_map<int,list<int>> adj;
    for(int i=0;i<m;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool ans=iscyclic(adj,i,visited);
                if(ans==1)
                {
                    return "Yes";
                }
                
            }
            return "No";

        }

    } 
}

int main()
{

return 0;
}