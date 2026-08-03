#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//floor版log2 (取整)函数(防溢出版)
int log2(int x)
{
    int res = 0;
    while ((1 << (res + 1)) <= x)res++;
    return res;
}
bool cmp(vector<int>& a, vector<int>& b)
{
    return a[1] < b[1];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>info;
    for (int i = 1; i <=n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x > y)y += m;
        info.push_back({ i,x,y });
    }
    sort(info.begin(), info.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        int id = info[i][0];
        int x = info[i][1] + m;
        int y = info[i][2] + m;
        info.push_back({ id,x,y });
    }
    int power = log2(n);
    vector<vector<int>>st(2*n + 1, vector<int>(power + 1, 0));
    int e = 2 * n;
    int arrive = 0;
    for (int i = 0; i <e; i++)
    {
        while (arrive + 1 < e && info[arrive + 1][1] <= info[i][2])arrive++;
        st[i][0] = arrive;
    }
    for (int i = 1; i <= power; i++)
    {
        for (int j = 0; j < e; j++)
        {
            st[j][i] = st[st[j][i - 1]][i - 1];
        }
    }
    vector<int>ans(n + 1);
    for (int i = 0; i < n; i++)
    {
        int aim = info[i][1] + m;
        int cur = i;
        int res = 0;
        for (int p = power; p >= 0; p--)
        {
            int next = st[cur][p];
            if (info[next][2] < aim)
            {
                res += (1 << p);
                cur = next;
            }
            ans[info[i][0]] = res + 2;
        }
    }
    for (int i = 1; i <= n; i++)cout << ans[i] << ' ';
    return 0;
}
