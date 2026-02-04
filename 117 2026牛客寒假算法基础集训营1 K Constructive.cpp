#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        if (n == 2 || n >= 4)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        if (n == 1)cout << 1 << endl;
        else cout << 1 << ' ' << 2 << ' ' << 3 << endl;
    }
    return 0;
}