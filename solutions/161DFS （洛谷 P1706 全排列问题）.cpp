#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>path;
unordered_map<int, int>mp;
void dfs()
{

    if (path.size() == n)
    {
        for (auto nums : path)printf("%5d", nums);
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
    cin >> n;
    dfs();

    return 0;
}

