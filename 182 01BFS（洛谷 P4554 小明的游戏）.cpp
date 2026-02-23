#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
using PII = pair<int, int>;
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[N][N];
char arr[N][N];
int x, y, tx, ty;
void bfs()
{
    deque<PII>q;
    q.emplace_back(x, y);
    dist[x][y] = 0;
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop_front();   
        if (a == tx && b == ty)
        {
            cout << dist[a][b] << '\n';
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (arr[nx][ny] == arr[a][b] && dist[a][b] < dist[nx][ny])
            {
                dist[nx][ny] = dist[a][b];
                q.emplace_front(nx, ny);
            }
            if (arr[nx][ny] != arr[a][b] && dist[a][b] + 1 < dist[nx][ny])
            {
                dist[nx][ny] = dist[a][b] + 1;
                q.emplace_back(nx, ny);
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    while (true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)break;
        fill((int*)dist, (int*)dist + N * N, 0x3f3f3f3f);
        for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
        cin >> x >> y >> tx >> ty;
        bfs();


    }
    return 0;
}
