#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//递归写法（TLE）
bool dfs(string s, string p, int i, int j)
{
    if (i == s.size())
    {
        if (j == p.size())return true;
        else
        {
            if (j + 1 == p.size())return false;
            else return p[j + 1] == '*' && dfs(s, p, i, j + 2);
        }
    }
    else if (j == p.size()) return false;
    else
    {
        if (j + 1 == p.size() || p[j + 1] != '*')return (p[j] == '.' || s[i] == p[j]) && dfs(s, p, i + 1, j + 1);
        else
        {
            bool j1 = dfs(s, p, i, j + 2);
            bool j2 = (p[j] == '.' || s[i] == p[j]) && dfs(s, p, i + 1, j);
            return j1 || j2;
        }
    }
}
//记忆化搜索写法
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        return dfs(s, p, 0, 0);
    }
};
unordered_map<int, unordered_map<int, bool>>mp;
bool dfs(string s, string p, int i, int j)
{
    if (mp.count(i) && mp[i].count(j))return mp[i][j];
    if (i == s.size())
    {
        if (j == p.size())return mp[i][j] = true;
        else
        {
            if (j + 1 == p.size())return mp[i][j] = false;
            else return mp[i][j] = p[j + 1] == '*' && dfs(s, p, i, j + 2);
        }
    }
    else if (j == p.size()) return mp[i][j] = false;
    else
    {
        if (j + 1 == p.size() || p[j + 1] != '*')return mp[i][j] = (p[j] == '.' || s[i] == p[j]) && dfs(s, p, i + 1, j + 1);
        else
        {
            bool j1 = dfs(s, p, i, j + 2);
            bool j2 = (p[j] == '.' || s[i] == p[j]) && dfs(s, p, i + 1, j);
            return mp[i][j] = j1 || j2;
        }
    }
}
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        mp.clear();
        return dfs(s, p, 0, 0);
    }
};
//迭代写法（DP）
class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n + 1, vector<bool>(m + 1, false));
        dp[n][m] = true;
        for (int j = m - 2; j >= 0; j--)dp[n][j] = (p[j + 1] == '*') && dp[n][j + 2];
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (j + 1 == m || p[j + 1] != '*')dp[i][j] = (p[j] == '.' || s[i] == p[j]) && dp[i + 1][j + 1];
                else dp[i][j] = dp[i][j + 2] || ((p[j] == '.' || s[i] == p[j]) && dp[i + 1][j]);
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
