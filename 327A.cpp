#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int dfs(string s, string t, int pos)
{
    auto it = s.find(t, pos);
    if (it == string::npos)return 0;
    return dfs(s, t, it + 1) + 1;
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
        int n;
        cin >> n;
        string t;
        cin >> t;
        string s = t + string(n, '0') + t;
        if (dfs(s, t, 0) == 2)
        {
            cout << string(n, '0') << '\n';
            continue;
        }
        s = t + string(n, '1') + t;
        if (dfs(s, t, 0) == 2)
        {
            cout << string(n, '1') << '\n';
            continue;
        }
        cout << -1 << '\n';
    }
    return 0;
}
