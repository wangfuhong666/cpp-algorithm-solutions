#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, k;
vector<int>path;
void dfs()
{
    if (path.size() >= n)
    {
        for (auto num : path)cout << num << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        path.push_back(i);
        dfs();
        path.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> k;
    dfs();
    return 0;
}
