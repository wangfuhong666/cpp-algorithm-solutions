#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>arrv(n + 1, 0), arrw(n + 1, 0), arrc(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrv[i] >> arrw[i] >> arrc[i];
    vector < vector < long long>>dp(n + 1, vector<long long>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int mod = 0; mod <= min(m, arrw[i] - 1); mod++)
        {
            deque<int>q;
            for (int j = mod; j <= m; j += arrw[i])
            {
                while (!q.empty() && dp[i - 1][q.back()] - q.back() / arrw[i] * arrv[i] < dp[i - 1][j] - j / arrw[i] * arrv[i])q.pop_back();
                q.push_back(j);
                while (!q.empty() && (j - q.front()) / arrw[i] > arrc[i]) q.pop_front();
                dp[i][j] = 1LL*j / arrw[i] * arrv[i] + dp[i - 1][q.front()] - q.front() / arrw[i] * arrv[i];
            }
        }
    }
    cout << dp[n][m];
    return 0;
}
