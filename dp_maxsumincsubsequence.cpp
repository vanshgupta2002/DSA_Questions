#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}class Solution{
    int solve(int arr[], int n,int i,int prev,vector<vector<int>>& dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev]!=-1)
        {
            return dp[i][prev];
        }
        int take =0;
       
        if(prev==-1||arr[i]>arr[prev])
        {
            take=arr[i]+solve(arr,n,i+1,i,dp);

        }
      int nottake=solve(arr,n,i+1,prev,dp);
        return dp[i][prev]= max(take,nottake);
    }
		

	public:
	int maxSumIS(int arr[], int n)  
	{  vector<vector<int>> dp(n,vector<int>(n+1,-1))
        int prev=-1;
	    return solve(arr,n,0,prev,dp);
	}  
};