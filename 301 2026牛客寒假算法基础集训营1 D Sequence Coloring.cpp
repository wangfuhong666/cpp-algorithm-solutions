#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, k;
const int N = 5e5 + 10;
vector<int>arr;
vector<int>ne;
bool check(int mid)
{
    int l = 1;
    while (l <= n && arr[l] == 0)l++;
    int ans = 1;
    int time = 0;
    while (l <= n)
    {
        time++;
        l = ne[l];
        if (l >= n)break;
        if (ne[l] == l)
        {
            while (l <= n && ne[l] == l)l++;
            if (l <= n)
            {
                ans++;
                time = 0;
            }
        }
        else
        {
            if (time == mid)
            {
                l++;
                while (l <= n && arr[l] == 0)l++;
                if (l <= n)
                {
                    ans++;
                    time = 0;
                }
            }
        }
    }
    return ans <= k;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> k;
        arr.clear();
        arr.resize(n + 2);
        ne.clear();
        ne.resize(n + 2);
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (arr[i])cnt++;
        }
        if (cnt <= k)
        {
            cout << 0 << '\n';
            continue;
        }
        for (int i = 1; i <= n; i++)ne[i] = max(ne[i - 1], arr[i] + i);
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check(mid))r = mid;
            else l = mid + 1;
        }
        if (!check(n))cout << -1 << '\n';
        else cout << l << '\n';

    }
    return 0;
}
