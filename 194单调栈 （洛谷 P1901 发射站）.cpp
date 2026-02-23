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
    vector<long long >h(n), v(n), ans(n, 0), ret1(n, -1), ret2(n, -1);
    for (int i = 0; i < n; i++)cin >> h[i] >> v[i];
    stack<long long>stk1, stk2;
    for (int i = 0; i < n; i++)
    {
        while (!stk1.empty() && h[stk1.top()] <= h[i])stk1.pop();
        if (!stk1.empty())ret1[i] = stk1.top();
        stk1.push(i);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        while (!stk2.empty() && h[stk2.top()] <= h[i])stk2.pop();
        if (!stk2.empty())ret2[i] = stk2.top();
        stk2.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        if (ret1[i] != -1)ans[ret1[i]] += v[i];
        if (ret2[i] != -1)ans[ret2[i]] += v[i];
    }
    cout << *max_element(ans.begin(), ans.end());
    return 0;
}
