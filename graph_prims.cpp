#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(pq.empty())
        {
            int weight=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(vis[node]==1)
            {
                continue;
            }
            sum+=weight;
            for(auto i: adj[node])
            {
                int adjnode=i[0];
                int adjweight=i[1];
                if(!vis[adjnode])
                {
                    pq.push({adjweight,adjnode});
                }
            }
        }
        return sum;
    }
};
int main()
{

return 0;
}
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        
    }
};
