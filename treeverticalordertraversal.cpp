#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        unordered_map<int,map<int,vector<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty())
        {
            TreeNode* temp=q.front().first;
            int hd=q.front().second.first;
            int =q.front().second.second;
            q.pop();
            if(temp->left)
            {
                q.push({temp->left,{hd-1,level+1}});
            }
            if(temp->right)
            {
                q.push({temp->right,{hd+1,level+1}});
            }
            
        }
        vector<vector<int>> fans;
        for(auto i: mp)
        {
            for(auto j: i.second)
            {
                vector<int> ans;
               
                for (auto k: j.second)
                {
                    ans.push_back(k);
                }
                fans.push_back(ans);
                
            }
        }
        return ans;
    }
};