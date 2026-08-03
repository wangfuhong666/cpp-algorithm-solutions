#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using PIL = pair<int, long long>;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>arrv(n + 1, 0), arrw(n + 1, 0), arrc(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrv[i] >> arrw[i] >> arrc[i];
   vector < long long>dp(m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int mod = 0; mod <= min(m, arrw[i] - 1); mod++)
        {
            //空间压缩时单调队列里面不仅要存下标也要存旧值
            deque<PIL>q;
            for (int j = mod; j <= m; j += arrw[i])
            {
                long long val = dp[j] - j / arrw[i] * arrv[i];            
                while (!q.empty() && q.back().second <val)q.pop_back();
                q.emplace_back(j,val);
                while (!q.empty() && (j - q.front().first) / arrw[i] > arrc[i]) q.pop_front();
                long long newn = q.front().second;
                dp[j] = 1LL * j / arrw[i] * arrv[i] + newn;
            }
        }
    }
    cout << dp[m];
    return 0;
}
