#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int>path;
//1 2 3 4 5 
// 5
void dfs(int pos, int begin)
{
    if (pos > m)
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i];
            if (i < path.size() - 1)cout << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = begin; i <= n; i++)
    {
        path.push_back(i);
        dfs(pos + 1, i + 1);
        path.pop_back();
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}
