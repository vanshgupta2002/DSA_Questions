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
void solve(TreeNode* root,vector<vector<int>> &fans)
{
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty())
    {
        
        int size=q.size();
        vector<int> level;
        for(int i=0;i<size;i++)
        {
            TreeNode* front=q.front();
            q.pop();
            level.push_back(front->val);
            if(front->left)
            {
                q.push(front->left);
            }
            if(front->right)
            {
                q.push(front->right);
            }
        }
        fans.push_back(level);

    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> fans;
     
        solve(root,fans);
        return fans;
    }
};