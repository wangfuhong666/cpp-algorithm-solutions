#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ULL = unsigned long long;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        ULL n, x, y;
        cin >> n >> x >> y;
        if (x > y)cout << 0 << '\n';
        else cout << y - x + 1 << '\n';
    }
    return 0;
}
