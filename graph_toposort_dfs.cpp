#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
void toposort(int node,stack<int> &s,unordered_map<int,bool> &visited,unordered_map<int,list<int>> &adj)
{
    visited[node]=true;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            toposort(i,s,visited,adj);
        }
    }
    s.push(node);
}
#include <bits/stdc++.h> 
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {

    unordered_map<int,list<int>> adj;
    unordered_map<int,bool> visited;
    stack<int> s;
    for(int i=0;i<e;i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];
        adj[u].push_back(v);
        
        
    }   

    for(int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            toposort(i,s,visited,adj);
        }
    }
    vector<int> ans;
   while(!s.empty())
   {
        ans.push_back(s.top());
        s.pop();
   }
   return ans;
}