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
        vector<long long>arr(n);
        unordered_map<long long, int>mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]]++;
        }
        long long maxn = *max_element(arr.begin(), arr.end());
        int cnt = mp[maxn];
        for (int i = 0; i < n; i++)
        {
            if (cnt % 2 == 1)
            {
                if (arr[i] == maxn)cout << '1';
                else cout << '0';
            }
            else
            {
                if (arr[i] == maxn)cout << '0';
                else cout << '1';
            }
        }
        cout << '\n';

    }


    return 0;
}