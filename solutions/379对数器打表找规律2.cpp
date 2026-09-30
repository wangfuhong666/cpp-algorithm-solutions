#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
//A赢/输
string dfs(int r, string e)
{
    string m = (e == "A" ? "B" : "A");
    if (r == 0)return m;
    int pos = 1;
    while (pos <= r)
    {
        if (dfs(r - pos, m)==e)return e;
        pos *= 4;
    }
    return m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i <= n; i++)cout << i << " : " << dfs(i,"A") << '\n';
    return 0;
}
