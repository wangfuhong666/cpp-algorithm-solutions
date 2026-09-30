#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>path;
int sum = 0;
vector<vector<int>>ans;
void dfs()
{
    if (path.size() >= 10)
    {
        if (sum == n)
        {
            ans.push_back(path);
        }
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        path.push_back(i);
        sum += i;
        dfs();
        path.pop_back();
        sum -= i;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    if (n < 10)cout << 0;
    else
    {
        dfs();
        cout << ans.size() << '\n';
        for (auto& rows : ans)
        {
            for (auto& num : rows)cout << num << ' ';
            cout << '\n';
        }
    }

    
    return 0;
}
