#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n);
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        s ^= arr[i];
    }
    unordered_map<int, int>mp;
    long long  ans = 0;
    int pre = 0, suf = s^arr[0];
    for(int i = 1; i < n-1; i++)
    {
        pre ^= arr[i - 1];
        suf ^= arr[i];
        mp[pre]++;
        if (suf == s)ans += mp[s];
    }
    cout << ans;
    return 0;
}
