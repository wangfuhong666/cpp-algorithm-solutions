#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
void sol()
{
    string t;
    cin >> t;
    string s = "#";
    for (auto e : t)
    {
        s += e;
        s += "#";
    }
    int n = s.size();
    vector<int> p(n, 0);
    int l = 0, r = 0;
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            p[i] = min(r - i, p[l + r - i]);
        if (i + p[i] >= r)
        {
            l = i - p[i];
            r = i + p[i];
            while (l && r + 1 < n && s[l - 1] == s[r + 1])
            {
                l--;
                r++;
                p[i]++;
            }
        }
        res = max(res, p[i]);
    }
    cout << res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
