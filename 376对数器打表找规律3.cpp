#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
unordered_map<int, unordered_map<int, bool>>mp;

bool dfs(int n, int start)
{
    if (mp.count(n) && mp[n].count(start))return mp[n][start];
    int res = 0;
    for (int i = start; i < n; i++)
    {
        res += i;
        if (res == n)return mp[n][start] = true;
        else if (res > n && dfs(n, start + 1))return mp[n][start] = true;
        
       
    }
    return  mp[n][start] = false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)if (!dfs(i, 1))cout << i << " : " << "F" << '\n';
    
    return 0;
}
