#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)break;
        vector<int>arr(n + 1, 0), l(n + 1, 0), r(n + 1, n+1);
        for (int i = 1; i <= n; i++)cin >> arr[i];
        stack<int>stk;
        for (int i = 1; i <= n; i++)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])stk.pop();
            if (!stk.empty())l[i] = stk.top();
            stk.push(i);
        }
        while (!stk.empty())stk.pop();
        for (int i = n ;i >= 1;i--)
        {
            while (!stk.empty() && arr[stk.top()] >= arr[i])stk.pop();
            if (!stk.empty())r[i] = stk.top();
           
            stk.push(i);
        }
        long long ans = 0LL;
        for (int i = 1; i <= n; i++)ans = max(ans, 1LL * arr[i] * (r[i] - l[i] - 1));
        cout << ans << '\n';

    }
    return 0;
}
