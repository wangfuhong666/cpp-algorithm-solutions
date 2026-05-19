#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
string f(ll x)
{
    string res = "";
    while (x)
    {
        res += x % 5 + '0';
        x /= 5;
    }
    reverse(res.begin(), res.end());
    return res == "" ? "0" : res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x;
    cin >> x;
    string s = f(x - 1);
    string res = "";
    for (auto e : s)
    {
        res += (e - '0') * 2 + '0';
    }
    cout << res;
    return 0;
}
