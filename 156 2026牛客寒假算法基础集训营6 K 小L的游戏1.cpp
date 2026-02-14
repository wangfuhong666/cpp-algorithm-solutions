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
        long long m, n, z;
        cin >> m >> n >> z;
        long long x = 0LL;
        long long tem1 = m + n;
        long long tem2 = (z - 1) / tem1;
        long long tmp1 = tem2 * tem1;
        long long tmp2 = z - tmp1;
        if (m >= tmp2)cout << '0';
        else cout << '1';
    }
    return 0;
}