#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ui = unsigned int;
void sol()
{
    string s;
    cin >> s;
    int n = (int)s.size();
    vector<int> z(n);
    vector<ui> pre(26);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (z[i] == n - i)
        {
            cout << "0\n";
            return;
        }
        int u = s[z[i]] - 'a';
        int v = s[i + z[i]] - 'a';
        pre[v] |= (1u << u);
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
    vector<ui> dp((1u << 26));
    dp[0] = 1;
    for (ui mask = 0; mask < (1u << 26); mask++)
    {
        if (dp[mask] == 0)
            continue;
        for (int i = 0; i < 26; i++)
        {
            if (mask & (1u << i))
                continue;
            if ((mask & pre[i]) != pre[i])
                continue;
            dp[mask | (1u << i)] += dp[mask];
        }
    }
    cout << dp[(1u << 26) - 1];
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
