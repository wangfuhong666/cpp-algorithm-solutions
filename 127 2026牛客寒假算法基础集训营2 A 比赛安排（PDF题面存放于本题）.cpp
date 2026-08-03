#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        long long cnt = a;
        cnt = max(cnt, b);
        cnt = max(cnt, c);
        long long res = a;
        res = min(res, b);
        res = min(res, c);
        if (cnt - res <= 1)cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
