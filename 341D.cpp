#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    long long k = 0;
    long long c1 = 0, c2 = 1;
    int y = 0;
    for (int i = 0; i < n; i++)
    {
        long long v, l;
        cin >> v >> l;
        k += l;
        if (v % 2)
        {
            if (y)
            {
                c2 += (l + 1) / 2;
                c1 += l / 2;
            }
            else
            {
                c1 += (l + 1) / 2;
                c2 += l / 2;
            }
        }
        else
        {
            if (y)c1 += l;
            else c2 += l;
           
        }
        long long sum = v * l;
        int tem = sum % 2;
        y = (y + tem == 2 ? 0 : y + tem);
    }
    while (m--)
    {
        long long r;
        cin >> r;
        cout << min(r, 2 * min(c1, c2)) << ' ' << min(r, k - 1) << '\n';
    }
    return 0;
}
