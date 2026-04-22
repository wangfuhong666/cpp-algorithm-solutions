#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, h;
    cin >> n >> h;
    vector<int>arrp(n + 1, 0), arrc(n + 1, 0);
    //dp[i][j]     [1,i] >=j   wmin
    //dp[i][j]    j=10  a=15(pi=5)
    // abs=a-j (pi-1>=abs)
    // 至少这个限定条件（无法唯一确定当前状态）
    //dp[i][j]  =   dp[i-1][j] = dp[i-1][j+1] =dp[i-1][j+2] =dp[i-1][j+3]......dp[i-1][j+abs-1]
    //选第i家公司的干草
    // 选一包甘草：dp[i][j] = dp[i-1][j-p[i]]+w[i] = dp[i-1][j-p[i]+1]+w[i] = dp[i-1][j-p[i]+2] +w[i]= ...... = dp[i-1][j-1] +w[i]
    //选二包甘草：dp[i][j] = dp[i-1][j-2*p[i]]+2w[i] =dp[i-1][j-2p[i]+1]+2w[i] =dp[i-1][j-2w[i]+2]+2w[i] =......=dp[i-1][j-1] +2*w[i]
    //...
    //已经推出了矛盾(dp[i][j] =dp[i-1][j-1]+w[i]=dp[i-1][j-1]+2*w[i] =...=dp[i][j-1]+bw[i]
    //所以这种定义状态的方式是不正确的
    for (int i = 1; i <= n; i++)cin >> arrp[i] >> arrc[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(h + 1+5001, LLONG_MAX/2));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < h + 1 + 5001; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arrp[i])dp[i][j] = min(dp[i][j], arrc[i] + dp[i][j - arrp[i]]);
        }
    }
    long long res = LLONG_MAX;
    for (int j = h; j < h + 1 + 5001; j++)res = min(res,dp[n][j]);
    cout << res;
    return 0;
}
