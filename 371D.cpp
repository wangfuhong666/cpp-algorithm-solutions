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
    vector<int>arr(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    vector<int>dp1(n + 1, 1), dp2(n + 1, 1);
    for (int i = 2; i <= n; i++)dp1[i] = min(dp1[i - 1] + 1, arr[i]);
    for (int i = n - 1; i >= 1; i--)dp2[i] = min(dp2[i + 1] + 1, arr[i]);
    int res = 0;
    for (int i = 1; i <= n; i++)res = max(res, min(dp1[i], dp2[i]));
    cout << res;
    return 0;
}
