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
        vector<long long>f(n);
        for (auto& num : f)cin >> num;
        if (n == 2)
        {
            cout << f[1] << ' ' << f[0] << '\n';
            continue;
        }
        vector<long long>arr(n);
        long long k = 0, m = 0;
        for (int i = 1; i < n - 1; i++)
        {
            arr[i] = (f[i - 1] - 2 * f[i] + f[i + 1]) / 2;
            k += arr[i];
            m += arr[i] * i;
        }
        arr[n - 1] = (f[0] - m) / (n - 1);
        arr[0] = f[1] - f[0] + k + arr[n - 1];
        for (int i = 0; i < n; i++)
        {
            cout << arr[i];
            if (i < n - 1)cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}
