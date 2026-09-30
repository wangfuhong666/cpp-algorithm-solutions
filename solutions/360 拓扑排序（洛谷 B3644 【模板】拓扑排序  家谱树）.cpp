#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
vector<int>adj[N];
vector<int>du(N, 0);
void topsort()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {

        while (1)
        {
            int x;
            cin >> x;
            if (!x)break;
            adj[i].push_back(x);
            du[x]++;
        }
    }
    queue<int>q;
    for (int i = 1; i <= n; i++)if (!du[i])q.push(i);
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        cout << c << ' ';
        for (auto e : adj[c])
        {
            du[e]--;
            if (!du[e])q.push(e);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    topsort();
    return 0;
}
