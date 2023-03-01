#include<bits/stdc++.h>
using namespace std;
int main()
{

return 0;
}
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp;
        int min=INT_MAX;
        for(int i=0;i<cards.size();i++)
        {
            if(mp.find(cards[i])!=mp.end())
            {
                min=i-mp[cards[i]];
                cards[i]=i;
            }
        }
        return min;
    }
};