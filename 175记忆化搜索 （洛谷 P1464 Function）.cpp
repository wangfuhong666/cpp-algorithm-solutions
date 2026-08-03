#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using PLLL = pair<pair<long long, long long>, long long>;
map<PLLL, long long>mp;
long long dfs(long long a, long long b, long long c)
{
   
    PLLL p = { {a, b}, c };
    
    if (a <= 0 || b <= 0 || c <= 0)return 1;
    if (a > 20 || b > 20 || c > 20)return dfs(20, 20, 20);
    if (mp.count(p))return mp[p];
    if (a < b && b < c)return mp[p] = dfs(a, b, c - 1) + dfs(a, b - 1, c - 1) - dfs(a, b - 1, c);
    else return mp[p] = dfs(a - 1, b, c) + dfs(a - 1, b - 1, c) + dfs(a - 1, b, c - 1) - dfs(a - 1, b - 1, c - 1);
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long a, b, c;
    while ((cin >> a >> b >> c) && (a != -1 || b != -1 || c != -1))
    {
        cout << "w(" << a << ", " << b << ", " << c << ") = " << dfs(a, b, c) << '\n';
    }
    return 0;
}
