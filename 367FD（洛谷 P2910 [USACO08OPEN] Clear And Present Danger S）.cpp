#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
using ll = long long;
vector<vector<ll>>dp(N, vector<ll>(N, LLONG_MAX / 2));
int n;
ll Floyd()
{
    int n, m;
    cin >> n >> m;
    vector<int>arr(m);
    for (auto& num : arr)cin >> num;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> dp[i][j];
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i < m; i++)res += dp[arr[i - 1]][arr[i]];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << Floyd();
    return 0;
}
