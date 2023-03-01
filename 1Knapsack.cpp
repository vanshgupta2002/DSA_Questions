#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}
class Solution
{
public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int index, int val[], int wt[], int W, vector<vector<int>> &dp)
    {
        if (index == 0)
        {
            if (wt[0] <= W)
            {
                return val[0];
            }
            else
                return 0;
        }
        if (dp[index][W] != -1)
        {
            return dp[index][W];
        }
        int take = 0;
        if (wt[index] <= W)
        {
            take = val[index] + solve(index - 1, val, wt, W - wt[index], dp);
        }
        int nottake = solve(index - 1, val, wt, W, dp);
        return dp[index][W] = max(take, nottake);
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n, vector<int>(W + 1, -1));
        for (int w = wt[0]; w <= W; w++)
        {
            if (wt[0] <= W)
            {
                dp[0][w] = val[0];
            }
            else
                dp[0][w] = 0;
        }
        for (int index =1 ; index < n; index++)
        {
            for (int w = 0; w < W + 1; w++)
            {
                
                
                int take = 0;
                if (wt[index] <= W)
                {
                    take = val[index] + dp[index-1][w-wt[index]];
                }
                int nottake = dp[index - 1][w];
                dp[index][W] = max(take, nottake);
            }
        }
        return dp[n-1][W];

        //return solve(n - 1, val, wt, W, dp);
    }
};