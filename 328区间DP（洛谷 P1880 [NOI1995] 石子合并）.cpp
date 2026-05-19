#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(2 * n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    vector<long long>pre(2 * n + 1, 0);
    for (int i = 1; i <= 2 * n; i++)pre[i] = pre[i - 1] + arr[i];
    vector<vector<long long>>dpmin(2 * n + 1, vector<long long>(2 * n + 1, LLONG_MAX / 2)), dpmax(2 * n + 1, vector<long long>(2 * n + 1, LLONG_MIN / 2));
    for (int i = 1; i <= 2 * n; i++)dpmin[i][i] = dpmax[i][i] = 0LL;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= 2 * n; i++)
        {
            int j = i + len - 1;
            long long sum = pre[j] - pre[i - 1];
            for (int k = i; k < j; k++)
            {
                dpmin[i][j] = min(dpmin[i][j], dpmin[i][k] + dpmin[k + 1][j] + sum);
                dpmax[i][j] = max(dpmax[i][j], dpmax[i][k] + dpmax[k + 1][j] + sum);
            }
        }
    }
    long long minn = LLONG_MAX, maxn = LLONG_MIN;
    for (int i = 1; i <= n; i++)
    {
        maxn = max(maxn, dpmax[i][i + n - 1]);
        minn = min(minn, dpmin[i][i + n - 1]);
    }
    cout << minn << '\n' << maxn;
    return 0;
}