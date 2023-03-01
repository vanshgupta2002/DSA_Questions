#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
#include<bits/stdc++.h>
using namespace std;
bool cycledfs(int node,unordered_map<int,bool> &visited,unordered_map<int,bool> &dfsvisited,unordered_map<int,list<int>> &adj)
{
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            
        
        bool ans=cycledfs(i,visited,dfsvisited,adj);
            if(ans)
            return true;
        }
        else if(dfsvisited[i])
        {
            return true;
        }
    } 
    dfsvisited[node]=false;
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
  unordered_map<int,bool> visited;
  unordered_map<int,bool> dfsvisited;
  for(int i=0;i<edges.size();i++)
  {
    int u=edges[i].first;
    int v=edges[i].second;
    adj[u].push_back(v);


  }

    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            bool cycledetected=cycledfs(i,visited,dfsvisited,adj);
            if(cycledetected)
            {
                return true;
            }
        }
    }
    return false;

}