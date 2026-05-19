#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int s, n, m;
    cin >> s >> n >> m;
    vector<vector<int>>arr(n + 1, vector<int>(s + 1, 0));
    for (int j = 1; j <= s; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i][j];
            arr[i][j] = arr[i][j] * 2 + 1;
        }
    }
    for (int i = 1; i <= n; i++)sort(arr[i].begin() + 1, arr[i].end());
    vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= s && j - arr[i][k] >= 0; k++)dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i][k]] + k * i);
        }
    }
    cout << dp[n][m];
    return 0;
}
