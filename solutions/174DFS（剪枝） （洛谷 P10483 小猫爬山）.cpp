#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, w;
const int N = 25;
int car[N];
int cat[N];
//递归到某一层的缆车个数
int res = 0;
//最小的缆车的个数
int cnt;
bool cmp(int a, int b)
{
    return a > b;
}
void dfs(int pos)
{
    if (res >= cnt)return;
    if (pos > n)
    {
        cnt = res;
        return;
    }
    for (int i = 1; i <= res; i++)
    {
        if (car[i] + cat[pos] > w)continue;
        car[i] += cat[pos];
        dfs(pos + 1);
        car[i] -= cat[pos];
    }
    res++;
    car[res] = cat[pos];
    dfs(pos + 1);
    car[res] = 0;
    res--;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)cin >> cat[i];
    sort(cat + 1, cat + 1 + n, cmp);
    cnt = n + 2;
    dfs(1);
    cout << cnt;
    return 0;
}
