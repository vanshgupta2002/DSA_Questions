#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(string word1, string word2, int i, int j, vector<vector<int>> &dp)
    {
        if (i == word1.length())
        {
            return word2.length() - j;
        }
        if (j == word2.length())
        {
            return word1.length() - i;
        }
        if (dp[i][j] != -1)
        {
            return dp[i][j];
        }
        int ans = 0;
        if (word1[i] == word2[j])
        {
            return solve(word1, word2, i + 1, j + 1, dp);
        }

        else
        {
            int ins = 1 + solve(word1, word2, i, j + 1, dp);
            int del = 1 + solve(word1, word2, i + 1, j, dp);
            int rep = 1 + solve(word1, word2, i + 1, j + 1, dp);
            dp[i][j] = min(ins, min(del, rep));
        }
        return dp[i][j];
    }
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> dp(word1.length(), vector<int>(word2.length(), -1));
        for (int j = 0; j < word2.length(); j++)
        {
            dp[word1.length()][j] = word2.length() - j;
        }
        for (int i = 0; i < word1.length(); i++)
        {
            dp[i][word2.length()] = word2.length() - i;
        }
        for (int i = word1.length() - 1; i >= 0; i++)
        {
            for (int j = word2.length() - 1; j >= 0; j++)
            {
                int ans = 0;
                if (word1[i] == word2[j])
                {
                    ans=dp[i+1][j+1];
                }

                else
                {
                    int ins = 1 + dp[i][j+1];
                    int del = 1 + dp[i+1][j];
                    int rep = 1 + dp[i+1][j+1];
                    dp[i][j] = min(ins, min(del, rep));
                }
              
                
            }
        }
        return dp[0][0];
        //return solve(word1, word2, 0, 0, dp);
    }
};