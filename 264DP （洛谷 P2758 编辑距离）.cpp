#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++)dp[i][0] = i;
    for (int j = 0; j < m; j++)dp[0][j] = j;
    for (int i = 0; i < n; i++)
    {
        for (int  j = 0; j < m; j++)
        {
            int ret = INT_MAX;
            if (s[i] == t[j])ret = dp[i][j];
            else ret = min(min(dp[i + 1][j], dp[i][j + 1]), dp[i][j]) + 1;
            dp[i + 1][j + 1] = ret;
            
        }
    }
    cout << dp[n][m];
    return 0;
}
