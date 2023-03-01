#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        vector<int> v1(26,0);
        int len=s1.length();
        vector<int> v2(26,0);
        for(int i=0;i<len;i++)
        {
            v1[s1[i]-'a']++;
        }
        int end;
        for(end=0;end<len;end++)
        {
            v2[s2[end]-'a']++;

        }
        int j=0;
        if(v1==v2)
        return true;
        end++;
        while(end<s2.length())
        {
           
            v1[s1[j]-'a']--;
            v1[s1[end]-'a']++;
            if(v1==v2)
            {
                return true;
            }
            end++;
        }
    }
};