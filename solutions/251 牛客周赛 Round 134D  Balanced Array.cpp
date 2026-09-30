#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int log2(int x)
{
    int res = 0;
    while ((1 << (res + 1)) <= x)res++;
    return res;
}
int get_max(int l, int r, vector<vector<int>>& stmax) {
    int k = log2(r - l + 1);
    return max(stmax[l][k], stmax[r - (1 << k) + 1][k]);
}
int get_min(int l, int r, vector<vector<int>>& stmin) {
    int k = log2(r - l + 1);
    return min(stmin[l][k], stmin[r - (1 << k) + 1][k]);
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
        int n;
        cin >> n;
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
            for (int i = 1; i + (1 << j) - 1 <= n; i++)
            {
                stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);

                stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
            }
        }
        int l = 1, r = 1;
        long long cnt = 0;
        while (r <= n)
        {
            while (get_max(l, r, stmax) - get_min(l, r, stmin) > 1) l++;
            cnt += r - l + 1;
            r++;
        }

        cout << cnt << '\n';
    }
    return 0;
}
