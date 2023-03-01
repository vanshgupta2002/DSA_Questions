#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
// works in gfg
class Solution
{
public:
    bool detect(int src, vector<int> adj[], int vis[])
    {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty())
        {

            int parent = q.front().second;
            int node = q.front().first;
            q.pop();

            for (auto i : adj[node])
            {

                if (!vis[i])
                {
                    q.push({i, node});
                    vis[i] = 1;
                }
                else if (i != parent)
                {
                    return true;
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        int vis[V] = {0};
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detect(i, adj, vis))
                {
                    return true;
                }
            }
        }
        return false;
    }
};