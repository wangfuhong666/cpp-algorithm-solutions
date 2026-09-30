#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    long long res = 0LL;
    int l = 0;
    while (l < n) 
    {
        int r = l;
        while (r + 1 < n && s[r + 1] != s[r])r++;  
        long long len = r - l + 1;
        res = (res + (len * (len + 1) / 2)) % mod;
        l = r + 1;
    }
    cout << res % mod;
    return 0;
}
