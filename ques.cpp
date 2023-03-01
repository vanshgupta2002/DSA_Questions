#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
class Solution {
public:
int fibn(int n,vector<int> &dp)
{
    if(n<=1)
    {
        return n;
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }
    else
    {
        dp[n]=fibn(n-1,dp)+fibn(n-2,dp);
        return dp[n];
    }
}
    int fib(int n) {
        vector<int> dp(n+1);
        for(int i=0;i<n;i++)
        {
            dp[i]=-1;
        }
       return fibn(n,dp);
        
        
    }
};