#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int>du(N, 0);
vector<vector<int>>adj(N);
vector<bool>vis(N, false);
int n;
vector<int>path;
vector<int>idx;
int bfs()
{

    queue<int>q;
    for (auto x : idx)q.push(x);
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        path.push_back(a);
        for (auto e : adj[a])
        {
            du[e]--;
            if (!du[e])q.push(e);
        }
    }
    return path.size();
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
        du[v]++;
    }

    for (int i = 0; i < n; i++) if (!du[i])idx.push_back(i);
    if (bfs() != n)cout << -1;
    else for (int i = 0; i < path.size(); i++)cout << path[i] << (i < path.size() - 1 ? " " : "");
    return 0;
}
