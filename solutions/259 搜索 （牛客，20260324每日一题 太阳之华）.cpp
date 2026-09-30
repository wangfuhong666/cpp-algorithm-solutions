#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10;
using PII = pair<int, int>;
int ret;
stack<PII>st;
bool path[N][N];
bool arr[N][N];
bool vis[N][N];

int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int bfs()
{
    memset(arr, false, sizeof arr);
    int res = 0;
    while (!st.empty())
    {

        auto p = st.top();
        st.pop();
        int a = p.first;
        int b = p.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (arr[nx][ny])continue;
            if (path[nx][ny])continue;
            res++;
            arr[nx][ny] = true;
        }
    }
    return res;
}
void bfs(int i, int j)
{
    queue<PII>q;
    q.emplace(i, j);
    st.emplace(i, j);
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        int a = p.first;
        int b = p.second;
        if (vis[a][b])continue;
        vis[a][b] = true;
        for (int k = 0; k < 4; k++)
        {
            int nx = a + dx[k];
            int ny = b + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
            if (vis[nx][ny])continue;
            if (!path[nx][ny])continue;
            st.emplace(nx, ny);
            q.emplace(nx, ny);
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {

        cin >> n >> m;
        ret = 0;
        memset(path, false, sizeof path);
        memset(arr, false, sizeof arr);
        memset(vis, false, sizeof vis);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                char ch;
                cin >> ch;
                //arr[i][j]=(ch=='#'?true:false);
                if (ch == '#')
                {
                    path[i][j] = true;
                    ret++;
                }
            }
        }
        if (ret == 0)
        {
            cout << "Blue" << '\n';
            continue;
        }
        bool judge = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (path[i][j] && !vis[i][j])
                {
                    bfs(i, j);
                    int x = bfs();
                    if (ret + x == n * m)
                    {
                        cout << "Red" << '\n';
                        judge = true;
                        break;
                    }
                }
            }
            if (judge)break;
        }
        if (judge)continue;
        else if (ret == n * m)cout << "Red" << '\n';
        else cout << "Draw" << '\n';
    }
    return 0;
}
