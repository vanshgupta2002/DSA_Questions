#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool iscyclicdfs(int node,int parent,unordered_map<int,list<int>> &adj,unordered_map<int,bool> &visited)
{
    visited[node]=1;
    for(auto i:adj[node])
    {
        if(!visited[i])
        {
            visited[i]=1;
           bool ans= iscyclicdfs(i,node,adj,visited);
           if(ans)
           return ans;
        }
        else if(parent!=i)
        {
            return true;
        }
    }
    

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
    }
        unordered_map<int,bool> visited;
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bool ans=iscyclicdfs(i,-1,adj,visited);
                if(ans==1)
                {
                    return "Yes";
                }
                
            }
            

        }
    return "No";

}

