#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
long long test(long long l, long long r, int k)
{
    long long p = 1;
    for (int i = 0; i < k - 1; i++)p *= 10;
    long long a = max(l, p), b = min(r, 10 * p - 1);
    if (a > b)return 0LL;
    long long res = 0LL, pos = p;
    for (int i = 0; i < k; i++)
    {
        for (int num = 9; num >= 0; num--)
        {
            long long tem1, tem2;
            if (a < num)tem1 = 0LL;
            else tem1 = (a - num + 10 - 1) / 10;

            if (b < num)tem2 = -1LL;
            else tem2 = (b - num) / 10;
            if (tem1 <= tem2)
            {
                res += num * pos;
                a = tem1; b = tem2;
                pos /= 10;
                break;
            }
        }
    }
    return res;
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long l, r;
        cin >> l >> r;
        int llen = to_string(l).size();
        int rlen = to_string(r).size();
        long long res = 0LL;
        for (int i = llen; i <= rlen; i++)res = max(res, test(l, r, i));
        cout << res << endl;
    }
    return 0;
}