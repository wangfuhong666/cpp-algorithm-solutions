#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll mod = 1e8;
int n, m;
vector<vector<int>> a(13, vector<int>(13, 0));
// 返回s中第j列的信息
int getinfo(int s, int j)
{
    return (s >> j) & 1;
}
void sol()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    vector<vector<ll>> dp( m + 1,vector<ll>(1 << m, 0));
    vector<int>pre((1LL<<m),0);
    for (int mask = 0; mask < (1 << m); mask++)
    {
        pre[mask]= 1;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int mask = 0; mask < (1 << m); mask++)
        {
            dp[m][mask] = pre[mask];
        }
        for (int j = m - 1; j >= 0; j--)
        {
            for (int mask = 0; mask < (1 << m); mask++)
            {
                ll ans = dp[j + 1][ mask & ~(1 << j)];
                if ((j == 0 || getinfo(mask, j - 1) == 0)&&getinfo(mask, j) == 0&&a[i][j] == 1)
                {
                    ans +=dp[j + 1][mask | (1 << j)];
                }
                dp[j][mask] = ans % mod;
            }
        }
         for (int mask = 0; mask < (1 << m); mask++)
        {
            pre[mask] = dp[0][mask];
        }       
    }

    cout << dp[0][0] % mod << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
