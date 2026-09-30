#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, x;
    cin >> n >> m >> x;
    vector<int>arra(n + 1), arrb(n + 1), arrc(n + 1);
    for (int i = 1; i <= n; i++)cin >> arra[i] >> arrb[i] >> arrc[i];
    vector<vector<long long>>dp(m + 1, vector<long long>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= arrb[i]; j--)
        {
            for (int k = x; k >= arrc[i]; k--)
            {
                dp[j][k] = max(dp[j][k], dp[j - arrb[i]][k - arrc[i]] + arra[i]);
            }
        }
    }
    cout << dp[m][x];
    return 0;
}
