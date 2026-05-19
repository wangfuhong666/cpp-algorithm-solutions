#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //dp[i][j]={ a[i]*(n-len+1) +dp[i+1][j]
    //         { a[j]*(n-len+1) + dp[i][j-1]
    int n;
    cin >> n;
    vector<int>arr(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    vector<vector<long long>>dp(n + 2, vector<long long>(n + 2, 0));
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            int tem = n - len + 1;
            dp[i][j] = max(tem * arr[i] + dp[i + 1][j], tem * arr[j] + dp[i][j - 1]);
        }
    }
    cout << dp[1][n];
    return 0;
}
