#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 3e1 + 10;
using PII = pair<int, int>;
int arr[N][N];
bool memo[N][N];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
void bfs(int x, int y)
{
    queue<PII>q;
    q.emplace(x, y);
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx<0 || nx>n + 1 || ny<0 || ny>n + 1)continue;
            if (memo[nx][ny])continue;
            if (arr[nx][ny] != 0)continue;
            memo[nx][ny] = true;
            q.emplace(nx, ny);

        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(arr, 0, sizeof arr);
    memset(memo, false, sizeof memo);
    cin >> n;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= n; j++)cin >> arr[i][j];
    bfs(0, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (memo[i][j])cout << 0 << ' ';
            else
            {
                if (arr[i][j] == 0)cout << 2 << ' ';
                else cout << arr[i][j] << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
