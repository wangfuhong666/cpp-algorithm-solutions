#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
vector<int>lis(vector<int>arr)
{
    int ret = 0;
    int n = arr.size() - 1;
    vector<int>dp(n + 1, 0);
    vector<int>res(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int x = arr[i];

        int l = 1, r = ret;
        if (ret == 0 || x > dp[ret])
        {

            dp[++ret] = x;
            res[i] = ret;
            continue;
        }
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (dp[mid] >= x)r = mid;
            else l = mid + 1;
        }
        dp[l] = x;
        res[i] = l;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n + 1);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    vector<int>f = lis(arr);
    reverse(arr.begin() + 1, arr.end());
    vector<int>g = lis(arr);
    int res = INT_MIN;
    for (int i = 1; i <= n; i++)res = max(res, f[i] + g[n - i + 1] - 1);
    cout << n - res;
    return 0;
}
