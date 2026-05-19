#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 600;
int n;
vector<int>adj[N];
vector<int>du(N, 0);
vector<bool>is(N, false);
int topsort()
{
    queue<int>q;
    for (int i = 1; i < N; i++)if (!du[i]&&is[i])q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        auto c = q.front();
        cnt++;
        q.pop();
        for (auto e : adj[c])
        {
            du[e]--;
            if (!du[e] && is[e])q.push(e);
        }
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    int m = n;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        is[x] = true;
        while (y--)
        {
            int u;
            cin >> u;
            adj[x].push_back(u);
            du[u]++;
        }
    }
    int res = topsort();
    if (res== n)cout << "YES";
    else cout << n - res;
    return 0;
}
