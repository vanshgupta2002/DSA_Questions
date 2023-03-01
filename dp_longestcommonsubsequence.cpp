#include <bits/stdc++.h>
using namespace std;
int main()
{

    return 0;
}
class Solution
{
public:
    int ans(string text1, string text2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == text1.length() || j == text2.length())
        {
            return 0;
        }
        int left = 0;
        int right = 0;
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        if (text1[i] == text2[j])
        {
            left = 1 + ans(text1, text2, i + 1, j + 1, dp);
        }
        right = max(ans(text1, text2, i + 1, j, dp), ans(text1, text2, i, j + 1, dp));
        return dp[i][j] = max(left, right);
    }
    int longestCommonSubsequence(string text1, string text2)
    {
        int i = 0;
        int j = 0;

        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, 0));
        for (int i = text1.length() - 1; i >= 0; i++)
        {
            for (int j = text2.length() - 1; j >= 0; j++)
            {
                int left=0;
                int right=0;

                if (text1[i] == text2[j])
                {
                    left = 1 + dp[i + 1][j + 1];
                }
                right = max(dp[i + 1][j], dp[i][j + 1]);
                dp[i][j] = max(left, right);
            }
        }
         return dp[0][0];
    }
   
}

;