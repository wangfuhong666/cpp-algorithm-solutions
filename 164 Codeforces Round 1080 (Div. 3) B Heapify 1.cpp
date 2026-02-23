#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int get(int x)
{
    while (x % 2 == 0)x /= 2;
    return x;
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
        int n;
        cin >> n;
        bool judge = true;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (get(x) != get(i))judge = false;
        }
        if (judge)cout << "YES" << "\n";
        else cout << "NO" << '\n';
    }
    return 0;
}
