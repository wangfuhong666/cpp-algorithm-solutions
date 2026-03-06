#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
const int N = 1e6 + 10;
ULL f[N];
ULL p[N];
void stringhash(string s, int p1)
{
    int n = s.size();
    f[0] = 0;
    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        f[i] = f[i - 1] * p1 + s[i - 1];
        p[i] = p[i - 1] * p1;
    }
}
//查找字符串在[l,r]（下标从1开始计数）的哈希值
ULL findhash( int l, int r)
{
    return f[r] - f[l - 1] * p[r - l + 1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    int m;
    cin >> s >> m;
    stringhash(s, 13331);
    while(m--)
    {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (findhash(l1, r1) == findhash(l2, r2))cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
