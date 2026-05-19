#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while(1)
    {
        int n, m;
        cin >> n >> m;
        if (!n && !m)break;
        vector<int>arrc(n + 1, 0), arrw(n + 1, 0);
        for (int i = 1; i <= n; i++)cin >> arrw[i];
        for (int i = 1; i <= n; i++)cin >> arrc[i];
        vector<bool>dp(m + 1, false);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            if (arrc[i] == 1)for (int j = m; j >= arrw[i]; j--)dp[j] = dp[j - arrw[i]] || dp[j];
            else if (arrc[i] * arrw[i] >= m)for (int j = arrw[i]; j <= m; j++)dp[j] = dp[j - arrw[i]] || dp[j];    
            else
            {
                for (int mod = 0; mod <= min(arrw[i] - 1, m); mod++)
                {
                    deque<int>q;
                    for (int j = mod; j <= m; j += arrw[i])
                    {
                        if (dp[j])q.push_back(j);
                        while (!q.empty() && j - q.front() > arrc[i] * arrw[i])q.pop_front();
                        dp[j] = !q.empty();

                    }
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++)if (dp[i])ans++;
        cout << ans << '\n';
    }
    return 0;
}
