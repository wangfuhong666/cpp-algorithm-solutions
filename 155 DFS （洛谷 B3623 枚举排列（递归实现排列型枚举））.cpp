#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int>path;
unordered_map<int, int>mp;
void dfs()
{

    if (path.size() == m)
    {
        for (auto nums : path)cout << nums << ' ';
        cout << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mp[i] > 0)
        {
           continue;
        }
        path.push_back(i);
        mp[i]++;
        dfs();
        path.pop_back();
        mp[i]--;

    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    dfs();
    
    return 0;
}
