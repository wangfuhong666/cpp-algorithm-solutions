#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>mp;
bool dfs(string& s, string& p, int i, int j)
{
    if (mp[i][j] != 2)return mp[i][j];
    if (i == s.size())
    {
        if (j == p.size())return mp[i][j] = true;
        else return mp[i][j] = (p[j] == '*') && dfs(s, p, i, j + 1);
    }
    else if (j == p.size())return mp[i][j] = false;
    else
    {
        if (p[j] != '*')return mp[i][j] = (s[i] == p[j] || p[j] == '?') && dfs(s, p, i + 1, j + 1);
        else return mp[i][j] = dfs(s, p, i, j + 1) || dfs(s, p, i + 1, j);
    }
}
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        mp.clear();
        int n = s.size();
        int m = p.size();
        mp.resize(n + 1, vector<int>(m + 1, 2));
        return dfs(s, p, 0, 0);
    }
};

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int j = m - 1; j >= 0; j--)dp[n][j] = (p[j] == '*') && dp[n][j + 1];
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (p[j] != '*')dp[i][j] = (p[j] == '?' || s[i] == p[j]) && dp[i + 1][j + 1];
                else dp[i][j] = dp[i][j + 1] || dp[i + 1][j];
            }
        }
        return dp[0][0];
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    return 0;
}
