#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, m,x,y;
const int  N = 40;
using PII = pair<int, int>;
vector<vector <char>> arr(N, vector <char>(N));
vector<vector <int>> dist(N, vector <int>(N,-1));
int dx[] = { 1,-1 ,0,0 };
int dy[] = { 0,0 ,1,-1 };
int ret = 0;
int ans = INT_MAX;
void bfs()
{
    queue<PII>q;
    q.emplace(x, y);
    dist[x][y] = 0;
    while (!q.empty())
    {
        PII p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (arr[nx][ny] == '*')continue;
            if (dist[nx][ny] != -1)continue;
            dist[nx][ny] = dist[x][y] + 1;
            if (arr[nx][ny] == 'e')
            {
                ret++;
                ans = min(ans, dist[nx][ny]);
                continue;
            }
            q.emplace(nx, ny);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'k')
            {
                x = i;
                y = j;
            }
        }
    }
    bfs();
    if (ret == 0)cout << -1;
    else cout << ret << ' ' << ans;
    return 0;
}
