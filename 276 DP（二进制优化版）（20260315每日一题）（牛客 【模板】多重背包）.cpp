#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int log_2(long long x)
{
    int res = 0;
    while ((1LL << (res + 1)) <= x)res++;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int pos = 0;
    int n, w;
    cin >> n >> w;
    int tmp = log_2(20) + 1;
    vector<int> arrw(tmp*n + 1, 0), arrv(tmp*n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        int t = 1;
        while (x >= t)
        {
            pos++;
            arrw[pos] = t * y;
            arrv[pos] = t * z;
            x -= t;
            t *= 2;
        }
        if (x)
        {
            pos++;
            arrw[pos] = x * y;
            arrv[pos] = x * z;

        }
    }

    vector<vector<long long>>dp(tmp * n + 1, vector<long long>(w + 1));
    for (int i = 1; i <= pos; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arrw[i])dp[i][j] = max(dp[i][j], dp[i - 1][j - arrw[i]] + arrv[i]);
        }
    }
    cout << dp[pos][w];

    return 0;
}
