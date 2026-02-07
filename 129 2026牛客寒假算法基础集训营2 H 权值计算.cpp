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
        vector<long long>arr(n + 1, 0);
        for (int i = 1; i <= n; i++)cin >> arr[i];
        unordered_map<long long, long long>mp;
        long long sum = 0LL;
        for (int i = 1; i <= n; i++)
        {

            long long idx = mp[arr[i]];
            sum += (i - idx) * 1LL * (n - i + 1) * (n - i + 2) / 2;
            mp[arr[i]] = i;
        }
        cout << sum << '\n';
    }
    return 0;
}