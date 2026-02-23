#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int log2(int x)
{
    int res = 0;
    while ((1 << (res + 1)) <= x)res++;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, q;
    cin >> n >> q;
    int power = log2(n);
    vector<vector<int>>stmax(n + 1, vector<int>(power + 1, 0)), stmin(n + 1, vector<int>(power + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        stmax[i][0] = x;
        stmin[i][0] = x;
    }
    for (int j = 1; j <= power; j++)
    {
        for (int i = 1;  i + (1 << j) - 1 <= n; i++)
        {
            stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);

            stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int len = b - a + 1;
        int tem = log2(len);
        cout << max(stmax[a][tem], stmax[b - (1 << tem)+1][tem]) - min(stmin[a][tem], stmin[b - (1 << tem)+1][tem]) << '\n';
    }
    return 0;
}
