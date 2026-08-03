#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
int setnum[N];
void start(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        setnum[i] = 1;
    }
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
bool un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        fa[fx] = fy;
        setnum[fy] += setnum[fx];
        return true;
    }
    return false;
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    start(n);
    int cnt = n;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (un(x, y))cnt--;
    } 
    if (cnt == 1)cout << 0 << ' ' << 0; 
    else if (cnt == 2)cout << 1 << ' ' << 1;
    else
    {
        long long ret = 0;
        for (int i = 1; i <= n; i++)if (fa[i] == i && setnum[i] == 1)ret++;
        if ((n - ret) - 2 * (cnt - ret-1) < ret)cout << cnt - 1 << ' ' << 2;
        else cout << cnt - 1 << ' ' << 1;

    }
    return 0;
}

//A 完事
//B 不会
//C 完事
//D 完事
//E 暴力完事（正解在研究中）
//F 完事
//G 暴力完事（正解在研究中）
//H 暴力完事（正解不会）