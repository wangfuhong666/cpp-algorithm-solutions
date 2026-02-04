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
        long long maxnum = 0;
        vector<long long>arr(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            if (maxnum < arr[i])maxnum = arr[i];
        }
        if (n == 1)cout << arr[1] << '\n';
        else if (n == 2)cout << arr[1] + arr[2] << '\n';
        else cout << arr[1] + arr[n] + (n - 2) * maxnum << '\n';

    }
    return 0;
}