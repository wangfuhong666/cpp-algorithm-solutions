#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
int setsize[N];
void start(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
        setsize[i] = 1;
    }
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
void un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        if (setsize[fx] >= setsize[fy])
        {
            fa[fy] = fx;
            setsize[fx] += setsize[fy];
        }
        else
        {
            fa[fx] = fy;
            setsize[fy] += setsize[fx];
        }
    }
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
    
    return 0;
}
