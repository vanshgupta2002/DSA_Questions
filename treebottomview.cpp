#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
class Solution {
  public:
 
    vector <int> bottomView(Node *root) {
       map<int,int> ans;
        vector<int> fans;
        queue<pair<Node *root,int>> q;
        q.push({root,0});
        while(!q.empty())
        {
            Node*temp = q.front().first;
            int level=q.front.second;
            q.pop();
            if(temp->left)
            {
                q.push({temp->left,level-1});
            }
            if(temp->right)
            {
                q.push({temp->right,level+1});
            }
            ans[level]=temp->data;
        }

        for(auto i:ans)
        {
            fans.push_back(i.second);
        }
        return fans;
        
    }
};