#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
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
        string s;
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        for (auto e : s)
        {
            if (e == '(')cnt1++;
            else cnt2++;
        }
        if (cnt1 == cnt2)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
