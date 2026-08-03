#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 * 1e2 + 10;
int fa[N];
char arr[N][N];
void start(int n)
{
    for (int i = 0; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return  fa[x] = find(fa[x]);
}
bool un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);;
    if (fx != fy)
    {
        fa[fx] = fy;
        return true;
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int dx[] = { 0,0,1,1,1,-1,-1,-1 };
    int dy[] = { 1,-1,1,0,-1,1,0,-1 };
    int n, m;
    cin >> n >> m;
    start(n*m);
    for (int i = 0; i < n; i++)for (int j = 0; j < m; j++)cin >> arr[i][j];
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 'W')
            {
                count++;
                for (int k = 0; k < 8; k++)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
                    if (arr[nx][ny] == '.')continue;
                    if (un(i*m+j,nx*m+ny))count--;

                }
            }
        }
    }
    cout << count;
    return 0;
}
