#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>dp(n + 1, 0);
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        int l = 1, r = ret;
        if (ret == 0 || x > dp[ret])
        {

            dp[++ret] = x;
            continue;
        }
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (dp[mid] >= x)r = mid;
            else l = mid + 1;
        }
        dp[l] = x;
    }
    cout << ret;
    return 0;
}
