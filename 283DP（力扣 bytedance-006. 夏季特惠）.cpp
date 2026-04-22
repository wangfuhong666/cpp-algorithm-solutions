#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    long long x;
    cin >> n >> x;
    long long ans = 0LL;
    int pos = 0;
    vector<int>arr(1, 0);
    vector<long long>arrw(1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        long long w;
        cin >> a >> b >> w;
        if (a - 2 * b >= 0)
        {
            x += a - 2 * b;
            ans += w;
        }
        else
        {
            pos++;
            arr.push_back(-(a - 2 * b));
            arrw.push_back(w);
        }
    }
    vector<long long>dp(x + 1, 0);
    for (int i = 1; i <= pos; i++)for (int j = x; j >= arr[i]; j--)dp[j] = max(dp[j], arrw[i] + dp[j - arr[i]]);
    cout << ans + dp[x];
    return 0;
}
