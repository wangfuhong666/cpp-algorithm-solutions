#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using PLI = pair<long long, int>;
bool cmp(long long val, const PLI p)
{
    return val < p.first;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<PLI>arr(n);
    for (int i = 0; i < n; i++)
    {
        long long val;
        cin >> val;
        arr[i] = { val,i + 1 };
    }
    sort(arr.begin(), arr.end());
    int l = 0, r = n - 1;
    for (int i = 0; i < n - 1; i++)
    {
        long long lv = arr[l].first;
        long long rv = arr[r].first;
        long long tmp = (lv + rv) / 2;
        auto it = upper_bound(arr.begin() + l, arr.begin() + r + 1, tmp, cmp);
        int cr = (int)distance(arr.begin() + l, it);
        int cl = (r - l + 1) - cr;
        if (cr >= cl)r--;
        else l++;
    }
    cout << arr[l].second;
    return 0;
}
