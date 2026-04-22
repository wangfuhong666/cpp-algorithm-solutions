#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    if (n <= 2)cout << n;
    else
    {
        vector<long long>dp(n + 1, 1LL);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; i++)dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        cout << dp[n];
    }
    return 0;
}
