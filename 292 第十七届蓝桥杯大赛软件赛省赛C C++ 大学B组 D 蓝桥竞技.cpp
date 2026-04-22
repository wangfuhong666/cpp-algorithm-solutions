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
        long long sum = 0;
        long long maxn = 0;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            sum += x;
            maxn = max(maxn, x);
        }
        if (sum % 5 || maxn>sum / 5)cout << 'F' << '\n';
        else cout << 'T' << '\n';
    }
    return 0;
}
