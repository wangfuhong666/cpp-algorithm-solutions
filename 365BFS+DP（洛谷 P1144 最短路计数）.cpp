#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
const long long mod = 100003;
using ll = long long;
vector<ll>dist(N, LLONG_MAX/2);
vector<ll>dp(N, 0);
vector<int>adj[N];
int n;
void bfs(int x)
{
    queue<int>q;
    q.push(x);
    dist[x] = 0;
    dp[x] = 1;
    ll res = 0LL;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        for (auto a : adj[c])
        {
            if (dist[c] + 1 < dist[a])
            {
                dp[a] = dp[c];
                dist[a] = dist[c] + 1;
                q.push(a);
            }
            else if (dist[c] + 1 == dist[a])dp[a] = (dp[a] + dp[c]) % mod;
        }
    }
    for (int i = 1; i <= n; i++)cout << dp[i] << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bfs(1);
    return 0;
}
