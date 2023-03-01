#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
    unordered_map<int,list<int>> adj; 
    for(int i=0;i<edges.size();i++)
    {
        int u=edges[i].first;
        int v=edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
	queue<int> q;
    q.push(s);
    unordered_map<int,bool> visited;
    unordered_map<int,int> parent;
    parent[s]=-1;
    visited[s]=1;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(auto i:adj[front])
        {
            if(!visited[i])
            {
                visited[i]=true;
                parent[i]=front;

            }
        }
    }

    vector<int> ans;
    ans.push_back(t);
    int curnode=t;
    while(curnode!=s)
    {
        curnode=parent[curnode];
        ans.push_back(curnode);
    }
    reverse(ans.begin(),ans.end());
    return ans;


}
