#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
class Solution {
public:
int lss(int i,int prev,vector<int> dp,vector<int>& nums)
{
    if(i==nums.size())
    {
        return ;
    }
    if(dp[i]!=-1)
    {
        return dp[i];
    }
    int left,right;
    if(nums[i]<prev||prev!=-1)
    {
        left= lss(i+1,prev,dp,nums) ;
    }
    else
     right=1+lss(i+1,i,dp,nums);

    dp[i]= max(left,right);

}

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size()-1,-1);
        int index=0;
        int prev=-1;
        return lss(index,prev,nums,dp);
    }
};