#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
class Solution {
public:
    void solve(vector<int>& candidates,int target,vector<int> ans,vector<vector<int>> fans,int i,int sum)
    {
        if(target==sum)
        {
            fans.push_back(ans);
        }
        ans.push_back(candidates[i]);
        sum=sum+candidates[i];
        solve(candidates,target,ans,fans,i,sum);
        ans.pop_back();
        sum=sum-candidates[i];
        solve(candidates,target,ans,fans,i+1,sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target,int i) {
        vector<int> ans;
        vector<vector<int>> fans;
        solve(candidates,target,ans,fans,i,0);
        return fans;
        
    }
};
void solve(vector<int>& candidates,int target,vector<int> ans,vector<vector<int>> fans,int i,int sum)
    {
        if(target==sum)
        {
            fans.push_back(ans);
        }
        ans.push_back(candidates[i]);
        sum=sum+candidates[i];
        solve(candidates,target,ans,fans,i,sum);
        ans.pop_back();
        sum=sum-candidates[i];
        solve(candidates,target,ans,fans,i+1,sum);
    }