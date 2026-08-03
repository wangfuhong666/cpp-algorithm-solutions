#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int fa[3 * N];
void start(int n)
{
    for (int i = 1; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
//x为两个域中靠前的那个
void un(int x, int y)
{
    fa[find(y)] = find(x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    start(3 * n + 4);
    int res = 0;
    while (k--)
    {
        int op, x, y;
        cin >> op >> x >> y;
        if (x > n || y > n)
        {
            res++;
            continue;
        }
        if (op == 1)
        {
            if(find(x)==find(y+n)||find(x)==find(y+n+n))res++;
            else
            {
                un(x, y);
                un(x + n, y + n);
                un(x + n + n, y + n + n);
            }
        }
        else
        {
            if (find(x) == find(y) || find(x) == find(y + n))res++;
            else
            {
                un(y, x + n);
                un(x, y + n + n);
                un(y + n, x + n + n);
            }
        }
    }
    cout << res;
    return 0;
}
