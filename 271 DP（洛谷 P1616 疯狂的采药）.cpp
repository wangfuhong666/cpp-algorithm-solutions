#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    cin >> t >> n;
    vector<int>arrt(n + 1, 0), arrw(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrt[i] >> arrw[i];
    vector<long long>dp(t + 1, 0LL);
    for (int i = 1; i <= n; i++)
    {
        for (int j = arrt[i]; j <= t; j++)dp[j] = max(dp[j], arrw[i]+dp[j - arrt[i]]);
   
    }
    cout << dp[t];
    return 0;
}
