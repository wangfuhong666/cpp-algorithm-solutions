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
    vector<int>arr(n + 1, 0), ret(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    stack<int>stk;
    for (int i = n; i >= 0; i--)
    {
        while (!stk.empty() && arr[stk.top()] <= arr[i])stk.pop();
        if (!stk.empty())ret[i] = stk.top();
        stk.push(i);
    }
    for (int i = 1; i <= n; i++)cout << ret[i] << ' ';
    return 0;
}
