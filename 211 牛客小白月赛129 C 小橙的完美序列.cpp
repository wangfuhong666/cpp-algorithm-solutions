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
    unordered_map<int, int>mp;
    for (int i = 1; i <= n; i++)
    {
        int tem;
        cin >> tem;
        int x = tem ^ i;
        mp[x]++;
    }
    int res = INT_MIN;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        res = max(res, it->second);
    }
    cout << n - res;
    return 0;
}
