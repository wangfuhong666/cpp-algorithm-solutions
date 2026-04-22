#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e8;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, f;
    cin >> n >> f;
    vector<int>arrw(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrw[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(f , 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <f; j++)
        {
            dp[i][j] = dp[i - 1][j] % mod;;
            dp[i][j] = (dp[i][j] + dp[i - 1][(j - (arrw[i]) % f + f)% f] )% mod;
        }
    }
    cout << (dp[n][0] - 1 + mod) % mod;
    return 0;
}
