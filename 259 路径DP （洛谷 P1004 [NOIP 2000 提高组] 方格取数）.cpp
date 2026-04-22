#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>arr(n + 1, vector<int>(n + 1, 0));
    while (1)
    {
        int x, y, val;
        cin >> x >> y >> val;
        if (x == y && y == val && x == 0)break;
        arr[x][y] = val;
    }
    vector<vector<vector<vector<int>>>> dp(n+1, vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INT_MIN))));
    dp[1][1][1][1] = arr[1][1];
    for (int i1 = 1; i1 <= n; i1++)
    {
        for (int j1 = 1; j1 <= n; j1++)
        {
            for (int i2 = 1; i2 <= n; i2++)
            {
                for (int j2 = 1; j2 <= n; j2++)
                {
                    if (i1 == 1 && i2 == 1 && j1 == 1 && j2 == 1)continue;
                    if (i1 + j1 != i2 + j2)continue;
                    int tmp = INT_MIN;
                    if (i1 > 1 && i2 > 1)tmp = max(tmp, dp[i1 - 1][j1][i2 - 1][j2]);
                    if (i1 > 1 && j2 > 1)tmp = max(tmp, dp[i1 - 1][j1][i2][j2 - 1]);
                    if (j1 > 1 && i2 > 1)tmp = max(tmp, dp[i1][j1 - 1][i2 - 1][j2]);
                    if (j1 > 1 && j2 > 1)tmp = max(tmp, dp[i1][j1 - 1][i2][j2 - 1]);
                    if (tmp == INT_MIN) continue;
                    if (i1 == i2 && j1 == j2) dp[i1][j1][i2][j2] = tmp + arr[i1][j1];
                    else dp[i1][j1][i2][j2] = tmp + arr[i1][j1] + arr[i2][j2];
                }

            }
        }
    }
    cout << dp[n][n][n][n];
    return 0;
}
