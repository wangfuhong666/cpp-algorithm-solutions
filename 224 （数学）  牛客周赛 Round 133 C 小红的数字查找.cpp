#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int facter(int x)
{
    int res = 1;
    for (int i = 2; (long long)i * i <= x; i++)
    {

        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt++;
                x /= i;
            }
            if (cnt % 2 == 1) res *= i;


        }
    }
    if (x > 1)res *= x;
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, l, r;
    cin >> x >> l >> r;
    int mn = facter(x);
    if (mn > r)cout << -1;
    else
    {
        int R = r / mn;
        int L = (l + mn - 1) / mn;
        int k = sqrt(R);
        while ((k + 1) * (k + 1) <= R) k++;
        while (k * k < L) k--;

        if (k * k >= L && k * k <= R) cout << k * k * mn;
        else cout << -1;

    }
    return 0;
}