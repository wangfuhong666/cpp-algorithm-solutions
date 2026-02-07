#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
int bitwei(long long n)
{
    int cnt = 0;
    while (n)
    {
        cnt++;
        n >>= 1;
    }
    return cnt;
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
        long long n, x, y;
        cin >> n;
        int tem = bitwei(n);
        x = n << tem;
        y = x | n;
        cout << x << ' ' << y << '\n';
    }
    return 0;
}