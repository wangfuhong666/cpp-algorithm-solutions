#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int>arr(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    deque<int>q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && arr[q.back()] >= arr[i])q.pop_back();
        q.push_back(i);
        if (q.back() - q.front() + 1 > k)q.pop_front();
        if (i >= k)cout << arr[q.front()] << ' ';
    }
    cout << '\n';
    q.clear();
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && arr[q.back()] <= arr[i])q.pop_back();
        q.push_back(i);
        if (q.back() - q.front() + 1 > k)q.pop_front();
        if (i >= k)cout << arr[q.front()] << ' ';
    }
    return 0;
}
