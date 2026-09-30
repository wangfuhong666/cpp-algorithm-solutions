#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e1 + 10;
int arr[N][N];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int n, m;
void dfs(int i, int j)
{
    arr[i][j] = 0;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];
        if (x<0 || x>=n || y<0 || y>=m)continue;
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
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
    for (int i = 0; i < n; i++)
    {
        if (arr[i][0])dfs(i, 0);
        if (arr[i][m - 1])dfs(i, m - 1);
    }
    for (int j = 0; j < m; j++)
    {
        if (arr[0][j])dfs(0, j);
        if (arr[n - 1][j])dfs(n - 1, j);
    }
    int res = 0;
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)if (arr[i][j])res++;
    cout << res;
    return 0;
}
