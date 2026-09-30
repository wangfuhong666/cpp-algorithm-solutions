#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n;
vector<int>arr(N, 0);
bool ju(int l, int r)
{
    while (l <= r)
    {
        if (arr[l] != arr[r])return false;
        l++;
        r--;
    }
    return true;
}
vector<int>pe(int pos1,int pos2)
{
    int l = pos1, r = pos2;
    while (l >= 0 && r < 2 * n && arr[l] == arr[r])
    {
        l--;
        r++;
    }
    return { l + 1,r - 1 };
}
vector<int>te(int pos)
{
    int l = pos, r = pos;
    while (l >= 0 && r < 2 * n && arr[l] == arr[r])
    {
        l--;
        r++;
    }
    return { l + 1,r - 1 };
}
int mex(int l, int r)
{
    int mp[N] = { 0 };
    for (int i = l; i <= r; i++)mp[arr[i]]++;
    for (int i = 0; i < N; i++)if (!mp[i])return i;
    return -1;
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
        cin >> n;
        vector<int>pos;
        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
            if (arr[i] == 0)pos.push_back(i);
        }
        int res = 0;
        vector<int>tem = te(pos[0]);
        res = max(res, mex(tem[0], tem[1]));
        if (ju(pos[0], pos[1]))
        {
            tem = pe(pos[0], pos[1]);
            res = max(res, mex(tem[0], tem[1]));
        }
        tem = te(pos[1]);
        res = max(res, mex(tem[0], tem[1]));
        cout << res << '\n';

    }
    return 0;
}
