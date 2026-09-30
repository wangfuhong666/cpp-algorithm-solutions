#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N = 1e4 + 10;
class Solution {
private:
    vector<vector<pii>> adj = vector<vector<pii>>(N);
    vector<int> d = vector<int>(N);
    int n;
    static constexpr int LOG = 20;
    int st[N][LOG + 1];
    int cnt[N][27];
    // st[i][j] = st[st[i][j - 1]][j - 1]
    // st[i][j - 1] 在 i 的上方
    // 预处理 O(nlogn)
    void dfs(int u, int fa,int w)
    {
        d[u] = d[fa] + 1;  // 为了 LCA 服务
        st[u][0] = fa;
        for (int i = 1; i <= 26; i++)
        {
            cnt[u][i] = cnt[fa][i];
        }

        cnt[u][w]++;
        for (int j = 1; j <= LOG; j++)
        {
            st[u][j] = st[st[u][j - 1]][j - 1];
        }

        for (auto [v,wx] : adj[u])
        {
            if (v == fa) continue;
            dfs(v, u,wx);
        }
    }

    // 查询 O(logn)
    int lca(int u, int v)
    {
        if (d[u] < d[v]) swap(u, v);

        int k = d[u] - d[v];

        for (int i = LOG; i >= 0; i--)
        {
            if (k & (1 << i))
            {
                u = st[u][i];
            }
        }

        if (u == v) return u;

        for (int i = LOG; i >= 0; i--)
        {
            if (st[u][i] != st[v][i])
            {
                u = st[u][i];
                v = st[v][i];
            }
        }

        return st[u][0];
    }

public:
    vector<int> minOperationsQueries(int n,vector<vector<int>>& edges,vector<vector<int>>& queries)
    {
        for(int i = 0;i < n-1;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            u++;
            v++;
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }    
        this->n = n;
        dfs(1,0,0);
        int m = queries.size();

        vector<int>ans(m);
        for(int i = 0;i < m;i++)
        {
            int u = queries[i][0];
            int v = queries[i][1];
            u++;
            v++;
            int c = lca(u,v);
            int dis = d[u] + d[v] - 2*d[c];
            int mx = 0;
            for(int j = 1;j <=26 ;j++)
            {
                mx = max(cnt[u][j]  + cnt[v][j] - 2*cnt[c][j],mx);
            }
            ans[i] = dis - mx;
        }
        
        return ans;
    }
};