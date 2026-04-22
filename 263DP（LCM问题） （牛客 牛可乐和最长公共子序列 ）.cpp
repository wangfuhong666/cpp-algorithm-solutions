#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (1)
    {
        string s, t;
        if (!(cin >> s >> t))break;
        cin.ignore();
        int n = s.size(), m = t.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (s[i] == t[j])dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
                ret = max(ret, dp[i + 1][j + 1]);
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
