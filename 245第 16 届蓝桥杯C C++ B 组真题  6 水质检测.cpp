#include <bits/stdc++.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
const int N = 1e7 + 10;
int dist[2][N];
bool vis[2][N];
int setnum;
vector<string>arr(2);
using PII = pair<int, int>;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int bfs(int x, int y)
{
    int ret = -1;
    memset(dist, 0x3f, sizeof dist);
    memset(vis, false, sizeof vis);
    deque<PII>q;
    q.emplace_back(x, y);
    dist[x][y] = 0;
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop_front();
        if (vis[a][b])continue;
        vis[a][b] = true;
        if (arr[a][b] == '#')ret = max(ret, dist[a][b]);
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || nx >= 2 || ny < 0 || ny >= setnum)continue;
            if (vis[nx][ny])continue;
            if (arr[nx][ny] == '#')
            {
                dist[nx][ny] = min(dist[nx][ny], dist[a][b]);
                q.emplace_front(nx, ny);

            }
            else
            {
                dist[nx][ny] = min(dist[nx][ny], dist[a][b] + 1);
                q.emplace_back(nx, ny);
            }
        }
    }
    return ret;
}
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> arr[0] >> arr[1];
    int n = arr[0].size();
    setnum = n;
    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == '#')
        {
            cout << bfs(0, i);
            return 0;
        }
        if (arr[1][i] == '#')
        {
            cout << bfs(1, i);
            return 0;
        }
    }
    return 0;
}
