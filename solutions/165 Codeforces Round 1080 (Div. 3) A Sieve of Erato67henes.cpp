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
        bool judge = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 67)judge = true;
        }
        if (judge)cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
