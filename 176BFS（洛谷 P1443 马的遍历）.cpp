#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, m, x, y;
const int N = 410;
using PII = pair<int, int>;
vector<vector<int>>dist(N, vector<int>(N, -1));
int dx[] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[] = { 2,1,-1,-2,-2,-1,1,2 };
void bfs()
{
    queue<PII>q;
    q.emplace(x, y);
    dist[x][y] = 0;
    while (!q.empty())
    {
        PII p = q.front();
        int x = p.first;
        int y = p.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (dist[nx][ny] != -1)continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> x >> y;
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)cout << dist[i][j] << ' ';
        cout << '\n';
    }
 
    return 0;
}
