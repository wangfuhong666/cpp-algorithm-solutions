#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 80112002;
const int N = 5e3 + 10;
int n;
vector<int>adj[N];
vector<int>du(N, 0);
vector<long long>dp(N, 0);
vector<int>outdu;
long long topsort()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        du[v]++;
    }
    queue<int>q;/
    for (int i = 1; i <= n; i++)
    {
        if (du[i]&&adj[i].size() == 0)outdu.push_back(i);
        if (!du[i])
        {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (auto e : adj[c])
        {
            dp[e] = (dp[e] + dp[c]) % mod;
            du[e]--;
            if (!du[e])q.push(e);
        }
    }
    long long res = 0LL;
    for (auto i : outdu) res = (res + dp[i]) % mod;
    return res;
   
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << topsort();

    return 0;
}
