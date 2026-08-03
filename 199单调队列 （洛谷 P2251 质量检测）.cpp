#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>arr(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    deque<int>q;
    for (int i = 1; i <= n; i++)
    {
        while (!q.empty() && arr[q.back()] >= arr[i])q.pop_back();
        q.push_back(i);
        if (q.back() - q.front() + 1 > m)q.pop_front();
        if(i>=m)cout << arr[q.front()] << '\n';
    }
    return 0;
}
