#include <bits/stdc++.h>
using namespace std;
void dfs(int node, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, stack<int> &st)
{
    vis[node] = true;
    for (auto i : adj[node])
    {
        if (!vis[i])
            dfs(node, adj, vis, st);
    }
    st.push(node);
}
void revdfs(int node, unordered_map<int, list<int>> &transpose, unordered_map<int, bool> &vis)
{
    vis[node] = true;
    for (auto i : transpose[node])
    {
        if (!vis[i])
            revdfs(node, transpose, vis);
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    unordered_map<int, bool> vis;
    stack<int> st;
    for (int i = 0; i < v; i++) 
    {

        if (!vis[i])
            dfs(i, adj, vis, st);
    }
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        vis[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            revdfs(top, transpose, vis);
        }
    }
    return count;
}
int main()
{

    return 0;
}