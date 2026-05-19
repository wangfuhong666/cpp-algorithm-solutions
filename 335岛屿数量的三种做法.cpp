//dfs
#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e1 + 10;
int arr[N][N];
bool vis[N][N];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int n, m;
void dfs(int i, int j)
{
    vis[i][j] = true;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x<0 || x>n || y<0 || y>m)continue;
        if (vis[x][y])continue;
        if (!arr[x][y])continue;
        dfs(x, y);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    memset(arr, 0, sizeof arr);
    memset(vis, false, sizeof vis);
    int res = 0;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (arr[i][j] && !vis[i][j])
            {
                res++;
                dfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}







//bfs
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;
const int N = 5e1 + 10;
int arr[N][N];
bool vis[N][N];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
void bfs(int i, int j)
{
    queue<PII> q;
    q.emplace(i, j);
    while (!q.empty())
    {
        auto& [a, b] = q.front();
        q.pop();
        if (vis[a][b])continue;
        vis[a][b] = true;
        for (int k = 0; k < 4; k++)
        {
            int x = a + dx[k];
            int y = b + dy[k];
            if (x < 0 || x > n || y < 0 || y > m) continue;
            if (vis[x][y])continue;
            if (!arr[x][y])continue;
            q.emplace(x, y);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    memset(arr, 0, sizeof arr);
    memset(vis, false, sizeof vis);
    int res = 0;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (arr[i][j] && !vis[i][j])
            {
                res++;
                bfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}







//并查集
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 60;
int fa[N];
int arr[60][60];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
void start(int n)
{
    for (int i = 0; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (x == fa[x])return x;
    return fa[x] = find(fa[x]);
}
bool un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)return false;
    fa[fx] = fy;
    return true;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    start(n * m + 1);
    memset(arr, 0, sizeof arr);
    int res = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j])
            {
                res++;
                for (int k = 0; k < 4; k++)
                {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (x < 0 || x >= n || y < 0 || y >= m) continue;
                    if (!arr[x][y])continue;
                    if (un(i * m + j, x * m + y))res--;
                }
            }
        }
    }
    cout << res;
    return 0;
}
