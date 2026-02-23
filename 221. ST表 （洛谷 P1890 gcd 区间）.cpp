#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    while (b)
    {
        a %= b;
        swap(a, b);
    }
    return a;
}
int log2(int x)
{
    int res = 0;
    while ((1 << (res + 1)) <= x)res++;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int power = log2(n);
    vector<vector<int>>st(n + 1, vector<int>(power + 1, 0));
    for (int i = 1; i <= n; i++)cin >> st[i][0];
    for (int j = 1; j <= power; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i + (1 << j - 1) > n)continue;
            st[i][j] = gcd(st[i][j - 1], st[i+(1<<j-1)][j - 1]);
        }
    }
    while (m--)
    {
        int l, r;
        cin >> l >> r;
        int len = r - l + 1;
        int tem = log2(len);
        cout << gcd(st[l][tem], st[r - (1 << tem) + 1][tem]) << '\n';
    }
    return 0;
}
