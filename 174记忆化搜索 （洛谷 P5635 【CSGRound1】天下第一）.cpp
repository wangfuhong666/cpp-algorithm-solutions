#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int p;
char memo[10010][10010];
char dfs(int x, int y)
{
    if (memo[x][y])return memo[x][y];
    memo[x][y] = '3';
    if (x == 0)return  memo[x][y] = '1';
    if (y == 0)return  memo[x][y] = '2';
    return  memo[x][y] = dfs((x + y) % p, ((x + y) % p + y) % p);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T >> p;
    while (T--)
    {
        int x, y;
        cin >> x >> y;
        int tem = dfs(x, y);
        if (tem == '1')cout << 1 << '\n';
        else if (tem == '2')cout << 2 << '\n';
        else cout << "error" << '\n';
    }
    return 0;
}
