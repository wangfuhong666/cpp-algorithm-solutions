#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int dfs(int r)
{
    if (r < 0)return INT_MAX;
    if (r == 0)return 0;
    int p1 = dfs(r - 6);
    if (p1 != INT_MAX)p1++;
    int p2 = dfs(r - 8);
    if (p2 != INT_MAX)p2++;
    return min(p1, p2);
}
int f(int x)
{
    int res = dfs(x);
    if (res == INT_MAX)return -1;
    return res;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)cout << i << " : " << f(i) << '\n';
    return 0;
}
