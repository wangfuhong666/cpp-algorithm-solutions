#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using LD = long double;
struct node
{
    LD p;
    long long v;
    long long w;
};
bool cmp(node a, node b)
{
    return a.v < b.v;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        vector<node>arr(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x >> arr[i].v >> arr[i].w;
            arr[i].p = x / 100.0;
        }
        sort(arr.begin() + 1, arr.end(), cmp);
        vector<LD>dp(m + 1, 0.0);
        for (int i = 1; i <= n; i++)
        {
            for (int j = m; j >= arr[i].w; j--)
            {
                dp[j] = max(dp[j], arr[i].p * arr[i].v + dp[j - arr[i].w] * (1 - arr[i].p));
            }
        }
        printf("%.12Lf\n", dp[m]);
    }

    return 0;
}
