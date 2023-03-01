#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void lot(TreeNode *root, vector<int> ans)
    {
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> fans;

        int flag = 1;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> ans;
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                TreeNode *front = q.front();
                q.pop();
                if (front->left)
                {
                    q.push(front->left);
                    ans.push_back(front->left->val);
                }
                if (front->right)
                {
                    q.push(front->right);
                    ans.push_back(front->right->val);
                }
            }
            if (flag == 1)
            {
                reverse(ans.begin(), ans.end());
            }
            fans.push_back(ans);
            if (flag == 1)
            {
                flag = 0;
            }
            else
                flag = 1;
        }
        return fans;
    }
};