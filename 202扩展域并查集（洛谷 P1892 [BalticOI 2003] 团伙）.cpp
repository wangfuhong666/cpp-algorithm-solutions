#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int fa[2 * N];
void start(int n)
{
    for (int i = 1; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}

//注意：x为朋友，y为敌人（状态）

void un(int x, int y)
{
    fa[find(y)] = find(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    start(2 * n + 4);
    while (m--)
    {
        int a, b;
        char c;
        cin >> c >> a >> b;
        if (c == 'F')un(a, b);
        else 
        {
            un(a, b + n);
            un(b, a + n);
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++)if (fa[i] == i)res++;
    cout << res;
    return 0;
}
