#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
string s;
int n;
long long ret = 0;
long long calc()
{
    long long x = 0, y = 0;
    for (auto e : s)
    {
        if (e == 'L')x++;
        else y +=x;
    }
    return y;
}
vector<int>idx;
void dfs(int pos)
{
    if (pos >= idx.size())
    {
        ret = max(ret, calc());
        return;
    }
    s[idx[pos]] = 'L';
    dfs(pos + 1);
    s[idx[pos]] = 'Q';
    dfs(pos + 1);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> s;
    for (int i = 0; i < n; i++)if (s[i] == '?')idx.push_back(i);
    dfs(0);
    cout << ret;
    return 0;
}
